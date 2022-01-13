#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>

using namespace std;

class Graph
{
private:
  // only used while loading from file
  vector<set<int>> adjecency_matrix;

  vector<int> adjecency_indexes;
  vector<int> adjecency_edges;

  void addEdge(int, int);
  void loadGraphFromFile(string);

public:
  Graph(int, string);
  vector<int> getEdges(int);
};

#endif