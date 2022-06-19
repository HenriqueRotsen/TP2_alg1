#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <map>
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

    // Acrescenta uma rodovia r de A --> B
    void addRodovia(int u, int v, int w)
    {
        pair<int, int> aux;
        aux = make_pair(v - 1, w);
        adj[u - 1].push_back(aux);
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
                v = (*i).first;
                alt = max(peso[v], min(peso[u], (*i).second));

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