#ifndef P1_EJ7_H
#define P1_EJ7_H

#include <vector>
using namespace std;

int mgnBT(vector<int> &p, int cant, int j);

int comprar(vector<int> &p, int cant, int j) {
    return -p[j] + mgnBT(p, cant + 1, j + 1);
}

int vender(vector<int> &p, int cant, int j) {
    if(cant == 0)
        return -INF;
    else
        return p[j] + mgnBT(p, cant - 1, j + 1);
}

int nada(vector<int> &p, int cant, int j) {
    return mgnBT(p, cant, j + 1);
}

int mgnBT(vector<int> &p, int cant, int j) {
    if(j == p.size() && cant == 0)
        return 0;
    else if(j == p.size() && cant > 0)
        return -INF;
    else {
        int compra = comprar(p, cant, j);
        int venta = vender(p, cant, j);
        int natti = nada(p, cant, j);
        return max(compra, max(venta, natti));
    }
}

int mgnPDTopDown(vector<int> &p, vector<vector<int>> &m, int cant, int j) {
    if(j == p.size() && cant == 0)
        return 0;
    else if(j == p.size() && cant > 0)
        return -INF;
    else {
        if(m[cant][j] == -1) {
            int compra = -p[j] + mgnPDTopDown(p, m, cant + 1, j + 1);
            int venta = cant == 0 ? -INF : p[j] + mgnPDTopDown(p, m, cant - 1, j + 1);
            int natti = mgnPDTopDown(p, m, cant, j + 1);
            m[cant][j] = max(compra, max(venta, natti));
        }
        return m[cant][j];
    }
}

int mgnPDBottomUp(vector<int> &p, vector<vector<int>> &m) {
    // Anda a chequearlo este

    // m[cant][j]
    int n = p.size();
    m[0][n] = 0;
    for (int i = 1; i <= n; ++i) {
        m[i][n] = -INF;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int k = n; k >= 0; --k) {
            int c = i > n ? -INF : (-p[k] + m[i + 1][k + 1]);
            int v = (i > n || i == 0) ? -INF : (p[k] + m[i - 1][k + 1]);
            int d = i > n ? -INF : (m[i + 1][k + 1]);
            m[i][k] = max(c, max(v, d));
        }
    }
    return m[0][0];
}

void pruebaEj7() {

    vector<int> p = {3, 2, 5, 6};
    vector<vector<int>> m(p.size() + 1, vector<int>(p.size() + 1, -1));

    // int mgn = mgnBT(p, 0, 0);
    int mgn = mgnPDTopDown(p, m, 0, 0);
    // int mgn = mgnPDBottomUp(p, m);

    cout << "Puede sacar " << mgn << " de ganancia";

}

#endif //P1_EJ7_H
