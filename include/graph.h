#include <unordered_map>
#include <vector>
using namespace std;

class Graph {
  private:
  // TODO: change to better suited data type.
  unordered_map<int, vector<int>> adjecency_data;
  
  void addEdge(int, int);

  public:
  void loadGraphFromFile(string);

  vector<int> getEdges(int);
};