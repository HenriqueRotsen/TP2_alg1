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

    int getN()
    {
        return this->n;
    };

    void addRodovia(int u, int v, int w)
    {
        pair<int, int> aux;
        aux = make_pair(v - 1, w);
        adj[u - 1].push_back(aux);
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

    vector<int> Dijkstra(int s)
    {
        int size = this->n;
        vector<int> peso;
        peso.resize(size);
        vector<int> ant;
        ant.resize(size);

        for (int i = 0; i < size; i++)
        {
            peso[i] = -(INT_MAX / 2);
            ant[i] = -1;
        }

        peso[s] = INT_MAX / 2;
        priority_queue<pair<int, int>> q;
        q.push(make_pair(peso[s], s));

        int u, v;
        int alt;
        while (!q.empty())
        {
            u = q.top().second;
            q.pop();
            if (peso[u] == -(INT_MAX / 2))
            {
                break;
            }

            vector<pair<int, int>>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                // Get vertex label and weight of current adjacent
                // of u.
                v = (*i).first;
                alt = max(peso[v], min(peso[u], (*i).second));

                //  If there is shorted path to v through u.
                if (alt > peso[v])
                {
                    peso[v] = alt;
                    ant[v] = u;
                    q.push(make_pair(peso[v], v));
                }
            }
        }
        return peso;
    }
};

#endif