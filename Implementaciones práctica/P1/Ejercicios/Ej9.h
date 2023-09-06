#ifndef P1_EJ9_H
#define P1_EJ9_H

#include <vector>
using namespace std;

int minVida(vector<vector<int>> &m, vector<vector<int>> &memo, int i, int j) {

    // Tomo esta posición fuera de m como el caso para cortar la recursión y 
    // empezar a armar la vida hacia arriba. Devuelve 1 porque es la minima vida requerida 
    if(i == m.size() - 1 && j == m[0].size())
        return 1;

    // Si en algun momento se sale del terreno, devuelve infinito
    else if(i == m.size() || j == m[0].size())
        return INF;

    // Caso contrario, compara los caminos de la derecha y de abajo. Al mínimo de esos, 
    // le resta el valor de la casilla actual. 
    // Si ese valor es positivo, lo devuelve. Si no, devuelve 1. 
    else {
        if(memo[i][j] == -1)
           memo[i][j] = max(1, min(minVida(m, memo, i + 1, j), minVida(m, memo, i, j + 1)) - m[i][j]);
        return memo[i][j];
    }
    
}


void pruebaEj9() {

    //vector<vector<int>> m = {{-2, -3, 3},
    //                         {-5, -10, 1},
    //                         {10, 30, -5}};


    vector<vector<int>> m = {{-1, -1, -1},
                             {-1, -1, -1},
                             {-1, -1, -1}};

    
    vector<vector<int>> memo(m.size(), vector<int>(m[0].size(), -1));

    int min = minVida(m, memo, 0, 0);
    cout << "La minima vida necesaria es " << min << endl;

}

#endif //P1_EJ9_H