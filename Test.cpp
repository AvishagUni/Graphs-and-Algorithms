// Avishag Minnes
// 213080088
// minnesav@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include <sstream>

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK((ariel::Algorithms::isConnected(g) == true));

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK((ariel::Algorithms::isConnected(g) == false));

    // weighted directed graph
    vector<vector<int>> graph3 = {
        {0, 3, 5},
        {6, 0, 4},
        {2, 1, 0}};
    g.loadGraph(graph3);
    CHECK((ariel::Algorithms::isConnected(g) == true));

    // weighted undirected graph
    vector<vector<int>> graph4 = {
        {0, 6, 8, 0},
        {6, 0, 5, 3},
        {8, 0, 5, 7},
        {0, 3, 7, 0}};
    g.loadGraph(graph4);
    CHECK((ariel::Algorithms::isConnected(g) == true));

    // unconnected weighted undirected graph
    vector<vector<int>> graph5 = {
        {0, 4, 3, 0, 0},
        {4, 0, 0, 0, 0},
        {3, 0, 0, 0, 0},
        {0, 0, 0, 0, 6},
        {0, 0, 0, 6, 0}};
    g.loadGraph(graph5);
    CHECK((ariel::Algorithms::isConnected(g) == false));
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    // weighted directed graph
    vector<vector<int>> graph3 = {
        {0, 2, 5, 0, 0},
        {0, 0, 1, 4, 0},
        {0, 0, 0, 1, 7},
        {0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->1->2->3->4");

    // weighted undirected graph
    vector<vector<int>> graph4 = {
        {0, 2, 5, 0, 0},
        {2, 0, 1, 4, 0},
        {5, 1, 0, 1, 7},
        {0, 4, 1, 0, 3},
        {0, 0, 7, 3, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 2) == "1->2");

    // unconnected unweighted directed graph
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");

    // connected weighted undirected graph 
    vector<vector<int>> graph6 = {
        {0, 3, 6, 0, 0},
        {3, 0, 2, 4, 0},
        {6, 2, 0, 0, 5},
        {0, 4, 0, 0, 1},
        {0, 0, 5, 1, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 4) == "1->3->4");
}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK((ariel::Algorithms::isContainsCycle(g) == false));

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK((ariel::Algorithms::isContainsCycle(g) == true));

    // No cycle in weighted directed graph
    vector<vector<int>> graph3 = {
        {0, 3, 2, 0, 0},
        {0, 0, 0, 4, 0},
        {0, 0, 0, 1, 3},
        {0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK((ariel::Algorithms::isContainsCycle(g) == false));

    // Cycle in weighted undirected graph
    vector<vector<int>> graph4 = {
        {0, 3, 0, 0},
        {0, 0, 4, 0},
        {5, 0, 0, 2},
        {0, 1, 0, 0}};
    g.loadGraph(graph4);
    CHECK((ariel::Algorithms::isContainsCycle(g) == true));

    // cycle in unconnected unweighted directed graph
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    g.loadGraph(graph5);
    CHECK((ariel::Algorithms::isContainsCycle(g) == true));
} 

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}.");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // bipartite graph with disconnected components
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3, 5}.");

    // bipartite graph with even number of vertices
    vector<vector<int>> graph5 = {
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 2}, B={3, 4, 5}.");
}

TEST_CASE("Test negativeCycle") {
    ariel::Graph g;

    // no negative cycle in unweighted undirected graph
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph is not weighted.");

    // no negative cycle in weighted directed graph
    vector<vector<int>> graph2 = {
        {0, 2, 4, 5},
        {0, 0, 1, 0},
        {0, 0, 0, 3},
        {0, 2, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative weight cycle found.");

    // negative cycle in weighted directed graph
    vector<vector<int>> graph3 = {
        {0, 1, 0, 2},
        {0, 0, -1, 0},
        {0, 0, 0, -1},
        {0, -1, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative weight cycle found: 1->2->3->1.");

    // negative cycle in weighted undirected graph
    vector<vector<int>> graph4 = {
        {0, -1, 0, 0},
        {0, 0, -2, 0},
        {0, 0, 0, -3},
        {-4, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative weight cycle found: 1->2->3->0->1.");

    vector<vector<int>> graph5 = {
        {0, -1, 0, 0},
        {0, 0, -2, 0},
        {-5, 0, 0, 0},
        {0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative weight cycle found: 0->1->2->0.");
}

TEST_CASE("Test invalid graph") {
    ariel::Graph g;

    // not square matrix
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1}};
    CHECK_THROWS(g.loadGraph(graph));
}



