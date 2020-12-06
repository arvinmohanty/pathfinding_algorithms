#include "../catch/catch.hpp"

#include "../UndirectedGraph.h"

TEST_CASE("UndirectedGraph can be loaded in") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");

  REQUIRE(graph.adj_list.size() == 1648645);
}
