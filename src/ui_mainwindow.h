/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *widget;
    QWidget *widget_4;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QLineEdit *lineEdit_8;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QComboBox *comboBox;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1280, 800);
        MainWindow->setMinimumSize(QSize(1280, 800));
        MainWindow->setMaximumSize(QSize(1280, 800));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 20, 900, 700));
        widget->setMinimumSize(QSize(900, 700));
        widget->setMaximumSize(QSize(900, 700));
        widget_4 = new QWidget(centralWidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(970, 150, 251, 171));
        widget1 = new QWidget(widget_4);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 10, 231, 151));
        verticalLayout_6 = new QVBoxLayout(widget1);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_10 = new QLabel(widget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_11->addWidget(label_10);

        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_11->addWidget(pushButton_2);


        verticalLayout_6->addLayout(horizontalLayout_11);

        textEdit = new QTextEdit(widget1);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_6->addWidget(textEdit);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(970, 340, 257, 247));
        verticalLayout_5 = new QVBoxLayout(widget2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_10 = new QHBoxLayout(widget_3);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_9 = new QLabel(widget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setTextFormat(Qt::RichText);

        horizontalLayout_2->addWidget(label_9);

        lineEdit_8 = new QLineEdit(widget_3);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setEnabled(false);

        horizontalLayout_2->addWidget(lineEdit_8);


        horizontalLayout_10->addLayout(horizontalLayout_2);


        verticalLayout_5->addWidget(widget_3);

        widget_2 = new QWidget(widget2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        comboBox = new QComboBox(widget_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_6->addWidget(comboBox);


        verticalLayout_4->addLayout(horizontalLayout_6);

        stackedWidget = new QStackedWidget(widget_2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_2 = new QLineEdit(page);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        lineEdit_3 = new QLineEdit(page);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_5->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit_4 = new QLineEdit(page);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        lineEdit_5 = new QLineEdit(page_2);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_7->addWidget(lineEdit_5);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);

        lineEdit_6 = new QLineEdit(page_2);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_8->addWidget(lineEdit_6);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        lineEdit_7 = new QLineEdit(page_2);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        horizontalLayout_9->addWidget(lineEdit_7);


        verticalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout_3->addLayout(verticalLayout_2);

        stackedWidget->addWidget(page_2);

        verticalLayout_4->addWidget(stackedWidget);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_4->addWidget(pushButton);


        verticalLayout_5->addWidget(widget_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266(utf-8)", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\344\272\244\347\202\271\344\270\252\346\225\260\344\270\200\345\205\261\344\270\272\357\274\232", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\347\261\273\345\236\213\357\274\232", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "L", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "R", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "S", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "C", nullptr));

        label->setText(QApplication::translate("MainWindow", "x1", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "y1", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "x2", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "y2", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "x", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "y", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "r", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
