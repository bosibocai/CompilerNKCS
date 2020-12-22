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
	rm -rf $(GRAMMARFOLDER) $(OBJ) $(PROGRAM) $(MEDIA)


ifeq ($(BUILDEXIST),notexist)
	mkdir $(BUILDFOLDER)
endif
ifeq ($(BUILDIOEXIST),notexist)
	mkdir $(BUILDIO)
endif
	$(NASM) -f elf -d ELF_TYPE common/util/io/asm_io.asm -o common/util/io/asm_io.o
	cp $(PROGRAM) $(BUILDFOLDER)
	cp common/util/io/asm_io.o $(BUILDIO)
	cp common/util/io/asm_io.inc $(BUILDIO)
	cp -r test/ $(BUILDFOLDER)
	# cp example/Makefile $(BUILDFOLDER)

all: array error  hello loop_test print_test simple

array: $(BUILDFOLDER)/test/array.c
	$(PROGRAM) $(BUILDFOLDER)/test/array.c
	$(NASM) -f elf $(BUILDFOLDER)/test/array.asm -o $(BUILDFOLDER)/array.o
	$(CC) -o $(BUILDFOLDER)/array $(BUILDFOLDER)/array.o $(BUILDFOLDER)/io/asm_io.o -m32

error: $(BUILDFOLDER)/test/error.c
	$(PROGRAM) $(BUILDFOLDER)/test/error.c
	$(NASM) -f elf $(BUILDFOLDER)/test/error.asm -o $(BUILDFOLDER)/error.o
	$(CC) -o $(BUILDFOLDER)/error $(BUILDFOLDER)/error.o $(BUILDFOLDER)/io/asm_io.o -m32

hello: $(BUILDFOLDER)/test/hello.c
	$(PROGRAM) $(BUILDFOLDER)/test/hello.c
	$(NASM) -f elf $(BUILDFOLDER)/test/hello.asm -o $(BUILDFOLDER)/hello.o
	$(CC) -o $(BUILDFOLDER)/hello $(BUILDFOLDER)/hello.o $(BUILDFOLDER)/io/asm_io.o -m32


loop_test: $(BUILDFOLDER)/test/loop_test.c
	$(PROGRAM) $(BUILDFOLDER)/test/loop_test.c
	$(NASM) -f elf $(BUILDFOLDER)/test/loop_test.asm -o $(BUILDFOLDER)/loop_test.o
	$(CC) -o $(BUILDFOLDER)/loop_test $(BUILDFOLDER)/loop_test.o $(BUILDFOLDER)/io/asm_io.o -m32


print_test: $(BUILDFOLDER)/test/print_test.c
	$(PROGRAM) $(BUILDFOLDER)/test/print_test.c
	$(NASM) -f elf $(BUILDFOLDER)/test/print_test.asm -o $(BUILDFOLDER)/print_test.o
	$(CC) -o $(BUILDFOLDER)/print_test $(BUILDFOLDER)/print_test.o io/asm_io.o -m32

simple: $(BUILDFOLDER)/test/simple.c
	$(PROGRAM) $(BUILDFOLDER)/test/simple.c
	$(NASM) -f elf $(BUILDFOLDER)/test/simple.asm -o $(BUILDFOLDER)/simple.o
	$(CC) -o $(BUILDFOLDER)/simple $(BUILDFOLDER)/simple.o $(BUILDFOLDER)/io/asm_io.o -m32






