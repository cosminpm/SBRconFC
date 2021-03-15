#ifndef SBR_BHCLASS_H
#define SBR_BHCLASS_H

#include <fstream>
#include <iostream>
#include <string.h>
#include <string_view>
#include <map>
using namespace std;

//typedef class bhClass bhClass;

class bhClass{
public:
    bhClass(ifstream& fileBH);
    void showMap();
    void showNumeroHechos();
    void showObjetivo();

    int getNumeroHechos();
    void incrementarNumeroHechos();
    void aniadirEntradaMapa(string, double);
    string getObjetivo();
    map<string, double> getMapaHechos();

private:
    int numeroHechos;
    string objetivo;
    map<string, double> mapaHechos;
};

#endif
