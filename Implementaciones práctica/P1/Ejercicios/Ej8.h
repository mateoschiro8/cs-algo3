#ifndef P1_EJ8_H
#define P1_EJ8_H

#include <vector>
using namespace std;

bool noHayCortes (vector<int> &cortes, int i, int j){
    for (int k = i; k < j; ++k) {
        if (cortes[k]){
            return false;
        }
    }
    return true;
}

//           {0, 1, 0, 1, 0, 0, 1, 0, 0, 0}

int corte(vector<int> &cortes, int i, int j) {
    if(noHayCortes(cortes, i, j))
        return 0;
    else {
        int res = INF;
        for(int k = i; k < j; k++) {
            if(cortes[k]) {
                int tmp = j - i + corte(cortes, i, k) + corte(cortes, k + 1, j);
                if(tmp < res)
                    res = tmp; 
            }
        }
        return res;
    }
}

void pruebaEj8() {

    vector<int> cortes = {0, 1, 0, 1, 0, 0, 1, 0, 0, 0};
    int res = corte(cortes, 0, cortes.size());
    cout << "El mínimo coste es " << res << endl;

}

#endif //P1_EJ8_H