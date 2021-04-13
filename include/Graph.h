//
// Created by andres on 12/04/2021.
//

#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <set>


// Data structure to store a graph edge
struct Edge {
    std::string src, dest;
    int weight = 1;
};

class Graph {
private:
    std::vector<Edge> m_edges;
    std::set<std::string> m_vertices;
    std::unordered_map<std::string, std::list<std::pair<std::string, int>>> m_graph;
public:
    Graph() = default;
    ~Graph() = default;
    void buildGraph(std::vector<Edge> const &edges);
    void readFile(const std::string &file);
    void printGraph();
    std::vector<Edge> getEdges() const;
    bool findIdSource(const std::string &src);
    bool findIdDestine(const std::string &dest);
    bool findId(const std::string &src, const std::string &dest);
    bool BFS(const std::string &src, const std::string &dest);
};