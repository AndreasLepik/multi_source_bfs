#ifndef BFS_H
#define BFS_H

#include "graph.h"

/**
 * Interface for BFS algorithms.
 */
class BFS
{
public:
  virtual ~BFS(){};
  virtual vector<int> run(Graph &, vector<int>) = 0;
};

#endif