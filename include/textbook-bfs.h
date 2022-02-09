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
  vector<int> run(Graph &graph, vector<int> sources)
  {
    cout << "Running TBFS..." << endl;

    int numberOfCalculations = 0;
    vector<int> distanceSums = vector<int>(sources.size() + 1, 0);
    
    for (int i = 0; i < sources.size(); ++i)
    {
      auto source = sources[i];
      unordered_set<int> seen{source};
      vector<int> visit{source};
      vector<int> visitNext;

      int currentDepth = 1;

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
              distanceSums[i] = distanceSums[i] + currentDepth;
              // cout << n << endl;
            }
          }
        }
        visit = move(visitNext);
        visitNext.clear();
        // cout << "+" << endl;
        currentDepth++;
      }
    }
    cout << "Number of calculations in TBFS: " << numberOfCalculations << endl;
    // for (auto d : distanceSums) {
    //   cout << d << endl;
    // }
    return distanceSums;
  };
};