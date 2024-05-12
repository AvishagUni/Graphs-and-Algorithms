#include "doctest.h"
#include "Algorithms.hpp"
//#include "Graph.hpp"

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
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

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
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

// Test the loading and integrity of the graph
TEST_CASE("Test LoadGraph") {
ariel::Graph g;
std::vector<std::vector<int>> matrix = {{0, 1}, {1, 0}};
g.loadGraph(matrix);
CHECK((g.size() == 2));
}

// Test print functionality by checking output consistency
TEST_CASE("Test Print") {
    ariel::Graph g;
g.loadGraph({{0, 2}, {2, 0}});
//testing::internal::CaptureStdout();
CHECK((g.printGraph() == "Graph with 2 vertices and 1 edges.\n"));
}

// Verify graph size reporting
TEST_CASE("Test GraphSize") {
    ariel::Graph g;
g.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}});
    CHECK((g.size() == 3));
}

// Test access operator functionality
TEST_CASE("Test AccessOperator") {
    ariel::Graph g;
g.loadGraph({{0, 1}, {1, 0}});
    CHECK((g[0][1] == 1));
}

// Connectivity tests
TEST_CASE("Test GraphConnectivity") {
    ariel::Graph g;
g.loadGraph({{0, 1}, {1, 0}});
    CHECK(((ariel::Algorithms::isConnected(g))==true));
}

TEST_CASE("Test GraphConnectivity") {
    ariel::Graph g;
g.loadGraph({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});
    CHECK(((ariel::Algorithms::isConnected(g))==false));
}

// Directed graph detection
TEST_CASE("Test DirectedGraph") {
    ariel::Graph g;
    g.loadGraph({{0, 1}, {0, 0}});
    CHECK(((ariel::Algorithms::isDirected(g))==true));
}


// Check if graph is undirected
TEST_CASE("Test DirectedGraph") {
    ariel::Graph g;
    g.loadGraph({{0, 1},
                 {1, 0}});
    CHECK(((ariel::Algorithms::isDirected(g)) == false));
}

// Testing for cycles
TEST_CASE("Test ContainsCycle") {
    ariel::Graph g;
    g.loadGraph({{0, 1}, {1, 0}});
    CHECK(((ariel::Algorithms::isContainsCycle(g)) == true));
}

TEST_CASE("Test NoCycle") {
    ariel::Graph g;
    g.loadGraph({{0, 1}, {0, 0}});
    CHECK(((ariel::Algorithms::isContainsCycle(g)) == false));
}

// Testing bipartite
TEST_CASE("Test IsBipartite") {
    ariel::Graph g;
    g.loadGraph({{0, 1}, {1, 0}});
    CHECK(((ariel::Algorithms::isBipartite(g)) == "The graph is bipartite: A={0}, B={1}.\n"));
}

TEST_CASE("Test IsNotBipartite") {
    ariel::Graph g;
    g.loadGraph({{0, 1, 1}, {1, 0, 0}, {1, 0, 0}});
    CHECK(((ariel::Algorithms::isBipartite(g)) == "0"));
}

// Test shortest path unweighted
TEST_CASE("Test ShortestPathUnweighted") {
    ariel::Graph g;
    g.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}});
    CHECK(((ariel::Algorithms::shortestPath(g, 0, 2)) == "0 -> 1 -> 2\n"));
}

// Test shortest path weighted
TEST_CASE("Test ShortestPathWeighted") {
    ariel::Graph g;
    g.loadGraph({{0, 2, 0}, {2, 0, 3}, {0, 3, 0}});
    CHECK(((ariel::Algorithms::shortestPath(g, 0, 2)) == "0 -> 1 -> 2\n"));
}

// Negative cycle detection
TEST_CASE("Test NegativeCycle") {
    ariel::Graph g;
    g.loadGraph({{0, 1, 2}, {1, 0, -3}, {2, 3, 0}});
    CHECK(((ariel::Algorithms::negativeCycle(g)) == "1 -> 2\n"));
}

TEST_CASE("Test NoNegativeCycle") {
    ariel::Graph g;
    g.loadGraph({{0, 1}, {1, 0}});
    CHECK(((ariel::Algorithms::negativeCycle(g)) == "No negative weight cycle found."));
}

TEST_CASE("Test CorrectEdgeCount") {
    ariel::Graph g;
    g.loadGraph({{0, 1, 0}, {1, 0, 2}, {0, 2, 0}});
    CHECK((g.printGraph() == "Graph with 3 vertices and 2 edges.\n"));
}

TEST_CASE("Test NonSquareMatrixRejection") {
    ariel::Graph g;
    std::vector<std::vector<int>> nonSquareMatrix = {{0, 1}, {1, 0}, {0, 1}};
    CHECK_THROWS(g.loadGraph(nonSquareMatrix));
}

TEST_CASE("Test GraphTransposeCorrectness") {
    ariel::Graph g;
    g.loadGraph({{0, 1}, {0, 0}});
    ariel::Graph transposed = ariel::Algorithms::transpose(g);
    CHECK((g[0][1] == 0));
    CHECK((g[1][0] == 1));
}

TEST_CASE("Test DisconnectedGraphHandling") {
    ariel::Graph g;
    g.loadGraph({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});
    CHECK(((ariel::Algorithms::isConnected(g))==false));
}




