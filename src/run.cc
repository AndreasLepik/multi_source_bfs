#include <iostream>
#include "context.h"
#include "msbfs.h"
#include "textbook-bfs.h"

int main()
{
  // Algorithms
  TextBookBFS tbfs;
  MSBFS msbfs;

  // Local data sets
  string test = "../data_sets/test/test.txt"; // size 6
  string zebra = "../data_sets/zebra/out.zebra"; // size 27
  string twitter = "../data_sets/twitter/out.txt";
  string wikipedia = "../data_sets/wikipedia_link_eu/out.wikipedia_link_eu"; // size 371025

  // Starting points
  vector<int> sources{1, 2};

  Context context{test, 6, &msbfs};

  // context.setData(test);
  // context.setAlgorithm(&tbfs);

  context.run(sources);

  return 0;
}