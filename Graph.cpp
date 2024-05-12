// Avishag Minnes
// 213080088
// minnesav@gmail.com

#include "Graph.hpp"
#include <cstddef>

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

    for (std::size_t i = 0; i < vertices; ++i) {
        for (std::size_t j = i; j < vertices; ++j) { // Start from 'i' to count each edge once
            if (this->adjMatrix[i][j] != 0) {
                edges++;
            }
        }
    }

    std::string result = "Graph with " + std::to_string(vertices) + " vertices and " + std::to_string(edges) + " edges.\n";
    std::cout << result;
    return result;    
}

std::size_t ariel::Graph::size() const
{
    return this->adjMatrix.size();
}

const std::vector<int>& ariel::Graph::operator[](std::size_t index) const
{
    return adjMatrix[index];
}// Const overload for read-only access




