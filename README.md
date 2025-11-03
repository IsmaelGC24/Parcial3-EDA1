# Evaluation 03 – Practical Assignment (Moment 2)
**Course:** Data Structures and Algorithms  
**University:** EAFIT  
**Language:** C++  
**IDE/Environment:** Visual Studio Code  
**Compiler:** g++ (C++11 or later)  

---

## Project Description
This project was developed as part of **Evaluation 03 – Practical Assignment (Moment 2)** for the course *Data Structures and Algorithms (EDA1)*.  
The goal is to **implement and compare two algorithms for the Single-Source Shortest Path (SSSP) problem**:

- **BFS (Breadth-First Search):** for unweighted graphs, minimizing the number of edges.  
- **Dijkstra’s Algorithm:** for weighted graphs with non-negative edge weights, minimizing the total path cost.

The project calculates distances and reconstructs paths from a given source vertex.  
It also measures execution time to compare both algorithms in terms of efficiency and applicability.

---

## Features

- Implementation of BFS and Dijkstra using adjacency list representation.  
- Automatic rejection of negative weights in Dijkstra.  
- Path reconstruction for reachable vertices.  
- Output of minimum distances and paths to `/results/dist_casoX.txt`.  
- Execution time logging to `/results/tiempos.csv`.  
- Modular code structure (separate source files for clarity).  

## How to Compile and Run

## Compile
```bash

g++ src/*.cpp -o parcial3
```

## Run
```bash

./parcial3
```

## The program will display a menu to select a test case:

1. No ponderado (BFS)
2. Ponderado (Dijkstra)
3. Inalcanzables (BFS)
4. Ciclos (BFS)
5. Negativo (Dijkstra)
6. Denso (Dijkstra)
Opcion: _

The corresponding results and time will be saved automatically in /results/.

## Documentation

The documentation (report/Documentacion.Parcial3.pdf) includes:

- Problem description and objectives

- BFS and Dijkstra pseudocode

- Comparison of complexities

- Experimental results in console

- Conclusions on algorithm selection

- Explanation of tiempos.csv format

