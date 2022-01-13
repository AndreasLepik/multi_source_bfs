#include "context.h"
#include "graph.h"

using namespace std;

Context::Context(string path, BFS *algorithm, int size) : pathToGraphFile(path), bfs(algorithm), graphSize(size){};

void Context::run(vector<int> sources)
{
  Graph graph{graphSize, pathToGraphFile};
  bfs->run(graph, sources);
}

void Context::setData(string path, int graphSize)
{
  this->pathToGraphFile = path;
  this->graphSize = graphSize;
}

void Context::setAlgorithm(BFS *algorithm)
{
  this->bfs = algorithm;
}
