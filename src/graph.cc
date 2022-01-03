#include <iostream>
#include "graph.h"
using namespace std;

void Graph::loadGraphFromFile() {
  cout << "loading..." << endl;
  this->adjecency_data.insert(make_pair<int, vector<int>>(1, {1, 2, 3}));
}

vector<int> Graph::getEdges(int node) {
  return this->adjecency_data.at(node);
}