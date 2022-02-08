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
      seen[sources[i]] = seen[sources[i]] | (1 << i);
      visit[sources[i]] = visit[sources[i]] | (1 << i);
    }

    // while v != 0 for ALL v in visit
    while (find_if(begin(visit), end(visit), [](u_int64_t a)
                   { return a > 0; }) != end(visit))
    {
      for (int i = 1; i <= graph.getSize(); ++i)
      {
        if (visit[i] != 0)
        {
          for (auto n : graph.getEdges(i))
          {
            // the set of BFSs that have not yet visited n
            auto D = visit[i] & ~(seen[n]);
            if (D != 0)
            {
              // auto numberOfBfs = count_set_bit(D);
              // numberOfCalculationsSaved += (numberOfBfs - 1);

              visitNext[n] = visitNext[n] | D;
              seen[n] = seen[n] | D;

              // do actual BFS calculation here
              numberOfCalculations++;
              for (int j = 1; j <= sources.size(); ++j)
              {
                if (D & 1 == 1)
                {
                  distanceSums[j] = distanceSums[j] + currentDepth;
                }
                D = D >> 1;
              }
              // cout << n << endl;
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
    // for (auto d : distanceSums)
    // {
    //   cout << d << endl;
    // }
    // cout << endl;
    return distanceSums;
  };
};

int count_set_bit(int n)
{
  int count = 0;
  while (n != 0)
  {
    if (n & 1 == 1)
    {
      count++;
    }
    n = n >> 1; // right shift 1 bit
  }
  return count;
}