PROGRAM = parser
GRAMMARFOLDER = ./output/
NASM = nasm
BUILDFOLDER = ./output
BUILDIOEXIST = $(shell if [ -d $(BUILDIO) ]; then echo "exist"; else echo "notexist"; fi;)
GRAMMAREXIST = $(shell if [ -d $(GRAMMARFOLDER) ]; then echo "exist"; else echo "notexist"; fi;)
BUILDEXIST = $(shell if [ -d $(BUILDFOLDER) ]; then echo "exist"; else echo "notexist"; fi;)
DEPS = $(shell find ./ -name "*.h")
SRC = $(shell find ./ -name "*.cpp")
MEDIA = $(shell find ./ -name "*.o")
TAB = $(shell find ./ -name "*.tab.*")
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
	$(BISON) --output="$(GRAMMARFOLDER)grammar.tab.cpp" --defines="$(GRAMMARFOLDER)grammar.tab.h" grammar.y
	$(FLEX) --outfile="$(GRAMMARFOLDER)lexxa.flex.cpp" lexxa.l
	sed -i "1i\#include \"../common/tools.h\"" $(GRAMMARFOLDER)grammar.tab.h

%.o: %.cpp $(DEPS)
	$(CXX) -c $< -o $@ -std=$(CXXVER) -g

clean:
	rm -rf  ./output/lexxa* ./output/test ./output/asm_io* ./output/parser $(OBJ) $(PROGRAM) $(MEDIA) $(TAB)


build:
ifeq ($(BUILDEXIST),notexist)
	mkdir $(BUILDFOLDER)
endif
ifeq ($(BUILDIOEXIST),notexist)
	mkdir $(BUILDIO)
endif
	$(NASM) -f elf -d ELF_TYPE common/util/io/asm_io.asm -o common/util/io/asm_io.o
	cp $(PROGRAM) $(BUILDFOLDER)
	cp common/util/io/asm_io.o $(BUILDFOLDER)
	cp common/util/io/asm_io.inc $(BUILDFOLDER)
	cp -r test/ $(BUILDFOLDER)
	# cp example/Makefile $(BUILDFOLDER)






