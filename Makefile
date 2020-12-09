EXENAME = pathfind
OBJS = main.o Pathfinder.o UndirectedGraph.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first before compiling. $(ccend))
endif
else
ifneq ($(strip $(SKIP_EWS_CHECK)),True)
CLANG_VERSION_MSG = $(warning $(ccyellow) Please develop on EWS. $(ccend))
endif
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : project-repo/main.cpp project-repo/Pathfinder.h project-repo/UndirectedGraph.h
	$(CXX) $(CXXFLAGS) project-repo/main.cpp

Pathfinder.o : project-repo/Pathfinder.cpp project-repo/Pathfinder.h
	$(CXX) $(CXXFLAGS) project-repo/Pathfinder.cpp

UndirectedGraph.o : project-repo/UndirectedGraph.cpp project-repo/UndirectedGraph.h
	$(CXX) $(CXXFLAGS) project-repo/UndirectedGraph.cpp

OBJS_TEST = testconstructor.o testSP.o catchmain.o

SHORTEST_PATH_OBJS = testSP.o catchmain.o Pathfinder.o UndirectedGraph.o
UNDIRECTED_GRAPH_OBJS = testUG.o catchmain.o  UndirectedGraph.o
LANDMARK_PATH_OBJS = testLP.o catchmain.o Pathfinder.o UndirectedGraph.o
SCC_OBJS = testSCC.o catchmain.o Pathfinder.o UndirectedGraph.o
DFS_OBJS = testDFS.o catchmain.o Pathfinder.o UndirectedGraph.o

shortestPathTest : output_msg $(SHORTEST_PATH_OBJS)
	$(LD) $(SHORTEST_PATH_OBJS) $(LDFLAGS) -o shortestPathTest

landmarkPathTest : output_msg $(LANDMARK_PATH_OBJS)
	$(LD) $(LANDMARK_PATH_OBJS) $(LDFLAGS) -o landmarkPathTest

undirectedGraphTest : output_msg $(UNDIRECTED_GRAPH_OBJS)
	$(LD) $(UNDIRECTED_GRAPH_OBJS) $(LDFLAGS) -o undirectedGraphTest

sccTest : output_msg $(SCC_OBJS)
	$(LD) $(SCC_OBJS) $(LDFLAGS) -o sccTest

dfsTest : output_msg $(DFS_OBJS)
	$(LD) $(DFS_OBJS) $(LDFLAGS) -o dfsTest


testconstructor : project-repo/tests/testconstructor.cpp
	$(CXX) $(CXXFLAGS) project-repo/tests/testconstructor.cpp

testSP.o : project-repo/tests/testSP.cpp
	$(CXX) $(CXXFLAGS) project-repo/tests/testSP.cpp

testUG.o : project-repo/tests/testUG.cpp
	$(CXX) $(CXXFLAGS) project-repo/tests/testUG.cpp

testLP.o : project-repo/tests/testLP.cpp
	$(CXX) $(CXXFLAGS) project-repo/tests/testLP.cpp

testSCC.o : project-repo/tests/testSCC.cpp
	$(CXX) $(CXXFLAGS) project-repo/tests/testSCC.cpp

testDFS.o : project-repo/tests/testDFS.cpp
	$(CXX) $(CXXFLAGS) project-repo/tests/testDFS.cpp
	
catchmain.o : project-repo/catch/catch.hpp project-repo/catch/catchmain.cpp
	$(CXX) $(CXXFLAGS) project-repo/catch/catchmain.cpp

