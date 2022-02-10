#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include "bfs.h"

using namespace std;

/**
 * #################### Bitmapping Multi Source Breadth First Search ####################
 *
 * Functionally identical to MSBFS but using bitmaps instead of STL datastructures, so way faster.
 * As of now, limited to max 63 consurrent BFSs because of the register sizes.
 * Indexing from 1 since the data input does so.
 */
class BitmappingMSBFS : public BFS
{
  vector<int> run(Graph &graph, vector<int> sources)
  {
    cout << "Running Bitmapping MSBFS..." << endl;
    int numberOfCalculations = 0;
    vector<int> distanceSums = vector<int>(sources.size() + 1, 0);

    vector<u_int64_t> seen(graph.getSize() + 1, 0);
    vector<u_int64_t> visit(graph.getSize() + 1, 0);
    vector<u_int64_t> visitNext(graph.getSize() + 1, 0);

    int currentDepth = 1;

    // Add starting points to seen and visit.
    for (int i = 0; i < sources.size(); ++i)
    {
      u_int64_t shifted = (u_int64_t) 1 << i;
      seen[sources[i]] = seen[sources[i]] | shifted;
      visit[sources[i]] = visit[sources[i]] | shifted;
    }

    // while v != 0 for ALL v in visit
    while (find_if(begin(visit), end(visit), [](u_int64_t a)
                   { return a > 0; }) != end(visit))
    {
      for (int i = 1; i <= graph.getSize(); ++i)
      {
        if (visit.at( i ) != 0)
        {
          for (auto n : graph.getEdges(i))
          {
            // the set of BFSs that have not yet visited n
            auto D = visit.at( i ) & ~(seen.at( n ));
            if (D != 0)
            {
              visitNext.at( n ) = visitNext.at( n ) | D;
              seen.at( n ) = seen.at( n ) | D;

              // do actual BFS calculation here
              numberOfCalculations++;
              int j = 0;
              while (D > 0)
              {
                if (D & 1 == 1)
                {
                  distanceSums.at( j ) = distanceSums.at( j ) + currentDepth;
                }
                // cout << D << endl;
                D = D >> 1;
                j++;
              }
            }
          }
        }
      }
      visit = move(visitNext);
      visitNext = vector<u_int64_t>(graph.getSize() + 1, 0);
      // cout << "+" << endl;
      currentDepth++;
    }
    cout << "Number of calculations in bitwise MSBFS: " << numberOfCalculations << endl;
    return distanceSums;
  };
};