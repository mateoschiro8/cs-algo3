
#ifndef P1_EJ6_H
#define P1_EJ6_H

#include <vector>
using namespace std;

pair<int, int> ccBT(vector<int> &B, int i, int j) {

    // Si me quedé sin billetes y todavía me queda para pagar
    if (i < 0 && j > 0)
        return {INF, INF};

    // Si no queda pagar más
    else if (j <= 0)
        return {0, 0};

    else {
        // Pruebo agregando el billete que estoy considerando
        pair<int, int> agrego = ccBT(B, i - 1, j - B[i]);

        // Pruebo sin agregar el billete que estoy considerando
        pair<int, int> noAgrego = ccBT(B, i - 1, j);

        // Devuelvo el mínimo entre los siguientes:
        // < valor del billete + minimo costo que puedo pagar hasta el billete i - 1, 1 + minima cantidad de billetes >
        // <                     minimo costo que puedo pagar hasta el billete i - 1,     minima cantidad de billetes >

        return min({B[i] + agrego.first, 1 + agrego.second}, noAgrego);
    }
}

pair<int, int> ccPDTopDown(vector<int> &B, vector<vector<pair<int, int>>> &m, int i, int j) {

    // Si me quedé sin billetes y todavía me queda para pagar
    if (i < 0 && j > 0)
        return {INF, INF};

        // Si no queda pagar más
    else if (j <= 0)
        return {0, 0};

    else {

        // Me fijo si ya está en la matriz
        if(m[i][j] != make_pair(-1, -1))
            return m[i][j];

        else {
            // Pruebo agregando el billete que estoy considerando
            pair<int, int> agrego = ccPDTopDown(B, m, i - 1, j - B[i]);

            // Pruebo sin agregar el billete que estoy considerando
            pair<int, int> noAgrego = ccPDTopDown(B, m, i - 1, j);

            m[i][j] = min({B[i] + agrego.first, 1 + agrego.second}, noAgrego);
            return m[i][j];
        }
    }
}

void pruebaEj6() {
    vector<int> B = {2,3,5,10};
    int c = 14;

    // pair<int, int> s1 = ccBT(B, B.size() - 1, c);

    vector<vector<pair<int, int>>> m(B.size(), vector<pair<int,int>>(c + 1, {-1, -1})) ;

    pair<int, int> s2 = ccPDTopDown(B, m, B.size() - 1, c);
    cout << "Se puede pagar " << s2.first << " usando " << s2.second << " billetes" << endl;
}

#endif //P1_EJ6_H
