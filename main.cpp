#include "mapa.hpp"

void inicializaD(Mapa m, int d, int p, int s)
{
    for (int i = 0; i < m.getVertices(); i++)
    {
        d[i] = INT_MAX/2;
        p[i] = -1;
    }
    d[s] = 0;    
}

int main()
{
    int n, m, q;
    cin >> n;
    assert(2 <= n && n <= 100);
    cin >> m;
    assert(1 <= m && m <= min(n*(n-1), 1000));
    cin >> q;
    assert(1 <= q && q <= 1000);

    int u, v, w;
    Rodovia r;
    Mapa mg(n, m);
    for (int i = 0; i < m; i++)
    {
        cin >> u;
        assert(1 <= u);
        r.setU(u);
        cin >> v;
        assert(v <= n && v != u);
        r.setV(v);
        cin >> w;
        assert(1 <= w && w <= 100000);
        r.setPeso(w);
        mg.addRodovia(r, u-1, v-1);
    }


}