#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>

using namespace std;

/**
 * Graph representation class
 * Builds graph from CSL text file. 
 */
class Graph
{
private:
  // only used while loading from file, consider moving to function scope.
  vector<set<int>> adjecency_matrix;
  int size;

  vector<int> adjecency_indexes;
  vector<int> adjecency_edges;

  vector<int> degree_sorted_nodes;

  void addEdge(int, int);
  void loadGraphFromFile(string);

public:
  Graph(int, string);
  vector<int> getEdges(int);
  int getSize();
  vector<int> getDegreeSortedNodes();
};

#endif