PROGRAM = parser
GRAMMARFOLDER = ./Linux/
NASM = nasm
BUILDIOEXIST = $(shell if [ -d $(BUILDIO) ]; then echo "exist"; else echo "notexist"; fi;)
GRAMMAREXIST = $(shell if [ -d $(GRAMMARFOLDER) ]; then echo "exist"; else echo "notexist"; fi;)
BUILDEXIST = $(shell if [ -d $(BUILDFOLDER) ]; then echo "exist"; else echo "notexist"; fi;)
DEPS = $(shell find ./ -name "*.h")
SRC = $(shell find ./ -name "*.cpp")
OBJ = $(SRC:%.cpp=%.o)
CXX = g++
FLEX = flex
BISON = bison
CXXVER = c++11

$(PROGRAM): $(OBJ)
	$(CXX) -o $(PROGRAM) $(OBJ) -std=$(CXXVER) -g

grammar: lexxa.l grammar.y
ifeq ($(GRAMMAREXIST),notexist)
	mkdir $(GRAMMARFOLDER)
endif
	$(BISON) --output="./Linux/grammar.tab.cpp" --defines="./Linux/grammar.tab.h" grammar.y
	$(FLEX) --outfile="./Linux/lexxa.flex.cpp" lexxa.l
	sed -i "1i\#include \"../common/tools.h\"" ./Linux/grammar.tab.h

%.o: %.cpp $(DEPS)
	$(CXX) -c $< -o $@ -std=$(CXXVER) -g

clean:
	rm -rf $(GRAMMARFOLDER) $(OBJ) $(PROGRAM) common/util/io/asm_io.o
