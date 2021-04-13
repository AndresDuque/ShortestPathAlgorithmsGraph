//
// Created by andres on 12/04/2021.
//

#include "Graph.h"

#include <fstream>
#include <iostream>
#include <list>
#include <queue>

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
    std::set<std::string> vertices;

    while (infile >> src >> dest) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        m_edges.push_back(edge);
        vertices.insert(edge.src);
        vertices.insert(edge.dest);
    }
    m_number_vertices = vertices.size();
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

std::vector<std::string>
Graph::dijkstra(const std::string &src, const std::string &dest) {
    // Second arguments -> distances
    // Find the smallest distance in the already in closed list
    // and push it in -> previous
    std::unordered_map<std::string, int> distances;
    std::unordered_map<std::string, std::string> previous;

    std::vector<std::string> nodes; // Open list
    std::vector<std::string> path; // Closed list

    auto comparator = [&](std::string left, std::string right) {
        return distances[left] > distances[right];
    };

    for (auto &vertex : m_graph) {
        if (vertex.first == src) {
            distances[vertex.first] = 0;
        } else {
            distances[vertex.first] = std::numeric_limits<int>::max();
        }
        nodes.push_back(vertex.first);
        std::push_heap(std::begin(nodes), std::end(nodes), comparator);
    }

    while (!nodes.empty()) {
        std::pop_heap(std::begin(nodes), std::end(nodes), comparator);
        std::string smallest = nodes.back();
        nodes.pop_back();

        //std::cout << "Open list: ";
        //for (const auto &node : nodes) {
        //    std::cout << node << ' ';
        // }
        //std::cout << std::endl;

        if (smallest == dest) {
            while (previous.find(smallest) != end(previous)) {
                path.push_back(smallest);
                smallest = previous[smallest];
                //std::cout << "Closed list: ";
                //for (const auto &i : path) {
                //    std::cout << i << ' ';
                // }
                // std::cout << std::endl;
            }
            break;
        }
        if (distances[smallest] == std::numeric_limits<int>::max()) {
            break;
        }
        for (auto &neighbor : m_graph[smallest]) {
            int alt = distances[smallest] + neighbor.second;
            if (alt < distances[neighbor.first]) {
                distances[neighbor.first] = alt;
                previous[neighbor.first] = smallest;
                make_heap(begin(nodes), end(nodes), comparator);
            }
        }
    }
    return path;
}
