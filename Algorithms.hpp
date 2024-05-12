// Algorithms.hpp
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.hpp"


namespace ariel
{
    class Algorithms
    {
    private:
        static void DFS(int v, std::vector<bool>& visited, const ariel::Graph& g);
        static bool isWeighted(ariel::Graph& g);
        static std::string bellmanFord(ariel::Graph& g, int src, int dest);
        static std::string BFS(ariel::Graph& g, int src, int dest);
        static bool findCycle(ariel::Graph& g, int v, std::vector<bool>& visited, std::vector<bool>& recStack, std::vector<int>& parent);
    public:
        static ariel::Graph transpose(ariel::Graph& g);
        static bool isDirected(const ariel::Graph& g);
        static bool isConnected(ariel::Graph& g);
        static std::string shortestPath(ariel::Graph& g, int start, int end);
        static bool isContainsCycle(ariel::Graph& g);
        static std::string isBipartite(ariel::Graph& g);
        static std::string negativeCycle(ariel::Graph& g);
    };
}

#endif