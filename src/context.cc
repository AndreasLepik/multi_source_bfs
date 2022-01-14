#include "context.h"
#include "graph.h"

using namespace std;

Context::Context(string path, int size, BFS *algorithm, bool timer)
    : bfs(algorithm), graph(Graph{size, path}), timer(timer){};

void Context::run(vector<int> sources)
{
  bfs->run(graph, sources);
}

void Context::setData(string path, int graphSize)
{
  this->graph = Graph{graphSize, path};
}

void Context::setAlgorithm(BFS *algorithm)
{
  this->bfs = algorithm;
}
