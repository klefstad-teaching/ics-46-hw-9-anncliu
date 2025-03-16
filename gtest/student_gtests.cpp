#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"



TEST(DijkstrasAlgorithmTest, print_path) {
  int arr[] = {4, 13, 9, 6, 12, 2};
  vector<int> v(arr, arr+sizeof(arr)/sizeof(int));
  print_path(v, 10); // prints "4 13 9 6 12 2 \nTotal cost is 10\n"
}
