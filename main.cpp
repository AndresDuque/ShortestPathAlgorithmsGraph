#include <iostream>

#include "Graph.h"

int main(int argc, char *argv[]) {
    Graph graph;

    int seq = 0;

    graph.readFile(argv[1]);
    graph.buildGraph(graph.getEdges());
    //graph.printGraph();

    std::string source, dest;
    std::cout << "Introduzca ID origen: ";
    std::cin >> source;
    std::cout << "Introduzca ID destino: ";
    std::cin >> dest;

    if (graph.findId(source, dest)) {
        for (auto &s : graph.dijkstra(source, dest)) {
            seq++;
        }
    } else{
        std::cout << "Origen o destino no existe en el grafo." << std::endl;
    }

    if(seq==0){
        std::cout << "No existe camino." << std::endl;
    }else{
        std::cout << "Longitud camino: " << seq << std::endl;
    }

    return 0;
}
