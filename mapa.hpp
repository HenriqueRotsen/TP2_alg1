#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

#ifndef MAPA_H
#define MAPA_H

class Rodovia
{
private:
    int pesoMax;
    int u;
    int v;
public:
    Rodovia(){pesoMax = 0; u =-1; v = -1;};
    void setPeso(int p) { this->pesoMax = p; };
    int getPeso() { return pesoMax; };
    void setU(int u) { this->u = u; };
    int getU() { return u; };
    void setV(int v) { this->v = v; };
    int getV() { return v; };
};

class Mapa
{
private:
    Rodovia r;
    int n;
    int m;
    vector<vector<Rodovia>> mapa;
public:
    Mapa(int n, int m) {
        this->n = n;
        this->m = m;
        mapa.resize(n, vector<Rodovia>(m)); 
    };

    int getVertices() { return n*m; };

    void addRodovia(Rodovia r, int x, int y) {
        mapa[x][y] = r;
    };


};



#endif