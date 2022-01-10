#include "bfs.h"
#include "graph.h"

using namespace std;

class Context
{
private:
  BFS *bfs;
  string path;

public:
  void run();

  void setData(string path);
  void setAlgorithm(BFS *algorithm);
};