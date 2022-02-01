#include "bfs.h"
#include "graph.h"

using namespace std;

class Context
{
private:
  BFS *bfs;
  bool timer;
  Graph graph;
  vector<int> sources;

public:
  Context(string path, int size, BFS *algorithm, vector<int> sources, bool timer = false);

  void run();

  void setTimer(bool);
  void setData(string path, int graphSize);
  void setAlgorithm(BFS *algorithm);
};