#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <utility>
#include <limits>
using namespace std;

// Valor infinito usado para representar distancias inalcanzables
const int INF = numeric_limits<int>::max();

/**
 * Clase Graph
 * Representa un grafo dirigido usando lista de adyacencia.
 * Cada posición del vector 'adj' almacena una lista de pares (v, peso)
 * donde existe una arista u -> v con un determinado peso.
 */
class Graph {
private:
    int V; // Número de vértices
    vector<vector<pair<int, int>>> adj; // Lista de adyacencia (v, peso)

public:
    // Constructor: inicializa el grafo con n vértices
    Graph(int n);

    // Agrega una arista dirigida desde u hasta v con peso w
    void addEdge(int u, int v, int w);

    // Retorna el número de vértices
    int getVertices() const;

    // Retorna la lista de adyacencia completa
    const vector<vector<pair<int, int>>>& getAdj() const;
};

#endif
