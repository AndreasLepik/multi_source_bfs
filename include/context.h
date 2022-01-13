#include "bfs.h"
#include "graph.h"

using namespace std;

class Context
{
private:
  BFS *bfs;
  int graphSize;
  string pathToGraphFile;

public:
  Context(string path, int size, BFS *algorithm);

  void run(vector<int> sources);

  void setData(string path, int graphSize);
  void setAlgorithm(BFS *algorithm);
};