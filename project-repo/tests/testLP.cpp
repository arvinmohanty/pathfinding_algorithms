#include "../catch/catch.hpp"
#include "../Pathfinder.h"

TEST_CASE("Test basic landmark path") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  Pathfinder pathfinder(graph);

  std::vector<int> expected = {40, 41, 42, 43, 44, 45, 1154, 1153};
  std::vector<int> path = pathfinder.landmarkPath(40, 44, 1153);

  REQUIRE(expected == path);

  UndirectedGraph graph2("project-repo/tests/testdata1");
  Pathfinder pathfinder2(graph2);

  expected = {8, 7, 9, 10, 11, 12, 13, 94, 77, 17};
  path = pathfinder2.landmarkPath(8, 94, 17);

  REQUIRE(expected == path);
}

TEST_CASE("Path shouldn't exist for node whose index is out of bounds") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  Pathfinder pathfinder(graph);

  std::vector<int> path = pathfinder.landmarkPath(-1, 44, 1153);
  REQUIRE(path.size() == 0);
  path = pathfinder.landmarkPath(40, INT_MAX, 44);
  REQUIRE(path.size() == 0);
  path = pathfinder.landmarkPath(40, 44, INT_MAX);
}

TEST_CASE("Landmark Path shouldn't exist for nodes who aren't connected") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  Pathfinder pathfinder(graph);

  std::vector<int> path = pathfinder.landmarkPath(5000, 54, 40);

  REQUIRE(path.size() == 0);
}

TEST_CASE("Landmark Path to the same node should be empty") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  Pathfinder pathfinder(graph);

  std::vector<int> path = pathfinder.landmarkPath(54, 54, 54);

  REQUIRE(path.size() == 0);
}
