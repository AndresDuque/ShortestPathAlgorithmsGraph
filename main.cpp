#include <iostream>

#include "Graph.h"

int main(int argc, char *argv[]) {
    Graph graph;

    int seq = 0;

    graph.readFile(argv[1]);
    graph.buildGraph(graph.getEdges());
    graph.printGraph();

    std::string source, dest;
    std::cout << "Introduzca ID origen: ";
    std::cin >> source;
    std::cout << "Introduzca ID destino: ";
    std::cin >> dest;

    if (graph.findId(source, dest)) {
        for (auto &s : graph.dijkstra(source, dest)) {
            std::cout << "Solution path from goal sequence : " << seq
                      << " Node : " << s << std::endl;
            seq++;
        }
    }

    return 0;
}
