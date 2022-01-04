#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Graph
{
private:
  // TODO: change to better suited data type.
  unordered_map<int, unordered_set<int>> adjecency_matrix;
  void addEdge(int, int);

public:
  Graph(int);
  void loadGraphFromFile(string);
  unordered_set<int> getEdges(int);
};