//
// Created by andres on 12/04/2021.
//

#include "Graph.h"
#include <fstream>
#include <iostream>


void Graph::buildGraph(const std::vector<Edge> &edges) {
    // add edges to the directed graph
    for (auto &edge: edges) {
        // insert at the end
        m_graph[edge.src].push_back(std::make_pair(edge.dest, edge.weight));
        // bidirectional relationship
        m_graph[edge.dest].push_back(std::make_pair(edge.src, edge.weight));
    }
}

void Graph::readFile(const std::string &file) {
    std::string src, dest;
    std::ifstream infile(file);
    while (infile >> src >> dest) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        m_edges.push_back(edge);
    }
}

void Graph::printGraph() {
    for (auto &i : m_graph) {
        std::string src = i.first;
        auto list = i.second;
        auto itr = list.begin();
        std::cout << "Graph[" << src << "]";
        while (itr != list.end()) {
            std::cout << " -> " << (*itr).first << " (" << (*itr).second << ")";
            ++itr;
        }
        std::cout << std::endl;
    }
}

std::vector<Edge> Graph::getEdges() const {
    return m_edges;
}

int Graph::getShortestPath(const std::string &src, const std::string &dest) {

    return 0;
}

bool Graph::findID(const std::string &src, const std::string &dest) {
    auto search1 = m_graph.find(src);
    auto search2 = m_graph.find(dest);
    if (search1 != m_graph.end() || search2 != m_graph.end()) {
        std::cout << "Found " << search1->first  << std::endl;
        auto itr = search1->second.begin();
        auto list = search1->second;
        while (itr != list.end()) {
            bool found = search1->first ==(*itr).first;
            ++itr;
        }

    } else {
        std::cout << "Not found\n";
    }

    return false;
}
