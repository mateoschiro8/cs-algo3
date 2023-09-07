#ifndef P1_EJ9_H
#define P1_EJ9_H

#include <vector>
using namespace std;

int minVidaTD(vector<vector<int>> &m, vector<vector<int>> &memo, int i, int j) {

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
           memo[i][j] = max(1, min(minVidaTD(m, memo, i + 1, j), minVidaTD(m, memo, i, j + 1)) - m[i][j]);
        return memo[i][j];
    }
    
}

int minVidaBU(vector<vector<int>> &m, vector<vector<int>> &memo) {

    // Recorremos la matriz de memoria de derecha a izquierda, de abajo hacia arriba
    for (int i = memo.size() - 1; i >= 0; i--) {
        for (int j = memo[0].size() - 1; j >= 0; j--) {
            
            // Valor de abajo. Si se va de rango, INF
            int abajo = (i + 1 == memo.size()) ? INF : memo[i + 1][j];  
            
            // Valor de la derecha. Si se va de rango, INF
            int derecha = (j + 1 == memo[0].size()) ? INF : memo[i][j + 1];
            
            // Caso especial de la casilla de afuera que tiene que devolver 1 
            if(i == memo.size() - 1 && j == memo[0].size() - 1)
                derecha = 1;

            memo[i][j] = max(1, min(abajo, derecha) - m[i][j]);

        }    
    }
 
    for (int i = 0; i < memo.size(); i++) {
        for (int j = 0; j < memo[0].size(); j++) {
            std::cout << memo[i][j] << " ";
        }
        std::cout << std::endl; // Nueva línea después de cada fila
    }

    // Devolvemos la información que queremos
    return memo[0][0];    
    
}


void pruebaEj9() {

    vector<vector<int>> m = {{-2, -3, 3},
                             {-5, -10, 1},
                             {10, 30, -5}};

    vector<vector<int>> memo(m.size(), vector<int>(m[0].size(), -1));

    // int min = minVidaTD(m, memo, 0, 0);
    int min = minVidaBU(m, memo);

    cout << "La minima vida necesaria es " << min << endl;

}

#endif //P1_EJ9_H