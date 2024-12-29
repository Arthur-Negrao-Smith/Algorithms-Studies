BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all: libs main

libs:
	gcc -c $(SRC)/heterogeneous_linkedlist.c -I $(INCLUDE) -o $(OBJ)/heterogeneous_linkedlist.o
	gcc -c $(SRC)/main.c -I $(INCLUDE) -o $(OBJ)/main.o

main:
	gcc $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/main    # Compile all object files

run:
	$(BIN)/main    # Run the main project

clean:
	rm -rf $(OBJ)/* $(BIN)/*	# Clean all object files and bin files