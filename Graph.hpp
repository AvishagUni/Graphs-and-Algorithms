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
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        std::string printGraph();
        [[nodiscard]] std::size_t size() const;
        const std::vector<int>& operator[](std::size_t index) const;  // Const overload for read-only access
    };
}

#endif
