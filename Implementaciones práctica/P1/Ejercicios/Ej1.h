
#ifndef P1_EJ1_H
#define P1_EJ1_H

#include <vector>
using namespace std;

int INF = 1e9;

bool subsetSum(vector<int>& c, vector<int>& p, int i, int j) {
    // Regla de factibilidad
    if(j < 0)
        return false;

    // Si llegué a la suma que busco, imprimo el subconjunto
    if(j == 0) {
        for(int m : p) {
            cout << m << " ";
        }
        cout << endl;
        return true;
    }

    if(i == 0)
        return false;

    // Pruebo incluir el elemento actual en el subconjunto
    p.push_back(c[i - 1]);
    bool incluido = subsetSum(c, p, i - 1, j - c[i - 1]);
    p.pop_back();

    // Pruebo no incluirlo
    bool noIncluido = subsetSum(c, p, i - 1, j);

    return incluido || noIncluido;
}

void pruebaEj1() {
    vector<int> c = {6, 12, 6};
    vector<int> p = {};
    int k = 12;
    int i = c.size();
    bool tiene = subsetSum(c,p, i, k);
    if(!tiene)
        cout << "No tiene solución" << endl;
}

#endif //P1_EJ1_H
