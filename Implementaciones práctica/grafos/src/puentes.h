#include <iostream>
#include <vector>

using namespace std;

// Algoritmo para determinar Tree Edges, Back Edges y Puentes a partir del recorrido BFS de un grafo CONEXO


int noVisto = 0, enProceso = 1, visto = 2;

vector<vector<int>> aristas = {{3,5,6,9}, {4,6,8}, {1,5,6,7}, {2,10}, {1,3,7}, {1,2,3}, 
                               {3,5}, {2,3}, {1,11,12}, {4}, {9,12}, {9,11}};
    
int n = aristas.size();

vector<pair<int, int>> treeEdges;
vector<pair<int, int>> backEdges;
vector<pair<int, int>> bridges;

vector<vector<int>> treeEdgesPorNodo(n);

vector<int> profundidad(n, 0);

vector<int> backEdgesConExtremoInferiorEn(n, 0);
vector<int> backEdgesConExtremoSuperiorEn(n, 0);

vector<int> padre(n, 0);

void dfsPuentes(int v, vector<int>& estado) {

    estado[v - 1] = visto;
    profundidad[v - 1] = (v - 1 > 0) ? profundidad[padre[v - 1] - 1] + 1 : 0;
    cout << " " << v << ",";

    for(int u : aristas[v - 1]) {
        if(estado[u - 1] == noVisto) {
            treeEdges.push_back({v, u});
            padre[u - 1] = v;
            dfsPuentes(u, estado);
        }   
        else if(estado[u - 1] == enProceso) {
            backEdgesConExtremoInferiorEn[u - 1]++;

    }
        else if(estado[u - 1] == visto && padre[v - 1] != u) {
            if(profundidad[u - 1] < profundidad[v - 1])
                backEdges.push_back({u, v});
            backEdgesConExtremoSuperiorEn[u - 1]++;
        }
    }
    estado[v] == visto;

}

vector<int> memo(n, - 1);
int cubren(int v, int p = -1) {
    if(memo[v - 1] == -1) {
        
        int res = 0;

        for(int hijo : treeEdgesPorNodo[v - 1]) {
            if(hijo != p)
                res += cubren(hijo, v);
        }
        
        res -= backEdgesConExtremoSuperiorEn[v - 1];
        res += backEdgesConExtremoInferiorEn[v - 1];

        memo[v - 1] = res;
    }

    return memo[v - 1];
}

void puentes() {

    treeEdges = {};
    backEdges = {};

    vector<int> estado(n, noVisto);
    cout << "Recorrido DFS " << endl;
    cout << "Pasé por: ";
    dfsPuentes(1, estado);
    cout << endl;

    cout << "Las tree edges son: " << endl;
    for(auto [v, w] : treeEdges) 
        cout << v << "-" << w << ", ";
    cout << endl;

    cout << "Las back edges son: " << endl;
    for(auto [v, w] : backEdges) 
        cout << v << "-" << w << ", ";
    cout << endl;

    /*
    cout << "Profundidades: " << endl;
    for(int i = 0; i < profundidad.size(); i++) 
        cout << "El nodo " << i + 1 << " tiene profundidad " << profundidad[i] << endl;
    
    cout << "Padres: " << endl;
    for(int i = 0; i < padre.size(); i++) 
        cout << "El padre de " << i + 1 << " es " << padre[i] << endl;
    */

    int puentes = 0;
    for(int i = 0; i < n; i++) {
        if(cubren(i) == 0)
            puentes++;
    }
    cout << "Y tiene " << puentes << " puentes" << endl;

    cout << "Pero eso no es correcto y hace falta corregirlo salu2" << endl;
}