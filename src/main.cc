#include <iostream>
#include "context.h"
#include "msbfs.h"
#include "bitmapping-msbfs.h"
#include "textbook-bfs.h"
#include "unordered-msbfs.h"

int main()
{
  // Algorithms
  TextBookBFS     tbfs;
  MSBFS           msbfs;
  UnorderedMSBFS  umsbfs;
  BitmappingMSBFS bmsbfs;

  // Local data sets
  string test =       "../data_sets/test/test.txt";    // size 6
  string zebra =      "../data_sets/zebra/out.zebra"; // size 27
  string twitter =    "../data_sets/twitter/out.txt";
  string wikipedia =  "../data_sets/wikipedia_link_eu/out.wikipedia_link_eu"; // size 371025

  // Starting points
  vector<int> wikipediaFewSources{1, 10, 20};
  vector<int> twentyOnes{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  vector<int> testSources{1, 2};
  vector<int> wikipediaSources;
  for (int i = 1; i < 4; ++i) {
    wikipediaSources.push_back(i * 1000);
  }

  // Context context{test, 6, &bmsbfs, true};
  Context context{wikipedia, 371025, &bmsbfs, wikipediaSources, true};
  // Context context{zebra, 27, &msbfs, true};

  context.run();
  context.setAlgorithm(&msbfs);
  context.run();
  context.setAlgorithm(&umsbfs);
  context.run();
  context.setAlgorithm(&tbfs);
  context.run();

  return 0;
}