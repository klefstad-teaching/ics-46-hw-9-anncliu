#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"


vector<int> run_dijkstras(string file_name, int source)
{
  Graph g;
  vector<int> prev;
  file_to_graph(file_name, g);
  return dijkstra_shortest_path(g, source, prev);
}

void are_equal(int expected[], int arr_size, const vector<int>& distances)
{
  EXPECT_EQ(arr_size, distances.size());

  for (int i = 0; i < arr_size; ++i)
    EXPECT_EQ(expected[i], distances[i]);
}


TEST(DijkstrasAlgorithmTest, print_path) {
  int arr[] = {4, 13, 9, 6, 12, 2};
  vector<int> v(arr, arr+sizeof(arr)/sizeof(int));
  print_path(v, 10); // prints "4 13 9 6 12 2 \nTotal cost is 10\n"
}


TEST(DijkstrasAlgorithmTest, ShortestPathSmallGraph)
{
  int expected[] = {0, 3, 6, 1};
  are_equal(expected, 4, run_dijkstras("src/small.txt", 0));
}

TEST(DijkstrasAlgorithmTest, ShortestPathMediumGraph)
{
  int expected[] = {0, 5, 3, 12, 10, 2};
  are_equal(expected, 6, run_dijkstras("src/medium.txt", 0));
}

TEST(DijkstrasAlgorithmTest, ShortestPathLargeGraph)
{
  int expected[] = {0, 7, 15, 5, 14, 11, 12};
  are_equal(expected, 7, run_dijkstras("src/large.txt", 0));
}


TEST(WordLadderTest, IsAdjacentLengthDiffGreatertThan1)
{
  EXPECT_FALSE(is_adjacent("mat", "mathy"));
  EXPECT_FALSE(is_adjacent("mat", "attorney"));
}

// fails 1st and 4th expects
TEST(WordLadderTest, IsAdjacentLengthGeneral)
{
  EXPECT_FALSE(is_adjacent("gcat", "cgta"));
  EXPECT_FALSE(is_adjacent("moon", "moonlight"));
  EXPECT_TRUE(is_adjacent("stride", "strider"));
  EXPECT_FALSE(is_adjacent("steak", "stake"));
}

TEST(WordLadderTest, EditDistanceWithin1)
{
  EXPECT_TRUE(edit_distance_within("mat", "matt", 1));
  EXPECT_TRUE(edit_distance_within("mat", "math", 1));
  EXPECT_TRUE(edit_distance_within("mat", "at", 1));
  EXPECT_TRUE(edit_distance_within("mat", "ma", 1));
  EXPECT_TRUE(edit_distance_within("stride", "strider", 1));
}

TEST(WordLadderTest, EditDistanceWithin0)
{
  EXPECT_TRUE(edit_distance_within("mat", "bat", 0));
  EXPECT_TRUE(edit_distance_within("mat", "cat", 0));
  EXPECT_TRUE(edit_distance_within("mat", "hat", 0));
}

