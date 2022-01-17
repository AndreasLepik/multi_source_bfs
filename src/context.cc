#include <ctime>
#include <iostream>
#include "context.h"
#include "graph.h"

using namespace std;

Context::Context(string path, int size, BFS *algorithm, bool timer)
    : bfs(algorithm), graph(Graph{size, path}), timer(timer){};

void Context::run(vector<int> sources)
{
  if (timer)
  {
    auto start = clock();
    bfs->run(graph, sources);
    auto end = clock();
    cout << "Time: " << (end - start) / (double)( CLOCKS_PER_SEC / 1000 ) << "ms" << endl;
  }
  else
  {
    bfs->run(graph, sources);
  }
}

void Context::setData(string path, int graphSize)
{
  this->graph = Graph{graphSize, path};
}

void Context::setTimer(bool timer)
{
  this->timer = timer;
}

void Context::setAlgorithm(BFS *algorithm)
{
  this->bfs = algorithm;
}
