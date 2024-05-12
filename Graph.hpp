#include <iostream>
#include <vector>

namespace ariel
{
    class Graph
    {
    private:
        std::vector<std::vector<int>> adjMatrix;
//        std::vector<std::vector<std::pair<int, int>>> adjList; // Adjacency list where each pair is (neighbor, weight)

    public:
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        std::string printGraph();
        [[nodiscard]] int size() const;
        const std::vector<int>& operator[](int index) const;  // Const overload for read-only access
    };
}