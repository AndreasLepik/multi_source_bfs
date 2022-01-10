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
  virtual void run(Graph &graph) = 0;
};

#endif