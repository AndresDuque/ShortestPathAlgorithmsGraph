//
// Created by andres on 12/04/2021.
//

#include "Graph.h"

#include <fstream>
#include <iostream>
#include <list>

void Graph::buildGraph(const std::vector<Edge> &edges) {
    // add edges to the directed graph
    for (auto &edge: edges) {
        // insert at the end
        m_graph[edge.src].push_back(std::make_pair(edge.dest, edge.weight));
        // bidirectional relationship
        //m_graph[edge.dest].push_back(std::make_pair(edge.src, edge.weight));
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
        m_vertices.insert(edge.src);
        m_vertices.insert(edge.dest);
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

bool Graph::findIdSource(const std::string &src) {
    bool res = false;
    auto search = m_graph.find(src);
    if (search != m_graph.end()) {
        //std::cout << "Found " << search->first << std::endl;
        //std::cout << "Origen: " << search->first << std::endl;
        res = true;
    }
    return res;
}

bool Graph::findIdDestine(const std::string &dest) {
    bool res = false;
    auto search = m_graph.find(dest);
    if (search != m_graph.end()) {
        //std::cout << "Found " << search->first << std::endl;
        //std::cout << "Origen: " << search->first << std::endl;
        res = true;
    }
    return res;
}

// Para poder ejecutar la busqueda se tienen que encontrar los dos nodos
// del grafo
bool Graph::findId(const std::string &src, const std::string &dest) {
    if (findIdSource(src) && findIdDestine(dest)) {
        return true;
    } else {
        return false;
    }
}

bool Graph::BFS(const std::string &src, const std::string &dest) {
    int result = 0;


    return result;
}
