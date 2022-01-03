#include <iostream>
#include <fstream>
#include <string>
#include "graph.h"
using namespace std;

void Graph::loadGraphFromFile(string inputFilePath) {
  cout << "Loading graph from file..." << endl;
  ifstream input (inputFilePath);
  string line;
  while (input) {
    getline(input, line);
    cout << line << endl;
  }
  this->adjecency_data.insert(make_pair<int, vector<int>>(1, {1, 2, 3}));
}

vector<int> Graph::getEdges(int node) {
  return this->adjecency_data.at(node);
}