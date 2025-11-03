#include "graph.hpp"
#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

/**
 * Dijkstra_SP
 * Calcula caminos mínimos en un grafo ponderado con pesos no negativos.
 * Parámetros:
 *   - g: grafo de entrada
 *   - s: vértice fuente
 *   - outputPath: archivo donde se guardarán resultados
 * Retorna:
 *   - true si se ejecutó correctamente
 *   - false si se detectaron pesos negativos
 */
bool Dijkstra_SP(const Graph& g, int s, const string& outputPath) {
    int n = g.getVertices();
    vector<int> dist(n + 1, INF);
    vector<int> prev(n + 1, -1);

    // Cola de prioridad (distancia, vértice)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : g.getAdj()[u]) {
            // Dijkstra no permite pesos negativos
            if (w < 0) {
                ofstream out(outputPath);
                out << "no soportado (pesos negativos)\n";
                out << "Dijkstra requiere pesos no negativos para garantizar optimalidad.\n";
                out.close();
                return false;
            }

            // Relajación clásica
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Escribir resultados
    ofstream out(outputPath);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            out << "Dist(" << s << "->" << i << ") = INF\n";
        } else {
            out << "Dist(" << s << "->" << i << ") = " << dist[i] << " | Camino: ";
            vector<int> path;
            for (int v = i; v != -1; v = prev[v]) path.push_back(v);
            for (int j = path.size() - 1; j >= 0; j--) {
                out << path[j];
                if (j > 0) out << " -> ";
            }
            out << "\n";
        }
    }
    out.close();
    return true;
}
