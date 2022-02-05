#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "graph.h"

using namespace std;

Graph::Graph(int numberOfNodes, string pathToData)
{
  this->adjecency_matrix = vector<set<int>>(numberOfNodes + 1, set<int>());

  adjecency_indexes = vector<int>(numberOfNodes + 2);
  adjecency_edges = vector<int>();

  this->size = numberOfNodes;

  loadGraphFromFile(pathToData);
}

vector<int> Graph::getDegreeSortedNodes()
{
  return this->degree_sorted_nodes;
}

int Graph::getSize()
{
  return this->size;
}

void Graph::addEdge(int first, int second)
{
  this->adjecency_matrix.at(first).insert(second);
  this->adjecency_matrix.at(second).insert(first);
}

void Graph::loadGraphFromFile(string inputFilePath)
{
  cout << "Loading graph from file..." << endl;
  // vector<vector<int>> adjecency_matrix();
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

  int currentIndexIndex = 0;
  int currentEdgeIndex = 0;
  for (auto node : adjecency_matrix)
  {
    adjecency_indexes.at(currentIndexIndex) = currentEdgeIndex;
    for (auto edge : node)
    {
      adjecency_edges.push_back(edge);
      currentEdgeIndex++;
    }
    currentIndexIndex++;
  }
  // Add one extra index for accessing the last element
  adjecency_indexes.at(currentIndexIndex) = currentEdgeIndex;

  // Build sorted list based on degree
  map<int, int> degreeMap;
  for (int i = 0; i < adjecency_matrix.size(); ++i)
  {
    degreeMap.insert(make_pair(adjecency_matrix.at(i).size(), i));
  }
  for (auto a = degreeMap.rbegin(); a != degreeMap.rend(); ++a)
  {
    degree_sorted_nodes.push_back(a->second);
  }

  // Deallocate adjecency matrix that no longer used.
  adjecency_matrix.clear();
}

span<int> Graph::getEdges(int node)
{
  int start = this->adjecency_indexes.at(node);
  int end = this->adjecency_indexes.at(node + 1);

  auto startIterator = this->adjecency_edges.begin() + start;
  auto endIterator = this->adjecency_edges.begin() + end;

  span<int> res{startIterator, endIterator};
  // vector<int> res(end - start);

  // copy(startIterator, endIterator, res.begin());
  return res;
}