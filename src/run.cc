#include <iostream>
#include "context.h"
#include "textbook-bfs.h"

int main()
{
  // Algorithms
  TextBookBFS tbfs;

  // Local data sets
  string test = "../data_sets/test/out.test";
  string twitter = "../data_sets/twitter/out.txt";

  // Starting points
  vector<int> sources {1};

  Context context{test, &tbfs};
  
  // context.setData(test);
  // context.setAlgorithm(&tbfs);

  context.run(sources);

  return 0;
}