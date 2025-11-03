#include "graph.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

// Declaración de funciones externas
void BFS_SP(const Graph&, int, const string&);
bool Dijkstra_SP(const Graph&, int, const string&);

/**
 * Main
 * - Permite elegir un caso de prueba.
 * - Lee el grafo desde un archivo .
 * - Ejecuta BFS o Dijkstra según el tipo.
 * - Guarda distancias, caminos y tiempos de ejecución.
 */
int main() {
    cout << "Seleccione caso de prueba:\n";
    cout << "1. No ponderado (BFS)\n";
    cout << "2. Ponderado (Dijkstra)\n";
    cout << "3. Inalcanzables (BFS)\n";
    cout << "4. Ciclos (BFS)\n";
    cout << "5. Negativo (Dijkstra)\n";
    cout << "6. Denso (Dijkstra)\n";
    cout << "Opcion: ";

    int opcion;
    cin >> opcion;

    string fileNames[] = {
        "", // índice 0 vacío
        "caso_no_ponderado.txt",
        "caso_ponderado.txt",
        "caso_inalcanzables.txt",
        "caso_ciclos.txt",
        "caso_negativo.txt",
        "caso_denso.txt"
    };

    if (opcion < 1 || opcion > 6) {
        cerr << "Opción inválida.\n";
        return 1;
    }

    string inputPath = "data/" + fileNames[opcion];
    ifstream in(inputPath);
    if (!in.is_open()) {
        cerr << "Error al abrir " << inputPath << "\n";
        return 1;
    }

    // Leer parámetros básicos del grafo
    int n, m, s, tipo;
    in >> n >> m >> s >> tipo;
    Graph g(n);

    // Leer todas las aristas
    for (int i = 0; i < m; i++) {
        int u, v, w;
        in >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    in.close();

    // Medir tiempo de ejecución
    auto start = chrono::high_resolution_clock::now();

    string outputPath = (tipo == 0) ? "results/dist_caso1.txt" : "results/dist_caso2.txt";

    if (tipo == 0) {
        BFS_SP(g, s, outputPath);
    } else if (tipo == 1) {
        Dijkstra_SP(g, s, outputPath);
    } else {
        cerr << "Tipo inválido (0 = no ponderado, 1 = ponderado).\n";
        return 1;
    }

    auto end = chrono::high_resolution_clock::now();
    double t_ms = chrono::duration<double, milli>(end - start).count();

    // Registrar el tiempo en CSV (modo append)
    ofstream tiempos("results/tiempos.csv", ios::app);
    tiempos << n << "," << m << "," << tipo << "," << t_ms << "\n";
    tiempos.close();

    cout << "Ejecucion completada. Resultados guardados en " << outputPath << endl;
    return 0;
}
