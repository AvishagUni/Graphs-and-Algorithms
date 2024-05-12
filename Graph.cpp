#include "Graph.hpp"

void ariel::Graph::loadGraph(const std::vector<std::vector<int>>& matrix)
{
    int numRows = matrix.size();
    // Check if the matrix is square
    for (const auto& row : matrix) {
        if (row.size() != numRows) {
            std::cerr << "Invalid graph: The graph is not a square matrix.\n" << std::endl;
            return;
        }
    }
    adjMatrix = matrix;
}

std::string ariel::Graph::printGraph()
{
    int vertices = this->adjMatrix.size();
    int edges = 0;

    for (int i = 0; i < vertices; ++i) {
        for (int j = i; j < vertices; ++j) { // Start from 'i' to count each edge once
            if (this->adjMatrix[i][j] != 0) {
                edges++;
            }
        }
    }

    std::string result = "Graph with " + std::to_string(vertices) + " vertices and " + std::to_string(edges) + " edges.\n";
    return result;    std::cout << "Graph with " << vertices << " vertices and " << edges << " edges." << std::endl;
}

int ariel::Graph::size() const
{
    return this->adjMatrix.size();
}

const std::vector<int>& ariel::Graph::operator[](int index) const
{
    return adjMatrix[index];
}// Const overload for read-only access





