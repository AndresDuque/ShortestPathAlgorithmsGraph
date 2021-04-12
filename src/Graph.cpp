//
// Created by andres on 12/04/2021.
//

#include "Graph.h"
#include <fstream>
#include <iostream>



void Graph::buildGraph(const std::vector<Edge> &edges) {
    // add edges to the directed graph
    for (auto &edge: edges)
    {
        // insert at the end
        m_graph[edge.src].push_back(std::make_pair(edge.dest,edge.weight));

    }
}

void Graph::readFile(const std::string &file) {
    std::string src, dest;
    std::ifstream infile(file);
    while(infile >> src >> dest){
        Edge edge;
        edge.src = src;
        edge.dest =dest;
        m_edges.push_back(edge);
    }
}
void Graph::printGraph(){
    for (auto &i : m_graph){
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
