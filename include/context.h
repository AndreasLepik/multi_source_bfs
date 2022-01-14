#include "bfs.h"
#include "graph.h"

using namespace std;

class Context
{
private:
  BFS *bfs;
  bool timer;
  Graph graph;

public:
  Context(string path, int size, BFS *algorithm, bool timer = false);

  void run(vector<int> sources);

  void setTimer(bool);
  void setData(string path, int graphSize);
  void setAlgorithm(BFS *algorithm);
};