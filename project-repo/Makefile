#Executable names
EXE = pathfind
TEST = test

#add objects
EXE_OBJ = main.o
OBJS = Pathfinder.o Node.o UndirectedGraph.o main.o
#compiler/linker config
CXX = clang++
LD = clang++
OBJS_DIR = .objs

WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wnounused-variable -Wno-unused-function
#files to delete after running
CLEAN_RM = 
DepFile_Flags = -MMD -MP

#Flags for linking
LDFLAGS += -std=c++1y -stdlib=libc++ -lc++abi

all: $(EXE)
#make sure it exists
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/Pathfinder
	@mkdir -p $(OBJS_DIR)/Node
	@mkdir -p $(OBJS_DIR)/UndirectedGraph

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX)$(CXXFLAGS) $< -o $@
clean:
	rm -rf $(EXE) $(TEST) $(OBJS_DIR) $(CLEAN_RM) *.o *.d
tide: clean
	rm -rf doc
.PHONY: all tidy clean output_msg
