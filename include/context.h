#include "bfs.h"
#include "graph.h"

using namespace std;

class Context
{
private:
  BFS *bfs;
  string pathToGraphFile;
  int graphSize;

public:
  Context(string path, BFS *algorithm, int size);

  void run(vector<int> sources);

  void setData(string path, int graphSize);
  void setAlgorithm(BFS *algorithm);
};