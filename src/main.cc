#include <iostream>
#include "context.h"
#include "msbfs.h"
#include "bitmapping-msbfs.h"
#include "textbook-bfs.h"
#include "unordered-msbfs.h"
#include "anp-msbfs.h"

int main()
{
  // Algorithms
  TextBookBFS tbfs;
  MSBFS msbfs;
  UnorderedMSBFS umsbfs;
  BitmappingMSBFS bm_msbfs;
  ANP_MSBFS anp_msbfs;

  // Local data sets
  string test = "../data_sets/test/test.txt";    // size 6
  string zebra = "../data_sets/zebra/out.zebra"; // size 27
  string twitter = "../data_sets/twitter/out.txt";
  string wikipedia = "../data_sets/wikipedia_link_eu/out.wikipedia_link_eu"; // size 371025

  // Define Starting points
  int factor = 371025 / 63;
  vector<int> experimentalSources = {};
  for (int i = 1; i <= 63; ++i)
  {
    experimentalSources.push_back(i * factor);
  }

  // Define the test context
  Context context{wikipedia, 371025, &bm_msbfs, experimentalSources, true};
  auto sortedSources = context.getDegreeSortedNodes();

  // Run tests
  cout << "========== Unsorted, size " << experimentalSources.size() << endl;
  context.setSources(experimentalSources);

  context.setAlgorithm(&bm_msbfs);
  auto bm_res = context.run();
  context.run();
  context.run();
  cout << endl;

  context.setAlgorithm(&anp_msbfs);
  auto anp_res = context.run();
  context.run();
  context.run();
  cout << endl;

  context.setAlgorithm(&msbfs);
  auto m_res = context.run();
  cout << endl;

  context.setAlgorithm(&tbfs);
  auto t_res = context.run();
  cout << endl;

  // cout << "indentical res? anp & bm: " << (anp_res == bm_res) << endl;
  // cout << "indentical res? t   & bm: " << (t_res == bm_res) << endl;
  // cout << "indentical res? m   & bm: " << (m_res == bm_res) << endl;
  // cout << endl;

  cout << "========== Sorted, size " << experimentalSources.size() << endl;
  auto sorted = copyNumberOfElements(sortedSources, experimentalSources.size());
  context.setSources(sorted);

  context.setAlgorithm(&bm_msbfs);
  bm_res = context.run();
  context.run();
  context.run();
  cout << endl;

  context.setAlgorithm(&anp_msbfs);
  anp_res = context.run();
  context.run();
  context.run();
  cout << endl;

  cout << "indentical res? anp & bm: " << (anp_res == bm_res) << endl;
  // cout << endl;

  return 0;
}

vector<int> copyNumberOfElements(vector<int> &vec, int numberOfElements)
{
  auto startIterator = vec.begin();
  auto endIterator = vec.begin() + numberOfElements;

  vector<int> res(numberOfElements);

  copy(startIterator, endIterator, res.begin());
  return res;
}