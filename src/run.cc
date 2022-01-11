#include <iostream>
#include "context.h"
#include "textbook-bfs.h"

int main()
{
  // Algorithms
  TextBookBFS tbfs;

  // Local Data Sets
  string test = "../data_sets/test/out.test";
  string twitter = "../data_sets/twitter/out.txt";

  Context context{test, &tbfs};
  
  // context.setData(test);
  // context.setAlgorithm(&tbfs);

  context.run();

  return 0;
}