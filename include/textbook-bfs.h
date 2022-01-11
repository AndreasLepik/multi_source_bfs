#include <iostream>
#include <queue>
#include "bfs.h"

using namespace std;

class TextBookBFS : public BFS
{
  void run(Graph &graph, vector<int> sources)
  {
    int source = sources[0];

    unordered_set<int> seen{source};
    vector<int> visit{source};
    vector<int> visitNext;
    // visit.push(source);

    while (visit.size() > 0)
    {
      for (auto v : visit)
      {
        for (auto n : graph.getEdges(v))
        {
          if (seen.count(n) == 0)
          {
            seen.insert(n);
            visitNext.push_back(n);

            cout << n << endl;
          }
        }
      }
      visit = visitNext;
      visitNext = {};
      cout << endl;
    }
  };
};