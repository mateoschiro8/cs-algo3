#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool esPrefijo(const string& cadena, const string& prefijo, size_t i = 0) {
    // Verifica si la longitud del prefijo más la posición i es mayor que la longitud de la cadena
    if (i + prefijo.length() > cadena.length()) {
        return false;
    }

    // Compara los caracteres de la cadena y el prefijo a partir de la posición i
    for (size_t j = 0; j < prefijo.length(); ++j) {
        if (cadena[i + j] != prefijo[j]) {
            return false;  // Caracteres diferentes, no es un prefijo
        }
    }

    return true;  // Todos los caracteres coinciden, es un prefijo

    // Adivinen de donde salió esta función que ni ganas teníamos de codear
}

// O(n * k * min(s, nk))
int cadenas(int i, string& s, vector<string>& dicc) {

    if(i == s.size())
        return 1;

    int res = 0;
    for(int k = 0; k < dicc.size(); k++) {
        res += esPrefijo(s, dicc[k], i) ? cadenas(i + dicc[k].size(), s, dicc) : 0; 
    
    }
    return res;
}   

void pruebaCadenas() {

    vector<string> d = {"a", "abra", "cad", "bra", "cada"};
    string s = "abracadabra";
    
    int res = cadenas(0, s, d);

    cout << res << endl; 


}

