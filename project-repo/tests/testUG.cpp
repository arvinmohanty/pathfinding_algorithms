#include "../catch/catch.hpp"

#include "../UndirectedGraph.h"

TEST_CASE("UndirectedGraph can be loaded in") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");

  REQUIRE(graph.adj_list.size() == 1648645);
  REQUIRE(graph.edge_count == 73);
}

TEST_CASE("UndirectedGraph check node has right list size") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");

  REQUIRE(graph.adj_list[3247].size() == 3);
}

TEST_CASE("UndirectedGraph add edge") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");

  graph.addEdge(5000, 2);
  REQUIRE(graph.edge_count == 74);
}

TEST_CASE("UndirectedGraph has correct adjacency between nodes") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  REQUIRE(graph.adj_list[31].find(30) != graph.adj_list[31].end());
  REQUIRE(graph.adj_list[3247].find(30) != graph.adj_list[3247].end());
  REQUIRE(graph.adj_list[32].find(33) != graph.adj_list[32].end());
  REQUIRE(graph.adj_list[32].find(2203) != graph.adj_list[32].end());
}

TEST_CASE("UndirectedGraph does not possess incorrect adjacencies between nodes") {
  UndirectedGraph graph("project-repo/tests/testdata2.txt");
  REQUIRE(graph.adj_list[32].find(3247) == graph.adj_list[32].end());
  REQUIRE(graph.adj_list[31].find(2203) == graph.adj_list[31].end());
}