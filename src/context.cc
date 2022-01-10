#include "context.h"
#include "graph.h"

using namespace std;

void Context::run()
{
  Graph graph {5};
  graph.loadGraphFromFile("../data_sets/test/out.test");

  bfs->run(graph);
}

void Context::setData(string path) {
  this->path = path;
}

void Context::setAlgorithm(BFS *algorithm) {
  this->bfs = algorithm;
}
