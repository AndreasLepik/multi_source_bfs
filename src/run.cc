#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
  Graph graph;
  graph.loadGraphFromFile("../data_sets/test/out.test");

  cout << endl;
  auto edges = graph.getEdges(1);
  for (auto edge : edges)
  {
    cout << edge << endl;
  }

  return 0;
}