# TichnutMaarachot2.1

Graph and Algorithms Library:
This library provides a comprehensive implementation of a graph data structure alongside a suite of algorithms to manipulate and analyze its properties. 

Features:
Robust Graph Operations: Includes methods for graph loading, printing, and accessing properties.
Advanced Graph Algorithms: Offers a variety of algorithms for connectivity checks, pathfinding, cycle detection, and more.
Implementation Details

Graph Class:
The Graph class is designed to efficiently manage graph data. 

Data Structures:
Adjacency Matrix (adjMatrix): A 2D vector that holds edge weights directly between any two nodes, ideal for quick lookups and updates which are O(1) operations.

Key Methods:
loadGraph(const std::vector<std::vector<int>>& matrix): Initializes the graph with a square matrix. Validates the matrix to ensure it is square, providing robust error handling to prevent runtime issues.

printGraph(): Outputs the number of vertices and edges, which are calculated dynamically. For edges, it counts only unique connections in the matrix to avoid duplicates in an undirected graph.

size() const: Returns the number of vertices, which corresponds to the dimension of the adjacency matrix.

operator[](int index) const: Facilitates easy access to adjacency list items, enabling read-only operations that are crucial for algorithms that should not modify the graph.

Algorithms Class:
The Algorithms class contains static methods, making them accessible without needing an object instance. This design choice emphasizes utility and functionality, as these methods operate universally on any Graph object passed to them.

Detailed Functionality
Connectivity (isConnected): Uses depth-first search (DFS) to check if all nodes are reachable from a given start node. For directed graphs, it additionally checks reachability in the transposed graph, ensuring strong connectivity.

Cycle Detection (findCycle): Employs DFS to explore the graph. It tracks nodes currently in the recursion stack to detect back edges, which indicate cycles.

Shortest Path (shortestPath): Determines the shortest path using BFS for unweighted graphs and Bellman-Ford for weighted graphs. This method is versatile, adapting to the nature of the graph to optimize the pathfinding process.

Bipartiteness (isBipartite): Uses a coloring algorithm to ensure no two adjacent nodes share the same color, which would violate bipartite conditions.

Negative Cycle Detection (negativeCycle): Implements the Bellman-Ford algorithm, checking for changes in the shortest path estimates after sufficient iterations to determine the presence of negative weight cycles.

Helper Functions:
Because we have to take in consideration that the graph has many options (weighted, unweighted, directed and undirected), I had to build a few helper functions to properly implement the main ones.

DFS : applies the depth-first search on the graph.

isWeighted : checks if graph is weighted.

bellman Ford : applies the bellman-ford algorithm while returning a signal if it found a negative cycle, if not returning the shortest path between two vertices.

BFS : applies the breadth-first search on the graph, returning the shortest path between two vertices if such exists.

findCycle : searches for a cycle in the graph (when it returns to a vertice that was already visited).

transpose : if the graph is directed, switches the direction of the edges.

isDirected : checks if the graph is directed (if the matrix is symmetrical or not).
