#include "../catch/catch.hpp"

#include "../UndirectedGraph.h"

TEST_CASE("UndirectedGraph can be loaded in") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");

  REQUIRE(graph.adj_list.size() == 1648645);
  REQUIRE(graph.edge_count == 73);
}

TEST_CASE("UndirectedGraph add edge") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");

  graph.addEdge(5000, 2);
  REQUIRE(graph.edge_count == 74);
}
