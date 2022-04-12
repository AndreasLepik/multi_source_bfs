# Multi Source Breadth First Search Project
This is a project exploring different variants of Multi Source Breadth First Search Algorithms based on [this paper](https://db.in.tum.de/~kaufmann/papers/msbfs.pdf). 

The goal of the MSBFS algorithm is to improve graph traversal from multiple sources, in particular on small world networks. This is done by runnig multiple BFS algorithms at the same time and by utilising the fact that they will have considerable overlap in the nodes that they cover.

[This data set](http://konect.cc/networks/wikipedia_link_eu/) was used to test the algorithms, containing 371,025 nodes and 8,985,762 edges.

## Algorithm variants
- [Textbook BFS](include/textbook-bfs.h) is the classical Breadth First Search algorithm as it is often teached in textbooks.
- [Multi Source BFS](include/msbfs.h) is a naive implementation of the MSBFS algorithm using STL data structures.
- [Bitmapping MSBFS](include/bitmapping-msbfs.h) is the same algorithm but implemented with bitmapping data structures, making it _a lot_ faster.
- [ANP MSBFS](include/anp-msbfs.h) is a version of the bitmapping MSBFS utilizing the so called Aggregated Neighbour Processing optimization.

## Project overview
- [The graph class](include/graph.h) is used to load data and to host the graph.
- [The context class](include/context.h) is used as a connecting layer between the data, the algorithms and the tests.
- [The main class](src/main.cc) is where the experimental setup is defined and launched.
