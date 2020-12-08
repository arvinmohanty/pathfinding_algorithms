#include "../catch/catch.hpp"
#include "../Pathfinder.h"

TEST_CASE("SCC works when there is an SCC") {
    UndirectedGraph graph("project-repo/tests/testdataSCC.txt");
    Pathfinder pathfinder(graph);
    vector<int> expected = {0, 1, 2, 3, 4};
    vector<int> actual = pathfinder.strongestConnectedComponent();
    REQUIRE(expected == actual);

    UndirectedGraph graph2("project-repo/tests/testdataSCC2.txt");
    Pathfinder pathfinder2(graph2);

    expected = {0, 1, 20, 5, 12, 14, 19};
    actual = pathfinder2.strongestConnectedComponent();
    REQUIRE(expected == actual);
}

TEST_CASE("SCC returns empty vector if no SCC found") {
    UndirectedGraph graph("project-repo/tests/testdata1");
    Pathfinder pathfinder(graph);
    REQUIRE(pathfinder.strongestConnectedComponent().size() == 0);

    UndirectedGraph graph2("project-repo/tests/testdata2.txt");
    Pathfinder pathfinder2(graph2);
    REQUIRE(pathfinder2.strongestConnectedComponent().size() == 0);
}

TEST_CASE("Connected component returns largest possible connected component") {
    UndirectedGraph graph("project-repo/tests/testdataCC.txt");
    Pathfinder pathfinder(graph);
    vector<int> expected = {0, 1, 2, 3, 4};
    vector<int> actual = pathfinder.connectedComponent();
    REQUIRE(expected == actual);
}

TEST_CASE("Connected component returns first if multiple of the same size found") {
    // for example, if the largest connected component was of size 3, and there were 2 connected components of that size
    // it would return the first occurence of the component
    // pathfinder.h has been updated to specify this in comments above the function signature
    UndirectedGraph graph("project-repo/tests/testdataCC2.txt");
    Pathfinder pathfinder(graph);
    vector<int> expected = {0, 1};
    vector<int> actual = pathfinder.connectedComponent();
    REQUIRE(expected == actual);
}