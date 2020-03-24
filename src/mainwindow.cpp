#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qcustomplot.h>
#include<QFile>
#include<QDebug>
#include<QTextStream>
#include<vector>
#include<QValidator>
#include<QRegExp>
#include <math.h>
#include<qstring.h>
#include<mainFunction.h>
#include<iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    customPlot = ui->widget;
    srand(QDateTime::currentDateTime().toTime_t());
    //设置背景色
    customPlot->setBackground(QColor(50, 50, 50));
    //QCPGraph *pGraph0 = customPlot->addGraph();

    //pGraph0->setPen(QPen(QColor(32, 178, 170)));

    // 设置x/y轴文本色、轴线色、字体等
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->setLabelColor(QColor(0, 160, 230));
    customPlot->xAxis->setBasePen(QPen(QColor(32, 178, 170)));
    customPlot->xAxis->setTickPen(QPen(QColor(128, 0, 255)));
    customPlot->xAxis->setSubTickPen(QColor(255, 165, 0));
    QFont xFont = customPlot->xAxis->labelFont();
    xFont.setPixelSize(20);
    customPlot->xAxis->setLabelFont(xFont);

    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(QColor(0, 160, 230));
    customPlot->yAxis->setBasePen(QPen(QColor(32, 178, 170)));
    customPlot->yAxis->setTickPen(QPen(QColor(128, 0, 255)));
    customPlot->yAxis->setSubTickPen(QColor(255, 165, 0));
    QFont yFont = customPlot->yAxis->labelFont();
    yFont.setPixelSize(20);
    customPlot->yAxis->setLabelFont(yFont);

    indexX = new QVector<double>(10000);

//    QFile f("D:/test.txt");
//    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        qDebug() << "Open failed." << endl;
//    }

//    QTextStream txtInput(&f);
//    QString lineStr;
//    while(!txtInput.atEnd())
//    {
//        lineStr = txtInput.readLine();
//        qDebug() << lineStr << endl;
//    }

//    f.close();


    customPlot->xAxis->setLabel("X轴");
    customPlot->yAxis->setLabel("Y轴");


    for (int i=0; i<10000; i++){
        (*indexX)[i] = (i*1.0/10000-0.5)*1000+0.1;

    }

    customPlot->xAxis->setRange(-1000,1000);
    customPlot->yAxis->setRange(-1000,1000);


    //设置图例
    customPlot->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setFamily("微软雅黑");
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->legend->setSelectedFont(legendFont);
    customPlot->legend->setSelectableParts(QCPLegend::spItems); // 图例部分的字可选


    //可拖动
    customPlot->setInteraction(QCP::iRangeDrag, true);

    //可缩放
    customPlot->setInteraction(QCP::iRangeZoom, true);

    //曲线可选
    customPlot->setInteraction(QCP::iSelectPlottables, true);

    //曲线 ctrl 多选
    customPlot->setInteraction(QCP::iMultiSelect, true);

    //坐标轴可选
    customPlot->setInteraction(QCP::iSelectAxes, true);
    //图例可选
    customPlot->setInteraction(QCP::iSelectLegend, true);

    //模式：框选放大
    //customPlot->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);
    //customPlot->selectionRect()->setPen(QPen(Qt::black,1,Qt::DashLine));//虚线

    /*设置画笔
     *
    QPen pen;
    pen.setColor(QColor(255,0,0));
    pen.setWidth(10);
    customPlot->graph(0)->setPen(pen);
    customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);　　//取消点与点之间的连线
    customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 8));　　//设置散点为圆点
    */
//QCPAbstractPlottable :: selectionChanged(bool selected)
    //connect();QCustomPlot::mouseDoubleClick
    connect(customPlot,SIGNAL(selectionChangedByUser()),this,SLOT(choose()));
    //customPlot->removeGraph(1);
    //customPlot->replot();


    // 选中轴时上下轴一起被选中
    connect(customPlot, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));
    // 选中轴时，鼠标拖动智能移动一边的轴，滚轮也是一样
    connect(customPlot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));
    connect(customPlot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));


    // 双击修改轴名
    connect(customPlot, SIGNAL(axisDoubleClick(QCPAxis*,QCPAxis::SelectablePart,QMouseEvent*)), this, SLOT(axisLabelDoubleClick(QCPAxis*,QCPAxis::SelectablePart)));

    // 双击图例改图名
    //connect(customPlot, SIGNAL(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*,QMouseEvent*)), this, SLOT(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*)));

    //双击修改title
    customPlot->plotLayout()->insertRow(0);
    QCPTextElement *title = new QCPTextElement(customPlot, "软工结对作业", QFont("sans", 17, QFont::Bold));
    customPlot->plotLayout()->addElement(0, 0, title);
    connect(title, SIGNAL(doubleClicked(QMouseEvent*)), this, SLOT(titleDoubleClick(QMouseEvent*)));

    // 状态栏处显示那条曲线被选中了
    connect(customPlot, SIGNAL(plottableClick(QCPAbstractPlottable*,int,QMouseEvent*)), this, SLOT(graphClicked(QCPAbstractPlottable*,int)));



    // 图例的菜单和对图形管理的菜单
    customPlot->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(customPlot, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequest(QPoint)));


    //QRegExp regx("[1-9][0-9]{1,4}");

    QValidator *validator = new QIntValidator(-99999,99999,this);
    QValidator *radius = new QIntValidator(0,99999,this);

    ui->lineEdit->setValidator(validator);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_3->setValidator(validator);
    ui->lineEdit_4->setValidator(validator);
    ui->lineEdit_5->setValidator(validator);
    ui->lineEdit_6->setValidator(validator);
    ui->lineEdit_7->setValidator(radius);


    //添加层面的connect

    //多选框切换时，直线输入切换成圆输入
    connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(switchGeo()));

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(addGeo()));

	//文件输入
	connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(fileInput()));

	//申请一次空间永久使用
	valueY = new QVector<double>(10000);

}

void MainWindow::fileInput() {

	QString path = QFileDialog::getOpenFileName(this, "打开文件", "D:\\QT_workspace\\software_second\\second");

	QFile file(path);
	if (path.contains(QRegExp("[\\x4e00-\\x9fa5]+"))) {
		QMessageBox::critical(this, "你文件选的路径有点问题啊", "文件读入的路径名内不能含有中文哦");
		return;
	}
	bool ok = file.open(QIODevice::ReadOnly);
	//以只读方式打开文件
	
	//文件与文本流相关联
	if (ok)
	{

		QByteArray array = file.readAll();

		ui->textEdit->setText(array);

		read_file(path.toStdString());
		customPlot->clearGraphs();
		originGeo();
	}
	else
	{
		QMessageBox::information(this, "你打开文件有点问题啊","文件打开失败");
		return;
	}

	
	//最后执行黎正宇写的函数(其中包括用fstream读文件，然后重新计算)
	//然后重新画图，其实就是执行originGeo
}

void MainWindow::switchGeo(){
    if(ui->comboBox->currentIndex() == 3){
        ui->stackedWidget->setCurrentIndex(1);
    }
    else{
        ui->stackedWidget->setCurrentIndex(0);
    }
}


void MainWindow::originGeo() {
	
	//画交点
	QVector<double> nodex;
	QVector<double> nodey;
	for (map <node, int>::iterator iter = (*nodes).begin(); iter != (*nodes).end(); iter++) {
		node temp = iter->first;
		double x = temp.getX();
		double y = temp.getY();
		nodex.push_back(x);
		nodey.push_back(y);
	}
	QCPGraph* graph = customPlot->addGraph();
	graph->setData(nodex, nodey);
	graph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ScatterShape::ssDisc, 5));
	QPen graphPen;
	graphPen.setColor(QColor(255,255,255));
	graphPen.setWidthF(rand() / (double)RAND_MAX * 2 + 1);
	graph->setPen(graphPen);
	graph->setName("交点集合");

	int cnt = (*nodes).size();
	ui->lineEdit_8->setText(QString::number(cnt));

	if (cnt >= 20) {
		customPlot->legend->setVisible(true);
	}

	//----------------------------------------
	//画直线
	int linesize = (*lines).size();
	for (int i = 0; i < linesize; i++) {
		line l = (*lines)[i];
		int x1 = l.getNode1().getX();
		int y1 = l.getNode1().getY();
		int x2 = l.getNode2().getX();
		int y2 = l.getNode2().getY();
		if (l.getExitK()) {
			double k = l.getK();
			double b = (-1) * l.getC() / l.getB();
			for (int i = 0; i < 10000; i++) {
				(*valueY)[i] = k * (*indexX)[i] + b;
			}
			QCPGraph* graph = customPlot->addGraph();
			graph->setData(*indexX, *valueY);
		}
		else {
			//不能画
			continue;
		}
		QPen graphPen;
		graphPen.setColor(QColor(rand() % 245 + 10, rand() % 245 + 10, rand() % 245 + 10));
		graphPen.setWidthF(rand() / (double)RAND_MAX * 2 + 1);
		customPlot->graph()->setPen(graphPen);
		//customPlot->graph()->setName("line(编号:" + QString::number(customPlot->graphCount()) + ")");
		const QString name = "L " + QString::number(x1) + " " + QString::number(y1) + " " + QString::number(x2) + " " + QString::number(y2);
		customPlot->graph()->setName(name);
	}

	//----------------------------------------
	//画射线
	int raysize = (*rayss).size();
	for (int i = 0; i < raysize; i++) {
		rays ray = (*rayss)[i];
		int x1 = ray.getStart().getX();
		int y1 = ray.getStart().getY();
		int x2 = ray.getN().getX();
		int y2 = ray.getN().getY();
		if (ray.getExitK()) {
			double k = ray.getK();
			double b = (-1) * ray.getC() / ray.getB();
			QVector<double> fx;
			QVector<double> fy;
			for (int i = 0; i < 10000; i++) {
				(*valueY)[i] = k * (*indexX)[i] + b;
				node tempnode((*indexX)[i], (*valueY)[i]);
				if (ray.judge(tempnode)) {
					fx.push_back((*indexX)[i]);
					fy.push_back((*valueY)[i]);
				}
			}
			QCPGraph* graph = customPlot->addGraph();
			graph->setData(fx, fy);
		}
		else {
			//斜率不存在时不能花
			continue;
		}
		QPen graphPen;
		graphPen.setColor(QColor(rand() % 245 + 10, rand() % 245 + 10, rand() % 245 + 10));
		graphPen.setWidthF(rand() / (double)RAND_MAX * 2 + 1);
		customPlot->graph()->setPen(graphPen);
		const QString name = "R " + QString::number(x1) + " " + QString::number(y1) + " " + QString::number(x2) + " " + QString::number(y2);
		//customPlot->graph()->setName("ray(编号:" + QString::number(customPlot->graphCount()) + ")");
		customPlot->graph()->setName(name);
	}

	//----------------------------------------
	//画线段
	int lisesize = (*lises).size();
	for (int i = 0; i < lisesize; i++) {
		lise ls = (*lises)[i];
		int x1 = ls.getNode1().getX();
		int y1 = ls.getNode1().getY();
		int x2 = ls.getNode2().getX();
		int y2 = ls.getNode2().getY();
		if (ls.getExitK()) {
			double k = ls.getK();
			double b = (-1) * ls.getC() / ls.getB();
			QVector<double> fx;
			QVector<double> fy;
			for (int i = 0; i < 10000; i++) {
				(*valueY)[i] = k * (*indexX)[i] + b;
				node tempnode((*indexX)[i], (*valueY)[i]);
				if (ls.judge(tempnode)) {
					fx.push_back((*indexX)[i]);
					fy.push_back((*valueY)[i]);
				}
			}
			QCPGraph* graph = customPlot->addGraph();
			graph->setData(fx, fy);
		}
		else {
			//斜率不存在时不能花
			continue;
		}
		QPen graphPen;
		graphPen.setColor(QColor(rand() % 245 + 10, rand() % 245 + 10, rand() % 245 + 10));
		graphPen.setWidthF(rand() / (double)RAND_MAX * 2 + 1);
		customPlot->graph()->setPen(graphPen);
		const QString name = "S " + QString::number(x1) + " " + QString::number(y1) + " " + QString::number(x2) + " " + QString::number(y2);
		customPlot->graph()->setName(name);
		
	}

	//----------------------------------------
	//画圆
	int circlesize = (*cycles).size();
	valueY1 = new QVector<double>(10000);
	for (int i = 0; i < circlesize; i++) {
		Cycle c = (*cycles)[i];
		int x = c.getC().getX();
		int y = c.getC().getY();
		int r = c.getR();
		const QString name = "C " + QString::number(x) + " " + QString::number(y) + " " + QString::number(r);
		r = r * r;
		double temp = 0;
		double temp1 = 0;
		for (int i = 0; i < 10000; i++) {
			temp = ((*indexX)[i] - x) * ((*indexX)[i] - x);
			temp1 = sqrt(r - temp);
			(*valueY)[i] = y + temp1;
			(*valueY1)[i] = y - temp1;
		}
		//int cnt = customPlot->graphCount();
		//const QString firstname = "arcTop(编号:" + QString::number(cnt) + ")";
		//const QString lastname = "arcBottom(编号:" + QString::number(cnt) + ")";

		customPlot->addGraph();
		customPlot->graph()->setData(*indexX, *valueY);
		customPlot->graph()->setName(name);
		customPlot->addGraph();
		customPlot->graph()->setData(*indexX, *valueY1);
		customPlot->graph()->setName(name);
	}
	
	customPlot->replot();
	return;
}



void MainWindow::addGeo(){
    int index = ui->comboBox->currentIndex();
    int x1 = 0,y1 = 0,x2 = 0,y2 = 0;
    int x = 0,y = 0,r = 0;
    switch(index){
        case 0:
        case 1:
        case 2:
            x1 = (int)(ui->lineEdit->text().toInt());
            y1 = (int)(ui->lineEdit_2->text().toInt());
            x2 = (int)(ui->lineEdit_3->text().toInt());
            y2 = (int)(ui->lineEdit_4->text().toInt());
            break;
        case 3:
            x = (int)(ui->lineEdit_5->text().toInt());
            y = (int)(ui->lineEdit_6->text().toInt());
            r = (int)(ui->lineEdit_7->text().toInt());
            break;
        default:
            return ;
    }

    //此处调用图形的各种构造函数

    valueY = new QVector<double>(10000);

	bool ret = false;

    if(index == 0){
        //L 直线
		string strl = "L " + to_string(x1) + " " + to_string(y1) + " " + to_string(x2) + " " + to_string(y2);
		node n1(x1, y1);
		node n2(x2, y2);
		line l(n1,n2);
		if (!l.getExitK()) {
			QMessageBox::critical(this, "你输入有点问题啊", "【输入为空】或者【直线没有斜率】本软件不支持哦，请试试文本输入");
			return;
		}
		if (!Add(strl)) {
			QMessageBox::critical(this, "你输入有点问题啊", "你输入的数据和现有图形重合了，不合法哟");
			return;
		}
    }
    else if(index == 1){
        //R
		string strr = "R " + to_string(x1) + " " + to_string(y1) + " " + to_string(x2) + " " + to_string(y2);
		node n1(x1, y1);
		node n2(x2, y2);
		rays ra(n1, n2);
		if (!ra.getExitK()) {
			//斜率不存在时不加入，因为没发画出来
			QMessageBox::critical(this, "你输入有点问题啊", "【输入为空】或者【直线没有斜率】本软件不支持哦，请试试文本输入");
			return;
		}
		if (!Add(strr)) {
			QMessageBox::critical(this, "你输入有点问题啊", "你输入的数据和现有图形重合了，不合法哟");
			return;
		}
		
    }
    else if(index == 2){
        //S线段
		string strs = "S " + to_string(x1) + " " + to_string(y1) + " " + to_string(x2) + " " + to_string(y2);
		node n1(x1, y1);
		node n2(x2, y2);
		lise s(n1, n2);
		if (!s.getExitK()) {
			//斜率不存在时不能花
			QMessageBox::critical(this, "你输入有点问题啊", "【输入为空】或者【直线没有斜率】本软件不支持哦，请试试文本输入");
			return;
		}
		if (!Add(strs)) {
			QMessageBox::critical(this, "你输入有点问题啊", "你输入的数据和现有图形重合了，不合法哟");
			return;
		}
    }
    else if(index == 3){
        //C
		string strc = "C " + to_string(x) + " " + to_string(y) + " " + to_string(r);
		if (!Add(strc)) {
			QMessageBox::critical(this, "你输入有点问题啊", "你输入的数据和现有图形重合了，不合法哟");
			return;
		}
    }

	customPlot->clearGraphs();
	originGeo();
}


void MainWindow::selectionChanged(){
    // 上下轴同步选择
    if (customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis) || customPlot->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
      customPlot->xAxis2->selectedParts().testFlag(QCPAxis::spAxis) || customPlot->xAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
    {
        customPlot->xAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
        customPlot->xAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    }

    // 左右轴同步选择
    if (customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis) || customPlot->yAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
      customPlot->yAxis2->selectedParts().testFlag(QCPAxis::spAxis) || customPlot->yAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
    {
        customPlot->yAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
        customPlot->yAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    }

    // 同步图形选择与图例选择
    for (int i=0; i<customPlot->graphCount(); ++i){
        QCPGraph *graph = customPlot->graph(i);
        QCPPlottableLegendItem *item = customPlot->legend->itemWithPlottable(graph);
        if (item->selected() || graph->selected()){
          item->setSelected(true);
          graph->setSelection(QCPDataSelection(graph->data()->dataRange()));
        }
    }
}

void MainWindow::mousePress(){
    // 当轴被选中时，只能缩放该轴
    // 轴未被选中时，xy均可缩放
    if (customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
        customPlot->axisRect()->setRangeDrag(customPlot->xAxis->orientation());
    else if (customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
        customPlot->axisRect()->setRangeDrag(customPlot->yAxis->orientation());
    else
        customPlot->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
}

void MainWindow::mouseWheel(){
    // 当轴被选中时，只能缩放该轴
    // 轴未被选中时，xy均可缩放
    if (customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
        customPlot->axisRect()->setRangeZoom(customPlot->xAxis->orientation());
    else if (customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
        customPlot->axisRect()->setRangeZoom(customPlot->yAxis->orientation());
    else
        customPlot->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
}



void MainWindow::titleDoubleClick(QMouseEvent* event){
    Q_UNUSED(event)
    //sender() 信号来源的对象
    if (QCPTextElement *title = qobject_cast<QCPTextElement*>(sender())){
        //不为空就执行
        bool ok;
        QString newTitle = QInputDialog::getText(this, "软工结对作业", "起个新名吧:", QLineEdit::Normal, title->text(), &ok);
        if (ok){
            title->setText(newTitle);
            customPlot->replot();
        }
    }
}

void MainWindow::axisLabelDoubleClick(QCPAxis *axis, QCPAxis::SelectablePart part){
    // 双击执行【轴改名】
    if (part == QCPAxis::spAxisLabel) {
        // 准确的点到了轴上
        bool ok;
        QString newLabel = QInputDialog::getText(this, "软工结对作业", "给轴起个新名:", QLineEdit::Normal, axis->label(), &ok);
        if (ok){
            axis->setLabel(newLabel);
            customPlot->replot();
        }
    }
}

void MainWindow::legendDoubleClick(QCPLegend *legend, QCPAbstractLegendItem *item){
    // 双击执行【图例改名】
    Q_UNUSED(legend)
    if (item){
        // 只有图例被点击的时候才执行，如果点到边缘上，item=0
        QCPPlottableLegendItem *plItem = qobject_cast<QCPPlottableLegendItem*>(item);
        bool ok;
        QString newName = QInputDialog::getText(this, "软工结对作业", "给图起个新名:", QLineEdit::Normal, plItem->plottable()->name(), &ok);
        if (ok){
            plItem->plottable()->setName(newName);
            customPlot->replot();
        }
    }
}

void MainWindow::graphClicked(QCPAbstractPlottable *plottable, int dataIndex){
    //只有QCPGraphs在图中，所以可以立刻连接interface1D()
    // since we know we only have QCPGraphs in the plot, we can immediately access interface1D()
    // usually it's better to first check whether interface1D() returns non-zero, and only then use it.
    double dataValuey = plottable->interface1D()->dataMainValue(dataIndex);
    double dataValuex = plottable->interface1D()->dataMainKey(dataIndex);
    QString message = QString("你点击的图形是 '%1' ，这个点的索引是 #%2 ，它的坐标是 (%3,%4).").arg(plottable->name()).arg(dataIndex).arg(dataValuex).arg(dataValuey);
    ui->statusBar->showMessage(message, 2500);
}

void MainWindow::contextMenuRequest(QPoint pos){
    QMenu *menu = new QMenu(this);
    menu->setAttribute(Qt::WA_DeleteOnClose);//关闭时释放资源

    if (customPlot->legend->selectTest(pos, false) >= 0){
        //选中的是图例
        menu->addAction("图例移至左上", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignLeft));
        menu->addAction("图例移至左下", this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignLeft));
        menu->addAction("图例移至中顶部", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignHCenter));
        menu->addAction("图例移至右上", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignRight));
        menu->addAction("图例移至右下", this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignRight));
    }
    else{
        //选中的不是图例
        //menu->addAction("添加随机图形", this, SLOT(addRandomGraph()));
        if (customPlot->selectedGraphs().size() > 0)
            menu->addAction("删除所选图形", this, SLOT(removeSelectedGraph()));
        if (customPlot->graphCount() > 0)
            menu->addAction("删除全部图形", this, SLOT(removeAllGraphs()));
    }

    menu->popup(customPlot->mapToGlobal(pos));
}



void MainWindow::addRandomGraph(){
    //格式参见博客 https://blog.csdn.net/yxy244/article/details/100033549
    int n = 50; // number of points in graph
    double xScale = (rand()/(double)RAND_MAX + 0.5)*2;
    double yScale = (rand()/(double)RAND_MAX + 0.5)*2;
    double xOffset = (rand()/(double)RAND_MAX - 0.5)*4;
    double yOffset = (rand()/(double)RAND_MAX - 0.5)*10;
    double r1 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r2 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r3 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r4 = (rand()/(double)RAND_MAX - 0.5)*2;
    QVector<double> x(n), y(n);
    for (int i=0; i<n; i++){
        x[i] = (i/(double)n-0.5)*10.0*xScale + xOffset;
        y[i] = (qSin(x[i]*r1*5)*qSin(qCos(x[i]*r2)*r4*3)+r3*qCos(qSin(x[i])*r4*2))*yScale + yOffset;
    }

    //customPlot->graph() 创建的最后一个图，如果没有图形返回0
    customPlot->addGraph();
    customPlot->graph()->setName(QString("New graph %1").arg(customPlot->graphCount()-1));
    customPlot->graph()->setData(x, y);
    //customPlot->graph()->setLineStyle((QCPGraph::LineStyle)(rand()%5+1));
    customPlot->graph()->setLineStyle(QCPGraph::LineStyle::lsLine);
    /*
    lsNone无连接线
    */

    /*
    *
    * QCPScatterStyle(QCPScatterStyle::ScatterShape::ssPlus,5) 数据点加号+
    */
    //if (rand()%100 > 50)
    //customPlot->graph()->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)(rand()%14+1)));
    customPlot->graph()->setScatterStyle(QCPScatterStyle ::ssNone);
    QPen graphPen;
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    graphPen.setWidthF(rand()/(double)RAND_MAX*2+1);
    customPlot->graph()->setPen(graphPen);

    //删除图例的某一个customPlot->legend->removeItem(0);

    customPlot->replot();
}

void MainWindow::removeSelectedGraph(){
	if (customPlot->selectedGraphs().size() > 0)
    {
		QString name = customPlot->selectedGraphs().first()->name();
		qDebug() <<"被删除图像的名字是 " <<name;
		
		Delete(name.toStdString());
        //customPlot->removeGraph(customPlot->selectedGraphs().first());
		customPlot->clearGraphs(); 
		originGeo();

        customPlot->replot();
    }
}

void MainWindow::removeAllGraphs(){
    customPlot->clearGraphs();
    customPlot->replot();
}


void MainWindow::choose(){

    if(customPlot->selectedGraphs().size()>0){
        qDebug() << "选中了 " << customPlot->selectedGraphs().first()->name();
    }
    else{
        qDebug() << "啥也没选中";
    }

}

MainWindow::~MainWindow(){
    delete ui;
}

