#include <iostream>
#include "context.h"
#include "msbfs.h"
#include "bitmapping-msbfs.h"
#include "textbook-bfs.h"
#include "unordered-msbfs.h"
#include "anp-msbfs.h"

vector<int> copyNumberOfElements(vector<int> &vec, int numberOfElements)
{
  auto startIterator = vec.begin();
  auto endIterator = vec.begin() + numberOfElements;

  vector<int> res(numberOfElements);

  copy(startIterator, endIterator, res.begin());
  return res;
}

int main()
{
  // Algorithms
  TextBookBFS     tbfs;
  MSBFS           msbfs;
  UnorderedMSBFS  umsbfs;
  BitmappingMSBFS bm_msbfs;
  ANP_MSBFS       anp_msbfs;

  // Local data sets
  string test =       "../data_sets/test/test.txt";    // size 6
  string zebra =      "../data_sets/zebra/out.zebra"; // size 27
  string twitter =    "../data_sets/twitter/out.txt";
  string wikipedia =  "../data_sets/wikipedia_link_eu/out.wikipedia_link_eu"; // size 371025

  // Starting points
  vector<int> wikipediaFewSources{1000, 2000, 3000};
  vector<int> twentyOnes{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  vector<int> testSources{1, 5};
  vector<int> tenSources;
  for (int i = 1; i < 4; ++i) {
    tenSources.push_back(i * 1);
  }
  vector<int> sixtySources;
  for (int i = 1; i < 61; ++i) {
    sixtySources.push_back(i * 6000);
  }

  // Context context{test, 6, &bm_msbfs, testSources, true};
  // Context context{zebra, 27, &bm_msbfs, tenSources, true};
  Context context{wikipedia, 371025, &bm_msbfs, tenSources, true};

  // auto sortedSources = context.getDegreeSortedNodes();
  // auto sixtySorted = copyNumberOfElements(sortedSources, 60);
  // context.setSources(tenSources);

  auto bm_res = context.run();
  context.run();
  context.run();
  cout << endl;

  context.setAlgorithm(&anp_msbfs);
  auto anp_res = context.run();
  context.run();
  cout << endl;

  context.setAlgorithm(&msbfs);
  auto m_res = context.run();
  cout << endl;

  context.setAlgorithm(&tbfs);
  auto t_res = context.run();
  cout << endl;

  cout << "indentical? anp & bm:" << (anp_res == bm_res)<< endl; 
  cout << "indentical? t & bm:" << (t_res == bm_res)<< endl; 
  cout << "indentical? m & bm:" << (m_res == bm_res)<< endl; 

  return 0;
}
