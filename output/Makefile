CC = gcc
NASM = nasm
PROGRAM = ./parser
BUILDFOLDER = .
OBJ = $(SRC:%.cpp=%.o)
MEDIA = $(shell find ../ -name "*.o")
TAB = $(shell find ../ -name "*.tab.*")
clean:
	rm -rf  lexxa* test asm_io* parser $(OBJ)  $(MEDIA) $(TAB)


all: array error  hello loop_test print_test simple

array: 
	
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


point_test: $(BUILDFOLDER)/test/point_test.c
	$(PROGRAM) $(BUILDFOLDER)/test/point_test.c
	$(NASM) -f elf $(BUILDFOLDER)/test/point_test.asm -o $(BUILDFOLDER)/point_test.o
	$(CC) -o $(BUILDFOLDER)/point_test $(BUILDFOLDER)/point_test.o io/asm_io.o -m32

simple: $(BUILDFOLDER)/test/simple.c
	$(PROGRAM) $(BUILDFOLDER)/test/simple.c
	$(NASM) -f elf $(BUILDFOLDER)/test/simple.asm -o $(BUILDFOLDER)/simple.o
	$(CC) -o $(BUILDFOLDER)/simple $(BUILDFOLDER)/simple.o $(BUILDFOLDER)/io/asm_io.o -m32

