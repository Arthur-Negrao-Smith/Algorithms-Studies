BIN = ./bin
OBJ = ./obj
SRC = ./src

all: libs main

libs:
	gcc -c $(SRC)/doublelinkedlist.c -o $(OBJ)/doublelinkedlist.o

main:
	gcc $(OBJ)/*.o -o $(BIN)/main    # Compile all object files

run:
	$(BIN)/main    # Run the main project

clean:
	rm -rf $(OBJ)/* $(BIN)/*	# Clean all object files and bin files