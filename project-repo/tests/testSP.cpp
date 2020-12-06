#include "../catch/catch.hpp"

#include "../Pathfinder.h"

TEST_CASE("Test basic shortest path") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  Pathfinder pathfinder(graph);

  std::vector<int> expected = {40, 41, 42, 43, 44};
  std::vector<int> path = pathfinder.shortestPath(40, 44);

  REQUIRE(expected == path);
}
