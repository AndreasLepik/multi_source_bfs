#include <iostream>
#include "context.h"
#include "textbook-bfs.h"

int main()
{
  // Algorithms
  TextBookBFS tbfs;

  // Local data sets
  string test = "../data_sets/test/out.test";
  string zebra = "../data_sets/zebra/out.zebra"; // size 20
  string twitter = "../data_sets/twitter/out.txt";
  string wikipedia = "../data_sets/wikipedia_link_eu/out.wikipedia_link_eu";

  // Starting points
  vector<int> sources {20};

  Context context{wikipedia, &tbfs, 371025};
  
  // context.setData(test);
  // context.setAlgorithm(&tbfs);

  context.run(sources);

  return 0;
}