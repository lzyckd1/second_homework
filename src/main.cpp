#include "mainwindow.h"
#include <QApplication>
#include<QDebug>
#include<geometry.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include "core.h"
#include "line.h"
#include "lise.h"
#include "Cycle.h"
#include "rays.h"
#include "node.h"
using namespace std;

int main(int argc, char** argv)
{
	QApplication qa(argc, argv);


	ifstream infile(argv[2]);  // argv[2]
	ofstream outfile(argv[4]);   // argv[4]
	if (!infile) {
		try {
			throw "input file error!\n";
		}
		catch (const char* msg) {
			cerr << msg << endl;
			exit(1);
		}
	}

	//ifstream infile("D:\\QT_workspace\\software_second\\second\\input.txt");  // argv[2]
	//ofstream outfile("D:\\QT_workspace\\software_second\\second\\output.txt");   // argv[4]

	read_file(argv[2]);//argv[2]


	outfile << countn;
	cout << countn;
	
	MainWindow w;

	w.nodes = &node_set;
	w.lines = &lseq;
	w.lises = &sseq;
	w.cycles = &cseq;
	w.rayss = &rseq;

	w.originGeo();
	w.show();

	return qa.exec();
}



