#include <iostream>
#include <queue>
#include "bfs.h"

using namespace std;

class TextBookBFS : public BFS
{
  void run(Graph &graph, vector<int> sources)
  {
    cout << "Runnig TBFS..." << endl;
    for (auto source : sources)
    {

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
        cout << "+" << endl;
      }
    }
  };
};