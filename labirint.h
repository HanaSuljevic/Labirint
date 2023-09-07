#ifndef LABIRINT_H
#define LABIRINT_H
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

class Labirint{
public:
    int brojRedova;
    int brojPozicija;
    vector< vector <int> > prolazi;
    void unesiPodatke(istream &in);
    int udaljenost1(int prviZid, int pozicijaPrvog, int drugiZid, int pozicijaDrugog);
    int udaljenost (char prviZid, int pozicijaPrvog, char drugiZid, int pozicijaDrugog);

};
#endif // LABIRINT_H


