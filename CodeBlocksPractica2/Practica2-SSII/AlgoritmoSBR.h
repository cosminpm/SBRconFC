#ifndef ALGORITMO_SBR
#define ALGORITMO_SBR

#include "bcClass.h"
#include "bhClass.h"
#include <iostream>

double verificar(class bcClass& bc, class bhClass& bh, string Meta, ofstream& fileBC);
double CalculoCaso1(vector<double> v, char t);
double CalculoCaso2(vector<double> v);
void imprimirCaso1(vector<double> v, char t,ofstream& of);
#endif
