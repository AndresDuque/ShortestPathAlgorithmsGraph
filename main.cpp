#include <iostream>

#include "Graph.h"

int main(int argc, char *argv[]){
    Graph graph;

    graph.readFile(argv[1]);
    graph.buildGraph(graph.getEdges());
    graph.printGraph();

    std::string source, dest;
    std::cout << "Introduzca ID origen: ";
    std::cin >> source;
    std::cout << "Introduzca ID destino: ";
    std::cin >> dest;

    graph.findID(source,dest);

    return 0;
}
