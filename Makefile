EXENAME = pathfind
OBJS = main.o Node.o Pathfinder.o UndirectedGraph.o

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

main.o : project-repo/main.cpp project-repo/Node.h project-repo/Pathfinder.h project-repo/UndirectedGraph.h
	$(CXX) $(CXXFLAGS) project-repo/main.cpp

Node.o : project-repo/Node.cpp project-repo/Node.h
	$(CXX) $(CXXFLAGS) project-repo/Node.cpp

Pathfinder.o : project-repo/Pathfinder.cpp project-repo/Pathfinder.h
	$(CXX) $(CXXFLAGS) project-repo/Pathfinder.cpp

UndirectedGraph.o : project-repo/UndirectedGraph.cpp project-repo/UndirectedGraph.h
	$(CXX) $(CXXFLAGS) project-repo/UndirectedGraph.cpp