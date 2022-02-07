#include <iostream>
#include <algorithm>
#include <set>
#include "bfs.h"

using namespace std;

class UnorderedMSBFS : public BFS
{
  vector<int> run(Graph &graph, vector<int> sources)
  {
    cout << "Runnig unordered MSBFS..." << endl;
    int numberOfCalculations = 0;
    vector<int> distanceSums = vector<int>(sources.size() + 1, 0);

    // have to use ordered set in order to do set difference?
    unordered_map<int, unordered_set<int>> seen(sources.size());
    unordered_multimap<int, unordered_set<int>> visit;
    unordered_multimap<int, unordered_set<int>> visitNext;
    unordered_set<int> visitKeys;
    unordered_set<int> visitNextKeys;

    int currentDepth = 1;

    for (auto source : sources)
    {
      seen.insert(make_pair(source, unordered_set<int>{source}));
      visit.insert(make_pair(source, unordered_set<int>{source}));
      visitKeys.insert(source);
    }

    while (visit.size() > 0)
    {
      for (auto v : visitKeys)
      {
        unordered_set<int> exploreNext;
        auto incomingNodes = visit.equal_range(v);
        for (auto n = incomingNodes.first; n != incomingNodes.second; ++n)
        {
          exploreNext.merge(n->second);
        }

        for (auto n : graph.getEdges(v))
        {
          unordered_set<int> D;
          auto nSeen = seen.find(n);
          if (nSeen == seen.end())
          {
            D = exploreNext;
          }
          else
          {
            for (auto nextNeighbour : exploreNext) {
              if (nSeen->second.find(nextNeighbour) == nSeen->second.end()) {
                D.insert(nextNeighbour);
              }
            }
          }
          // D = exploreNext \ seen.at(n);
          if (D.size() > 0)
          {
            // BFS calculation here before destructive merge function
            numberOfCalculations++;
            for (auto d : D)
            {
              distanceSums[d] = distanceSums[d] + currentDepth;
            }
            visitNext.insert(make_pair(n, D));
            visitNextKeys.insert(n);
            auto nSeen = seen.find(n);
            if (nSeen == seen.end())
            {
              seen.insert(make_pair(n, D));
            }
            else
            {
              seen.at(n).merge(D);
            }

            // cout << n << endl;
          }
        }
      }
      visit = move(visitNext);
      visitKeys = move(visitNextKeys);
      visitNext.clear();
      visitNextKeys.clear();
      // cout << "+" << endl;
    }
    // cout << "Number of calculations saved in MSBFS: " << numberOfCalculationsSaved << endl;
    return distanceSums;
  };
};