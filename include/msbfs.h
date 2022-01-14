#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include "bfs.h"

using namespace std;

class MSBFS : public BFS
{
  void run(Graph &graph, vector<int> sources)
  {
    cout << "Runnig MBFS..." << endl;

    // have to change to ordered set in order to do set difference?
    unordered_map<int, set<int>> seen(sources.size());
    // {(v => source)}
    unordered_multimap<int, set<int>> visit;
    unordered_multimap<int, set<int>> visitNext;
    set<int> visitKeys;
    set<int> visitNextKeys;

    for (auto source : sources)
    {
      seen.insert(make_pair(source, set<int>{source}));
      visit.insert(make_pair(source, set<int>{source}));
      visitKeys.insert(source);
    }

    while (visit.size() > 0)
    {
      for (auto v : visitKeys)
      {
        // cout << node.first << ", " << node.second << endl;
        set<int> neighbours;
        auto incomingNodes = visit.equal_range(v);
        for (auto n = incomingNodes.first; n != incomingNodes.second; ++n)
        {
          neighbours.merge(n->second);
        }

        for (auto n : graph.getEdges(v))
        {
          set<int> D;
          // set<int> D = neighbours \ seen.at(n);
          set_difference(neighbours.begin(),
                         neighbours.end(),
                         seen.at(n).begin(),
                         seen.at(n).end(),
                         D);
          if (D.size() > 0)
          {
            // seen.insert(n);
            // visitNext.push_back(n);

            cout << n << endl;
          }
        }
      }
      visit = visitNext;
      visitNext = {};
      cout << "+" << endl;
    }
  };
};