#include "../catch/catch.hpp"

#include "../Pathfinder.h"

TEST_CASE("Test basic shortest path") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  Pathfinder pathfinder(graph);

  std::vector<int> expected = {40, 41, 42, 43, 44};
  std::vector<int> path = pathfinder.shortestPath(40, 44);

  REQUIRE(expected == path);

  UndirectedGraph graph2("project-repo/tests/testdata1");
  Pathfinder pathfinder2(graph2);

  expected = {8, 7, 9, 10, 11, 12, 13, 94};
  path = pathfinder2.shortestPath(8, 94);

  REQUIRE(expected == path);
}

TEST_CASE("Test reserve basic shortest path") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  Pathfinder pathfinder(graph);

  std::vector<int> expected = {44, 43, 42, 41, 40};
  std::vector<int> path = pathfinder.shortestPath(44, 40);

  REQUIRE(expected == path);

  UndirectedGraph graph2("project-repo/tests/testdata1");
  Pathfinder pathfinder2(graph2);

  expected = {94, 13, 12, 11, 10, 9, 7, 8};
  path = pathfinder2.shortestPath(94, 8);

  REQUIRE(expected == path);
}

TEST_CASE("Path shouldn't exist for node whose index is out of bounds") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  Pathfinder pathfinder(graph);

  std::vector<int> path = pathfinder.shortestPath(-1, 44);
  REQUIRE(path.size() == 0);
  path = pathfinder.shortestPath(40, 1000000);
  REQUIRE(path.size() == 0);

  UndirectedGraph graph2("project-repo/tests/testdata1");
  Pathfinder pathfinder2(graph);
}

TEST_CASE("Path shouldn't exist for nodes who aren't connected") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  Pathfinder pathfinder(graph);

  std::vector<int> path = pathfinder.shortestPath(5000, 54);

  REQUIRE(path.size() == 0);
}

TEST_CASE("Path to the same node should be empty") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  Pathfinder pathfinder(graph);

  std::vector<int> path = pathfinder.shortestPath(54, 54);

  REQUIRE(path.size() == 0);
}
