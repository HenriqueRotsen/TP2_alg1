#include "mapa.hpp"

using namespace std;

vector<int> Dijkstra(Grafo g, int s)
{
    int size = g.getN();
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

        for (int i = 0; i < g.getNumV(u); i++)
        {
            v = g.getVert(u, i);
            alt = max(peso[v], min(peso[u], g.getPeso(u, v)));            
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
    vector<int> resp;
    for (int i = 0; i < q; i++)
    {
        cin >> source;
        cin >> dest;
        resp = g.Dijkstra(source - 1);
        cout << resp[dest - 1] << endl;
    }
}