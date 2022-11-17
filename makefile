DIRECTORY = quicksort-analysis
EXE = main

REPODIR = ../$(DIRECTORY)
TARFILE = $(DIRECTORY).tar

FLAGS = -Wall -Wextra -g
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/Main.o
	$(CC) $(FLAGS) $(OBJ)/Main.o -o $@

$(OBJ)/Main.o: Main.cpp
	$(CC) $(FLAGS) -c Main.cpp -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) $(BIN)/$(DATA) *.tar.gz
