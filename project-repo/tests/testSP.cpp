#include "../catch/catch.hpp"

#include "../Pathfinder.h"

TEST_CASE("Test basic shortest path") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  Pathfinder pathfinder(graph);

  std::vector<int> expected = {40, 41, 42, 43, 44};
  std::vector<int> path = pathfinder.shortestPath(40, 44);

  REQUIRE(expected == path);
}

TEST_CASE("Test reserve basic shortest path") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  Pathfinder pathfinder(graph);

  std::vector<int> expected = {44, 43, 42, 41, 40};
  std::vector<int> path = pathfinder.shortestPath(44, 40);

  REQUIRE(expected == path);
}

TEST_CASE("Path shouldn't exist for node that doesn't exist") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  Pathfinder pathfinder(graph);

  std::vector<int> path = pathfinder.shortestPath(-1, 44);

  REQUIRE(path.size() == 0);
}
