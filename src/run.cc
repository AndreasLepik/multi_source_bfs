#include <iostream>
#include "context.h"
#include "textbook-bfs.h"

int main()
{
  // Algorithms
  TextBookBFS tbfs;

  // Local data sets
  string test = "../data_sets/test/out.test";
  string zebra = "../data_sets/zebra/out.zebra";
  string twitter = "../data_sets/twitter/out.txt";

  // Starting points
  vector<int> sources {20};

  Context context{zebra, &tbfs};
  
  // context.setData(test);
  // context.setAlgorithm(&tbfs);

  context.run(sources);

  return 0;
}