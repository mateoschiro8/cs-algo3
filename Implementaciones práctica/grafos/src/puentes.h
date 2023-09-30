#include <iostream>
#include <vector>

using namespace std;

// Algoritmo para determinar Tree Edges, Back Edges y Puentes,
// a partir del recorrido DFS de un grafo CONEXO y utilizando el algoritmo de Tarjan

int noVisto = 0, enProceso = 1, visto = 2;

vector<vector<int>> aristas = {{}, {3,5,6,9}, {4,6,8}, {1,5,6,7}, {2,10}, {1,3,7}, {1,2,3}, 
                               {3,5}, {2,3}, {1,11,12}, {4}, {9,12}, {9,11}};
    
int n = aristas.size();

vector<int> padre(n, 0);
vector<int> estado(n, noVisto);
vector<int> profundidad(n, 0);

vector<pair<int, int>> treeEdges;
vector<pair<int, int>> backEdges;
vector<pair<int, int>> bridges;

// Tiempo que un nodo tomó para ser visitado
vector<int> tiempoVisto(n);

// Mínimo tiempo de visita de todos los nodos adyacentes (y distintos al padre) de un nodo
vector<int> minTiempoVisto(n);

int tiempo = 1;

void dfsPuentes(int v) {

    cout << " " << v << ",";

    estado[v] = visto;

    profundidad[v] = profundidad[padre[v]] + 1;

    tiempoVisto[v] = tiempo;
    minTiempoVisto[v] = tiempo;
    tiempo++;

    for(int u : aristas[v]) {

        if(u == padre[v])
            continue;

        if(estado[u] == noVisto) {
            
            padre[u] = v;
            treeEdges.push_back({v, u});

            dfsPuentes(u);
            
            minTiempoVisto[v] = min(minTiempoVisto[v], minTiempoVisto[u]);

            if(minTiempoVisto[u] > tiempoVisto[v]) 
                bridges.push_back({v, u});

        }   

        else if(u != padre[v]) {

        minTiempoVisto[v] = min(minTiempoVisto[u], minTiempoVisto[v]);        
        
        if(profundidad[u] < profundidad[v])
            backEdges.push_back({u, v});

        }
    
    }

}

void puentes() {

    int inicial = 1;

    cout << "Recorrido DFS " << endl;
    cout << "Pasé por: ";
    dfsPuentes(inicial);
    cout << endl;

    cout << "Las tree edges son: " << endl;
    for(auto [v, w] : treeEdges) 
        cout << v << "-" << w << ", ";
    cout << endl;

    cout << "Las back edges son: " << endl;
    for(auto [v, w] : backEdges) 
        cout << v << "-" << w << ", ";
    cout << endl;

    cout << "Los puentes son: " << endl;
    for(auto [v, w] : bridges) 
        cout << v << "-" << w << ", ";
    cout << endl;

}