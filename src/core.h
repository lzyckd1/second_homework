#ifdef CREATEDELL_API_DU
#else                                                                            
#define CREATEDELL_API_DU _declspec(dllimport) 
#endif   


#include "node.h"
#include "Cycle.h"
#include "line.h"
#include "lise.h"
#include "rays.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <time.h>
#include <math.h>
using namespace std;
static const int maxn = 1000;
static map <node, int> node_set;
static vector <line> lseq;
static vector <lise> sseq;
static vector <Cycle> cseq;
static vector <rays> rseq;
static int countn = 0;
void CREATEDELL_API_DU error_output(string errors);
int CREATEDELL_API_DU string2int(string l);
double CREATEDELL_API_DU string2double(string l);
char CREATEDELL_API_DU string2char(string l);
double CREATEDELL_API_DU distance_nn(node a, node b);
double CREATEDELL_API_DU distance_nl(node a, line b);
double CREATEDELL_API_DU distance_nl(node a, lise b);
double CREATEDELL_API_DU distance_nl(node a, rays b);
void CREATEDELL_API_DU node_set_insert(node n);
void CREATEDELL_API_DU node_set_delete(node n);
node CREATEDELL_API_DU findIntersectionll(line a, line b);
node CREATEDELL_API_DU findIntersectionlr(line a, rays b);
node CREATEDELL_API_DU findIntersectionrr(rays a, rays b);
node CREATEDELL_API_DU findIntersectionls(line a, lise b);
node CREATEDELL_API_DU findIntersectionrs(rays a, lise b);
node CREATEDELL_API_DU findIntersectionss(lise a, lise b);
void CREATEDELL_API_DU add_node_ll(line a, line b);
void CREATEDELL_API_DU add_node_lr(line a, rays b);
void CREATEDELL_API_DU add_node_rr(rays a, rays b);
void CREATEDELL_API_DU add_node_ls(line a, lise b);
void CREATEDELL_API_DU add_node_ss(lise a, lise b);
void CREATEDELL_API_DU add_node_rs(rays a, lise b);
void CREATEDELL_API_DU add_node_cc(Cycle a, Cycle b);
void CREATEDELL_API_DU add_node_cl(Cycle a, line b);
void CREATEDELL_API_DU add_node_cs(Cycle a, lise b);
void CREATEDELL_API_DU add_node_cr(Cycle a, rays b);
void CREATEDELL_API_DU delete_node_ll(line a, line b);
void CREATEDELL_API_DU delete_node_lr(line a, rays b);
void CREATEDELL_API_DU delete_node_rr(rays a, rays b);
void CREATEDELL_API_DU delete_node_ls(line a, lise b);
void CREATEDELL_API_DU delete_node_ss(lise a, lise b);
void CREATEDELL_API_DU delete_node_rs(rays a, lise b);
void CREATEDELL_API_DU delete_node_cc(Cycle a, Cycle b);
void CREATEDELL_API_DU delete_node_cl(Cycle a, line b);
void CREATEDELL_API_DU delete_node_cs(Cycle a, lise b);
void CREATEDELL_API_DU delete_node_cr(Cycle a, rays b);
void CREATEDELL_API_DU get_int(string l, double* a, double* b, double* c, double* d);
void CREATEDELL_API_DU get_int(string l, double* a, double* b, double* c);
void CREATEDELL_API_DU Delete(string l);
bool CREATEDELL_API_DU Add(string l);
void CREATEDELL_API_DU read_file(string input_file);