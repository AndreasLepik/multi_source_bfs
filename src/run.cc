#include <iostream>
#include "graph.h"

int main()
{
  std::cout << "hello world" << std::endl;

  Graph graph;
  graph.loadGraphFromFile();
  auto edges = graph.getEdges(1);
  for (auto edge : edges)
  {
    std::cout << edge << std::endl;
  }

  return 0;
}