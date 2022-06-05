# Makefile for SDL2 game Tower Defense for semestral work.

COLOR_DEFAULT = \033[0m
COLOR_STATUS = \033[1;33m
COLOR_INFO = \033[1;36m
COLOR_GOOD = \033[1;32m

EXECUTABLE = kulikvl1

CXX = g++
CXXFLAGS = -std=c++17 -Wall -pedantic -Wno-long-long -O2 -Werror
LDFLAGS = -lSDL2 -lSDL2_image
CHECK = valgrind
CHECKFLAGS = --leak-check=full

# wildcard (make syntax) returns a list of all the source files with a particular extension.
# := is simple assignment, the command ( wildcard... ) will be executed once.
# = is expanded assignment, the command will be executed every time we see SOURCES.
SOURCES := $(wildcard src/*.cpp)



all: doc compile

# get SOURCES list, but replace .cpp with .o
compile: $(SOURCES:.cpp=.o)
	@echo "$(COLOR_INFO)compiling with flags $(COLOR_DEFAULT)$(CXXFLAGS) $(LDFLAGS)"
	@$(CXX) $(CXXFLAGS) $(SOURCES:.cpp=.o) $(LDFLAGS) -o $(EXECUTABLE) 
	@echo "$(COLOR_GOOD)COMPILE SUCCESS$(COLOR_DEFAULT)"

run: compile
	@echo "$(COLOR_INFO)starting executable$(COLOR_DEFAULT)"
	@./$(EXECUTABLE)
	@echo "$(COLOR_GOOD)RUN SUCCESS$(COLOR_DEFAULT)"

doc:
	@echo "$(COLOR_INFO)generating documentation$(COLOR_DEFAULT)"
	doxygen Doxyfile
	@echo "$(COLOR_GOOD)DOC SUCCESS$(COLOR_DEFAULT)"

check: clean compile
	@echo "$(COLOR_INFO)starting check in $(CHECK) utility with flags $(COLOR_DEFAULT)$(CHECKFLAGS)"
	$(CHECK) $(CHECKFLAGS) ./$(EXECUTABLE)
	@echo "$(COLOR_GOOD)CHECK SUCCESS$(COLOR_DEFAULT)"

clean:
	@echo "$(COLOR_INFO)removing object/link/executable/documentation files$(COLOR_DEFAULT)"
	@rm -rf src/*.o src/*.d $(EXECUTABLE) doc/
	@echo "$(COLOR_GOOD)CLEAN SUCCESS$(COLOR_DEFAULT)"

help:
	@echo "Usage: $(COLOR_INFO)make$(COLOR_DEFAULT) $(COLOR_STATUS)[TARGET]$(COLOR_DEFAULT)"
	@echo
	@echo "TARGETS:"
	@echo "  $(COLOR_STATUS)all$(COLOR_DEFAULT)       create all outputs generated from source code"
	@echo "  $(COLOR_STATUS)compile$(COLOR_DEFAULT)   compiles outdated object files and creates the executable"
	@echo "  $(COLOR_STATUS)run$(COLOR_DEFAULT)       compiles and runs the executable file"
	@echo "  $(COLOR_STATUS)doc$(COLOR_DEFAULT)       generates the project Doxyfile documentation"
	@echo "  $(COLOR_STATUS)check$(COLOR_DEFAULT)     does a clean compilation and runs check utility"
	@echo "  $(COLOR_STATUS)clean$(COLOR_DEFAULT)     removes all of the compiled files, executable and documentation"
	@echo "  $(COLOR_STATUS)help$(COLOR_DEFAULT)      print this message"



# 	% is used for pattern matching, and it requires one in the target as well as one in the dependencies.
# -MM flag returns all dependencies for source file. -MT flag allows to specify a name for the target (e.x. not main.o: ... , but someTargetName: ...).
# 	$@	Target name.
# 	$<	First dependancy name.
#	$*	Target name without end suffix.
#	$^	All dependancies names.
# @ is to ignore printing the content of the command.
%.o: %.cpp
	@echo "$(COLOR_STATUS)$< -> $@$(COLOR_DEFAULT)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@$(CXX) $(CXXFLAGS) $(LDFLAGS) -MM -MT $*.o $*.cpp  > $*.d



# inserts contents of files here ('-' means to ignore a makefile which does not exist)
-include $(SOURCES:.cpp=.d)
