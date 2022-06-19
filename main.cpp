#include "mapa.hpp"

int main()
{
    // Leitura com verificacao de condicoes iniciais
    int n, m, q;
    cin >> n;
    assert(2 <= n && n <= 100);
    cin >> m;
    assert(1 <= m && m <= min(n * (n - 1), 1000));
    cin >> q;
    assert(1 <= q && q <= 1000);

    // Leitura das rodovias + verificacao
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

    // Procura da resposta de maneira otimizada
    int source, dest;
    vector<int> resp;
    vector<vector<int>> helper; // matriz que guarda as respostas
    helper.resize(n);
    for (int i = 0; i < q; i++)
    {
        cin >> source;
        cin >> dest;
        if (!helper[source - 1].empty()) // se ja tiver a resposta ele não chama o Dijkstra denovo.
        {
            cout << helper[source - 1][dest - 1] << endl;
        }
        else // Caso nao tenha chamado o Dijkstra para aquela entrada
        {
            resp = g.Dijkstra(source - 1);
            helper[source - 1] = resp;
            cout << resp[dest - 1] << endl;
        }
    }
}