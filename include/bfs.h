#ifndef BFS_H
#define BFS_H

#include "graph.h"

/**
 * Interface for BFS algorithms.
 */
class BFS
{
public:
  virtual ~BFS() {};
  virtual void run(Graph &graph, vector<int> sources) = 0;
};

#endif