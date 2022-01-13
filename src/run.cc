#include <iostream>
#include "context.h"
#include "textbook-bfs.h"

int main()
{
  // Algorithms
  TextBookBFS tbfs;

  // Local data sets
  string test = "../data_sets/test/out.test"; // size 5
  string zebra = "../data_sets/zebra/out.zebra"; // size 27
  string twitter = "../data_sets/twitter/out.txt";
  string wikipedia = "../data_sets/wikipedia_link_eu/out.wikipedia_link_eu"; // size 371025

  // Starting points
  vector<int> sources{19, 20, 22};

  Context context{zebra, 27, &tbfs};

  // context.setData(test);
  // context.setAlgorithm(&tbfs);

  context.run(sources);

  return 0;
}