//
// Created by andres on 12/04/2021.
//

#include "Graph.h"

#include <fstream>
#include <iostream>
#include <list>
#include <queue>

/**
 * @name: buildGraph
 * @description Construye el grafo con los datos leidos del archivo de texto
 * @param edges
 */
void Graph::buildGraph(const std::vector<Edge> &edges) {
    // inserta el origen apuntando al destino y viceversa
    for (auto &edge: edges) {
        // insert at the end
        m_graph[edge.src].push_back(std::make_pair(edge.dest, edge.weight));
        // bidirectional relationship
        m_graph[edge.dest].push_back(std::make_pair(edge.src, edge.weight));
    }
}

/**
 * @name: readFile
 * @description Lee el archivo de texto, crea las relaciones entre los nodos y
 * los añade al vector.
 * @param file
 */
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

/**
 * @name: printGraph
 * @description Imprime el grafo
 */
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

/**
 * @name: getEdges
 * @description devuelve el vector de aristas
 */
std::vector<Edge> Graph::getEdges() const {
    return m_edges;
}

/**
 * @name: findIdSource
 * @description Devuelve true si encuentra el nodo origen
 * @params src
 */
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

/**
 * @name: findIdDestine
 * @description Devuelve true si encuentra el nodo destino
 * @params dest
 */
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

/**
 * @name: findIdSource
 * @description Devuelve true si encuentra los nodos introducidos por el
 * usuario, en caso contrario devuelve falso.
 * @params src
 */
bool Graph::findId(const std::string &src, const std::string &dest) {
    if (findIdSource(src) && findIdDestine(dest)) {
        return true;
    } else {
        return false;
    }
}

/**
 * @name dijkstra
 * @param src
 * @param dest
 * @description
 * Esta función implementa el algoritmo dijstra o tambien llamado
 * algoritmo de caminos minimos.
 * 1. Inicializa todas las distancias a un valor infinito relativo,
 * ya que son desconocidas al principio excepto el nodo actual puesto que
 * es el mismo nodo. (Llegar de nodo A a nodo A es 0).
 * 2. Se toma el nodo actual.
 * 3. Se recorren todos los nodos adyacentes del nodo actual, excepto los nodos
 * no marcados.
 * 4. Para el nodo actual se calcula la distancia tentantiva desde dicho
 * nodo hasta sus vecinos. La distancia tentativa del nodo A es la distancia que
 * actualmente tiene el nodo en el vector D más la distancia desde dicho nodo ‘a’
 * (el actual) hasta el nodo vi. Si la distancia tentativa es menor que la distancia
 * almacenada en el vector, entonces se actualiza el vector con esta distancia
 * tentativa.
 * 5. Se marca como completo el nodo a.
 * 6.Se toma como próximo nodo actual el de menor valor en D
 * (puede hacerse almacenando los valores en una cola de prioridad)
 * y se regresa al paso 3, mientras existan nodos no marcados.
 *
 * Una ves terminado el algoritmo, el hash map de distancias estara lleno.
 * @return Devuelve el camino de nodos desde src a dest.
 */
std::vector<std::string>
Graph::dijkstra(const std::string &src, const std::string &dest) {
    // Second arguments -> distances
    // Find the smallest distance in the already in closed list
    // and push it in -> previous
    std::unordered_map<std::string, int> distances;
    std::unordered_map<std::string, std::string> previous;

    std::vector<std::string> nodes; // Open list
    std::vector<std::string> path; // Closed list

    auto comparator = [&](const std::string& left, const std::string& right) {
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
