# Graph and Algorithms Library

This project is a comprehensive **Graph and Algorithms Library** developed to handle complex graph structures and provide efficient solutions to common graph-related problems. It offers a flexible, C++-based graph data structure and a set of algorithms for tasks like connectivity checks, pathfinding, cycle detection, and more.

---

## 📋 Features

### 1. Robust Graph Operations
- **Graph Loading**: Load graphs from adjacency matrices for quick setup.
- **Graph Printing**: Display the structure and details of the graph (vertices, edges).
- **Access Methods**: Retrieve specific properties and perform read-only operations on the graph.

### 2. Advanced Graph Algorithms
- **Connectivity**: Check if all nodes are reachable and, for directed graphs, assess strong connectivity.
- **Cycle Detection**: Identify cycles within the graph.
- **Shortest Path**: Compute shortest paths using BFS for unweighted graphs and Bellman-Ford for weighted graphs.
- **Bipartiteness**: Verify if the graph is bipartite using a coloring algorithm.
- **Negative Cycle Detection**: Detect negative cycles with Bellman-Ford.

---

## 🔧 Implementation Details

### Graph Class
The `Graph` class is built to efficiently manage graph data using an adjacency matrix. Key elements include:

- **Data Structure**: `adjMatrix`, a 2D vector storing edge weights between nodes for fast O(1) lookups.
  
- **Key Methods**:
  - `loadGraph(const std::vector<std::vector<int>>& matrix)`: Initializes the graph from a square matrix, validating input to ensure robustness.
  - `printGraph()`: Prints vertex and edge count, dynamically calculated. Avoids duplicate edge counts in undirected graphs.
  - `size() const`: Returns the number of vertices, derived from matrix dimensions.
  - `operator[](int index) const`: Provides read-only access to adjacency list items, essential for non-modifying algorithm operations.

### Algorithms Class
The `Algorithms` class provides static methods that operate directly on any `Graph` instance, emphasizing utility and versatility.

#### Core Algorithms
- **Connectivity (isConnected)**: Uses DFS to verify reachability for all nodes. For directed graphs, it checks the transposed graph to confirm strong connectivity.
- **Cycle Detection (findCycle)**: Uses DFS and tracks nodes in the recursion stack to detect cycles.
- **Shortest Path (shortestPath)**: Determines shortest paths with BFS (unweighted) or Bellman-Ford (weighted), adapting to graph type for optimal performance.
- **Bipartiteness (isBipartite)**: Uses a coloring algorithm to check for valid bipartite conditions.
- **Negative Cycle Detection (negativeCycle)**: Implements Bellman-Ford to detect negative weight cycles by monitoring changes in shortest path estimates.

---

## 🛠 Helper Functions

Given the flexibility required to handle weighted/unweighted and directed/undirected graphs, several helper functions support core functionality:

- **DFS**: Depth-first search traversal.
- **BFS**: Breadth-first search to find the shortest path in unweighted graphs.
- **isWeighted**: Checks if the graph contains weighted edges.
- **bellmanFord**: Runs Bellman-Ford and indicates if a negative cycle is detected, otherwise returns the shortest path.
- **findCycle**: Detects cycles by revisiting nodes.
- **transpose**: Transposes the graph for strong connectivity checks in directed graphs.
- **isDirected**: Verifies if the graph is directed based on matrix symmetry.

---

## 📂 Project Structure

- **Graph.hpp/cpp**: Defines the `Graph` class for managing graph structure and data.
- **Algorithms.hpp/cpp**: Contains static methods for graph analysis, such as connectivity and pathfinding.
- **Main.cpp**: Demonstrates library usage and provides examples of graph manipulation and analysis.

---

## 🚀 Getting Started

### Requirements
- **C++ Compiler**: Ensure C++11 or higher for compatibility.

### Compilation
To compile the project, navigate to the project directory and use:
```bash
g++ -std=c++11 -o graph_library Main.cpp Graph.cpp Algorithms.cpp

