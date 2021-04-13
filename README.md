# The shortest path algorithms.

![workflow](https://github.com/AndresDuque/ShortestPathAlgorithmsGraph/actions/workflows/graph.yml/badge.svg)


### Graph

Graph implements the Dijkstra's algorithm to find the shortest path given two
vertices in a graph.
Graph is implemented with an unordered_map.

## Usage

### Prerequisites

You will need:

* A modern C/C++ compiler
* CMake 3.1+ installed (on a Mac, run `brew install cmake`)
* If you prefer to code in a great IDE, I highly recommend [Jetbrains CLion](https://www.jetbrains.com/clion/). It is fully compatible with this project.

### Building The Project

#### Git Clone

First we need to check out the git repo:

```bash
❯ mkdir ~/workspace
❯ cd ~/workspace
❯ git clone \
    https://github.com/AndresDuque/ShortestPathAlgorithmsGraph \
    Graph
❯ cd Graph
❯ bash build-and-run
```

The output of this script is rather long and is shown [on this screenshot](doc/build-and-run.png).

The script `build-and-run` is a short-cut — you shouldn't really be using this script to build your project, but see how to do it properly below.

#### Project Structure

There are three empty folders: `lib`, `bin`, and `include`. Those are populated by `make install`.

The rest should be obvious: `src` is the sources, and `test` is where we put our unit tests.

Now we can build this project, and below we show three separate ways to do so.

#### Building Manually

```bash
❯ cd Graph
❯ mkdir build
❯ cd build
❯ cmake ..
❯ make -j
❯ cd ..
```

### Using it as a C++ Library

Graph is built as a shared library that, given a graph returns the shortest path between two given nodes.

We can use it from C++ like so:

```cpp
#include <iostream>
#include "Graph.h"

Graph graph;

int seq = 0; // variable to see 

graph.readFile(argv[1]); // redes.txt file example
graph.buildGraph(graph.getEdges());
graph.printGraph(); // to see connections between nodes.

std::string source, dest;
std::cout << "Introduce source node: ";
std::cin >> source;
std::cout << "Introduce destine node: ";
std::cin >> dest;


```

## File Locations

* `src/*` — C++ code that ultimately compiles into a library.
* `include/*` — header files.

