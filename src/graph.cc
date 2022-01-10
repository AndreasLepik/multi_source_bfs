#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "graph.h"

using namespace std;

Graph::Graph(int numberOfNodes) {
  this->adjecency_matrix = unordered_map<int, unordered_set<int>>(numberOfNodes);
  for (int i = 1; i <= numberOfNodes; ++i) {
    this->adjecency_matrix.insert(make_pair(i, unordered_set<int>()));
  }
}

void Graph::addEdge(int first, int second)
{
    this->adjecency_matrix.at(first).insert(second);
    this->adjecency_matrix.at(second).insert(first);
}

void Graph::loadGraphFromFile(string inputFilePath)
{
  cout << "Loading graph from file..." << endl;
  ifstream input(inputFilePath);
  string line;

  // First line is just meta info
  getline(input, line);

  while (getline(input, line))
  {
    istringstream stream(line);
    string first, second;
    getline(stream, first, '\t');
    getline(stream, second);
    int a = stoi(first);
    int b = stoi(second);
    this->addEdge(a, b);
  }
}

unordered_set<int> Graph::getEdges(int node)
{
  return this->adjecency_matrix.at(node);
}