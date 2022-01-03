#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "graph.h"
using namespace std;

void Graph::addEdge(int first, int second)
{
  if (first < second)
  {
    int temp = first;
    first = second;
    second = temp;
  }

  auto vec = this->adjecency_data.find(first);
  if (vec == this->adjecency_data.end())
  {
    this->adjecency_data.insert(make_pair<int, vector<int>>(1, {second}));
  }
  else
  {
    this->adjecency_data.at(first).push_back(second);
  }
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
    cout << a << ", " << b << endl;
    this->addEdge(a, b);
  }
}

vector<int> Graph::getEdges(int node)
{
  return this->adjecency_data.at(node);
}