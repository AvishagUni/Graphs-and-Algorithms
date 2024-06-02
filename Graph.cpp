// Avishag Minnes
// 213080088
// minnesav@gmail.com

#include "Graph.hpp"
#include <cstddef>
#include <sstream> // Include the necessary header file


using namespace std;

namespace ariel
{

// loads the graph from a given matrix
void ariel::Graph::loadGraph(const std::vector<std::vector<int>>& matrix)
{
    if(matrix.empty()) {
        throw invalid_argument("Invalid graph: The graph is empty.\n");
    }
    int numRows = matrix.size();
    // Check if the matrix is square
    for (const auto& row : matrix) {
        if (row.size() != numRows) {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.\n");
        }
    }
    this->adjMatrix = matrix;
}

// prints the graph
std::string ariel::Graph::printGraph() const
{
    std::ostringstream result;
    for (size_t i = 0; i < adjMatrix.size(); i++) {
        result << "[";
        for (size_t j = 0; j < adjMatrix.size(); j++) {
            result << adjMatrix[i][j];
            if (j != adjMatrix[i].size() - 1) {
                result << ", ";
            }
        }
        result << "]\n";
    }
    std::cout << result.str();
    return result.str();
}

// returns the size of the graph
std::size_t ariel::Graph::size() const
{
    return this->adjMatrix.size();
}

// returns the number of edges in the graph
int ariel::Graph::edgeCount() const {
    int count = 0;
    for (size_t i = 0; i < this->size(); i++) {
        for (size_t j = 0; j < this->size(); j++) {
            if (this->adjMatrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

// returns a specific cell in the matrix
const std::vector<int>& ariel::Graph::operator[](std::size_t index) const
{
    return this->adjMatrix[index];
}// Const overload for read-only access

ariel::Graph ariel::Graph::operator+(const ariel::Graph& g) const {
    if(this->size()!=g.size()) {
        throw invalid_argument("Graphs are not the same size.\n");
    }
    size_t size = this->size();
    std::vector<std::vector<int>> mat(size, std::vector<int>(size, 0));
    for(size_t i =0; i<size; i++) {
        for(size_t j=0; j<size; j++) {
            mat[i][j] = this->adjMatrix[i][j] + g.adjMatrix[i][j];
        }
    }
    Graph c;
    c.loadGraph(mat);
    return c;




