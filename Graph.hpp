// Avishag Minnes
// 213080088
// minnesav@gmail.com

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

namespace ariel
{
    class Graph
    {
   private:
       std::vector<std::vector<int>> adjMatrix;
    public:
        // memeber functions
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        std::string printGraph() const;
        std::size_t size() const;
        int edgeCount() const;

        // operators
        const std::vector<int>& operator[](std::size_t index) const;  // Const overload for read-only access
    };
} // namespace ariel

#endif // GRAPH_H
