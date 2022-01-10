#include <iostream>
#include "bfs.h"

using namespace std;

class TextBookBFS : public BFS
{
  void run(Graph &graph)
  {
    auto edges = graph.getEdges(1);
    for (auto edge : edges)
    {
      cout << edge << endl;
    }
  };
};