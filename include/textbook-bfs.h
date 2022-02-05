#include <iostream>
#include <queue>
#include "bfs.h"

using namespace std;

/**
 * #################### Textbook Breadth First Search ####################
 * 
 * The classic unmodified version.
 * If multiple sources, it just runs one the other.
 */
class TextBookBFS : public BFS
{
  void run(Graph &graph, vector<int> sources)
  {
    cout << "Running TBFS..." << endl;

    int numberOfCalculations = 0;
    for (auto source : sources)
    {

      unordered_set<int> seen{source};
      vector<int> visit{source};
      vector<int> visitNext;

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

              // do actual BFS calculation here
              numberOfCalculations++;
              // cout << n << endl;
            }
          }
        }
        visit = move(visitNext);
        visitNext.clear();
        // cout << "+" << endl;
      }
    }
    cout << "Number of calculations in TBFS: " << numberOfCalculations << endl;
  };
};