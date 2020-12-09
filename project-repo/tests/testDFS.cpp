#include "../catch/catch.hpp"
#include "../Pathfinder.h"

TEST_CASE("DFS finds node that exists in the file") {
    UndirectedGraph graph("project-repo/tests/testdata1");
    Pathfinder pathfinder(graph);
    int expected = 420;
    vector<int> actual = pathfinder.dfs(420);
    REQUIRE(expected == actual[0]);

    UndirectedGraph graph2("project-repo/tests/testdata2.txt");
    Pathfinder pathfinder2(graph2);

    expected = 3246;
    actual = pathfinder2.dfs(3246);
    REQUIRE(expected == actual[0]);
}

TEST_CASE("DFS returns a size 1 vector with the nodeID if no node found") {
    UndirectedGraph graph("project-repo/tests/testdata1");
    Pathfinder pathfinder(graph);
    vector<int> actual = pathfinder.dfs(333);
    REQUIRE(actual.size() == 1);
    REQUIRE(actual[0] == 333);

    UndirectedGraph graph2("project-repo/tests/testdata2.txt");
    Pathfinder pathfinder2(graph2);
    actual = pathfinder.dfs(333);
    REQUIRE(actual.size() == 1);
    REQUIRE(actual[0] == 333);
}

TEST_CASE("DFS returns an empty vector if NodeID is out of bounds") {
    UndirectedGraph graph("project-repo/tests/testdata1");
    Pathfinder pathfinder(graph);
    vector<int> actual = pathfinder.dfs(1000000);
    REQUIRE(actual.size() == 0);

    UndirectedGraph graph2("project-repo/tests/testdata2.txt");
    Pathfinder pathfinder2(graph2);
    actual = pathfinder.dfs(1000000);
    REQUIRE(actual.size() == 0);
}

