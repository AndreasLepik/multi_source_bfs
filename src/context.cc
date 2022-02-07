#include <ctime>
#include <iostream>
#include "context.h"
#include "graph.h"

using namespace std;

Context::Context(string path, int size, BFS *algorithm, vector<int> sources, bool timer)
    : bfs(algorithm), graph(Graph{size, path}), sources(sources), timer(timer){};

vector<int> Context::run()
{
  if (timer)
  {
    auto start = clock();
    auto res = bfs->run(graph, sources);
    auto end = clock();
    cout << "Time: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << "ms" << endl;
    return res;
  }
  else
  {
    return bfs->run(graph, sources);
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

void Context::setSources(vector<int> sources)
{
  this->sources = sources;
}

vector<int> Context::getDegreeSortedNodes()
{
  return graph.getDegreeSortedNodes();
}