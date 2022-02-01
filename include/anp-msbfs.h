#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include "bfs.h"

using namespace std;

/**
 * #################### Aggregated Neighbor Processing Multi Source Breadth First Search ####################
 *
 * MSBFS with aggregated neighbor processing optimization.
 * Further reduces the amount of BFS computation calls and and the amount of random memory accesses.
 * Using the same bitmapping optimizations as bitmapping-msbfs.
 * As of now, limited to max 63 consurrent BFSs because of the register sizes.
 */
class ANP_MSBFS : public BFS
{
  void run(Graph &graph, vector<int> sources)
  {
    cout << "Runnig ANP MSBFS..." << endl;
    // int numberOfCalculationsSaved = 0;

    vector<u_int64_t> seen(graph.getSize() + 1, 0);
    vector<u_int64_t> visit(graph.getSize() + 1, 0);
    vector<u_int64_t> visitNext(graph.getSize() + 1, 0);

    // Add starting points to seen and visit.
    for (int i = 0; i < sources.size(); ++i)
    {
      seen.at(sources.at(i)) = seen.at(sources.at(i)) | (1 << i);
      visit.at(sources.at(i)) = visit.at(sources.at(i)) | (1 << i);
    }

    // while v != 0 for ALL v in visit
    while (find_if(begin(visit), end(visit), [](u_int64_t a)
                   { return a > 0; }) != end(visit))
    {
      for (int i = 1; i <= graph.getSize(); ++i)
      {
        if (visit.at(i) != 0)
        {
          for (auto n : graph.getEdges(i))
          {
            visitNext.at(n) = visitNext.at(n) | visit.at(i);
          }
        }
      }

      for (int i = 1; i <= graph.getSize(); ++i)
      {
        if (visitNext.at(i) != 0)
        {
          visitNext.at(i) = visitNext.at(i) & ~(seen.at(i));
          seen.at(i) = seen.at(i) | visitNext.at(i);

          if (visitNext.at(i) != 0)
          {
              // do actual BFS calculation here
              // cout << i << endl;
          }
        }
      }

      visit = move(visitNext);
      visitNext = vector<u_int64_t>(graph.getSize() + 1, 0);
      // cout << "+" << endl;
    }
    // cout << "Number of calculations saved in bitwise MSBFS: " << numberOfCalculationsSaved << endl;
  };
};

// int count_set_bit(int n)
// {
//   int count = 0;
//   while (n != 0)
//   {
//     if (n & 1 == 1)
//     {
//       count++;
//     }
//     n = n >> 1; // right shift 1 bit
//   }
//   return count;
// }