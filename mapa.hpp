#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <map>
#include <list>
#include <utility>
#include <functional>

#ifndef MAPA_H
#define MAPA_H

using namespace std;

class Grafo
{
private:
    int n;
    map<int, vector<pair<int, int>>> adj;

public:
    Grafo(int n)
    {
        this->n = n;
    };

    int getTam()
    {
        return this->adj.size();
    };

    void addRodovia(int u, int v, int w)
    {
        pair<int, int> aux;
        aux = make_pair(v-1, w);
        adj[u-1].push_back(aux);
    };

    int getNumV(int v)
    {
        return adj[v].size();
    };

    int getPeso(int u, int v)
    {
        int resp = -(INT_MAX / 2);
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (adj[u][i].first == v)
            {
                resp = adj[u][i].second;
                break;
            }
        }
        return resp;
    };

    int getVert(int u, int i)
    {
        return adj[u][i].first;
    };
};

#endif