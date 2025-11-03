#include "graph.hpp"
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

/**
 * BFS_SP
 * Calcula los caminos mínimos en un grafo no ponderado.
 * Parámetros:
 *   - g: grafo de entrada
 *   - s: vértice fuente
 *   - outputPath: ruta del archivo donde se guardará la salida
 * Retorno: no devuelve nada (escribe resultados en archivo)
 */
void BFS_SP(const Graph& g, int s, const string& outputPath) {
    int n = g.getVertices();
    vector<int> dist(n + 1, INF); // distancia desde la fuente
    vector<int> prev(n + 1, -1);  // predecesor para reconstruir caminos

    queue<int> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, w] : g.getAdj()[u]) {
            // Si el nodo aún no fue visitado
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                prev[v] = u;
                q.push(v);
            }
        }
    }

    // Escribir resultados en archivo
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
}
