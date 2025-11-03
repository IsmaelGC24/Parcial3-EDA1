#include "graph.hpp"

// Constructor: redimensiona el vector de adyacencia
Graph::Graph(int n) {
    V = n;
    adj.resize(n + 1);
}

// Agrega una arista dirigida u -> v con peso w
void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
}

// Retorna el número de vértices
int Graph::getVertices() const {
    return V;
}

// Retorna la lista de adyacencia
const vector<vector<pair<int, int>>>& Graph::getAdj() const {
    return adj;
}
