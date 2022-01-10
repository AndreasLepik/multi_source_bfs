#include <iostream>
#include "context.h"
#include "textbook-bfs.h"

int main()
{
  // Algorithms
  TextBookBFS tbfs;

  // Data sets
  string test = "../data_sets/test/out.test";
  string twitter = "../data_sets/twitter/out.txt";

  // Context context {tbfs, test};
  Context context;
  context.setData(test);
  context.setAlgorithm(&tbfs);

  context.run();

  return 0;
}