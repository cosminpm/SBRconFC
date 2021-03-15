#ifndef SBR_BCCLASS_H
#define SBR_BCCLASS_H

#include <fstream>
#include <iostream>
#include <string.h>
#include <string_view>
#include <map>
#include <vector>

#include "bhClass.h"

using namespace std;

class reglaClass{
public:
    reglaClass(string line);
    void showFactorRegla();
    void showParteDerecha();
    void showTipo();
    void showParteIzquierda();
    void showReglaCompleta();
    void salidaRegla(ofstream& of);

    char getTipo();
    double getFactorCertezaRegla();
    vector<string> getParteIzquierda();
    string getParteDerecha();


private:
    double factorCerteza;
    // Nos indicara si son conjunciones, disyunciones o simplemente un literal
    char tipo;
    vector<string> parteIzquierda;
    string parteDerecha;

};

class bcClass{
public:
    bcClass(ifstream& fileBC);
    int getNumeroReglas();
    map<string, reglaClass> getMapaReglas();

    void showNumeroReglas();
    void showMapaReglas();


private:
    int numeroReglas;
    map<string, reglaClass> mapaReglas;
};

#endif
