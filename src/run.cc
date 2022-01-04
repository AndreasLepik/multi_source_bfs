#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
  Graph graph {5};
  graph.loadGraphFromFile("../data_sets/test/out.test");

  auto edges = graph.getEdges(4);
  for (auto edge : edges)
  {
    cout << edge << endl;
  }

  return 0;
}