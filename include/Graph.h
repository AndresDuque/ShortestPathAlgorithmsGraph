//
// Created by andres on 12/04/2021.
//

#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <list>

// Data structure to store a graph edge
struct Edge {
    std::string src, dest;
    int weight = 1;
};

class Graph {
private:
    std::vector<Edge> m_edges;
    std::unordered_map<std::string, std::list<std::pair<std::string, int>>> m_graph;
public:
    Graph() = default;

    ~Graph() = default;

    void buildGraph(std::vector<Edge> const &edges);

    void readFile(const std::string &file);

    void printGraph();

    std::vector<Edge> getEdges() const;

    int getShortestPath(const std::string &src, const std::string &dest);

    bool findID(const std::string &src, const std::string &dest);
};