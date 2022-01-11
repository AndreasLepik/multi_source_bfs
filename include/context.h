#include "bfs.h"
#include "graph.h"

using namespace std;

class Context
{
private:
  BFS *bfs;
  string path;

public:
  Context(string path, BFS *algorithm);

  void run(vector<int> sources);

  void setData(string path);
  void setAlgorithm(BFS *algorithm);
};