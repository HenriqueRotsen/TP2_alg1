#include "mapa.hpp"

using namespace std;

void Dijkstra(Grafo g, int s)
{
    int size = g.getTam();
    vector<int> peso;
    peso.resize(size);
    vector<int> ant;
    ant.resize(size);
    
    for (int i = 0; i < size; i++)
    {
        peso[i] = -(INT_MAX / 2);
        ant[i] = -1;
    }

    peso[s] = 0;
    list<pair<int, int>> q;
    pair<int, int> aux;

    for (int i = 0; i < size; i++)
    {
        aux = make_pair(peso[i], i);
        q.push_back(aux);
    }
    q.sort();

    int u, v; 
    int alt;
    while (q.size() != 0)
    {
        u = q.front().second;
        q.pop_front();
        if (peso[u] == -(INT_MAX/2))
        {
            break;
        }
        
        for (int i = 0; i < g.getNumV(u); i++)
        {
            v = g.getVert(u, i);
            alt = max(peso[i], min(peso[u], g.getPeso(u,v)));
            if (alt > peso[v])
            {
                peso[v] = alt;
                ant[v] = u;
                
            }
        }
    }
}

int main()
{
    int n, m, q;
    cin >> n;
    assert(2 <= n && n <= 100);
    cin >> m;
    assert(1 <= m && m <= min(n * (n - 1), 1000));
    cin >> q;
    assert(1 <= q && q <= 1000);

    int u, v, w;
    Grafo g(n);
    pair<int, int> aux;

    for (int k = 0; k < m; k++)
    {
        cin >> u;
        assert(1 <= u);
        cin >> v;
        assert(v <= n && v != u);
        cin >> w;
        assert(1 <= w && w <= 100000);
        g.addRodovia(u, v, w);
    }

    int source, dest;
    for (int i = 0; i < q; i++)
    {
        cin >> source;
        cin >> dest;
        Dijkstra(g, source-1);
    }
}