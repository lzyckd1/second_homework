#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qcustomplot.h>
#include<QVector>
#include<geometry.h>
#include<map>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	map <node, int>* nodes;
	vector<line>* lines;
	vector<rays>* rayss;
	vector<lise>* lises;
	vector<Cycle>* cycles;

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
	void originGeo();


public slots:
    void choose();
    void selectionChanged();
    void mousePress();
    void mouseWheel();

    void titleDoubleClick(QMouseEvent *event);
    void axisLabelDoubleClick(QCPAxis* axis, QCPAxis::SelectablePart part);
    void legendDoubleClick(QCPLegend* legend, QCPAbstractLegendItem* item);

    void graphClicked(QCPAbstractPlottable *plottable, int dataIndex);

    void contextMenuRequest(QPoint pos);

    void addRandomGraph();
    void removeSelectedGraph();
    void removeAllGraphs();

    void switchGeo();
    void addGeo();

	void fileInput();

private:
    Ui::MainWindow *ui;

    QVector<double> *indexX;
    QVector<double> *valueY;
    QVector<double> *valueY1;
    QCustomPlot* customPlot;

    

};

#endif // MAINWINDOW_H
