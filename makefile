DIRECTORY = quicksort-analysis
EXE = main

REPODIR = ../$(DIRECTORY)
TARFILE = $(DIRECTORY).tar

FLAGS = -Wall -Wextra -g
CC = g++
BIN = bin
OBJ = obj
SRC = src
MAIN = $(SRC)/Main.cpp

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/Main.o
	$(CC) $(FLAGS) $(OBJ)/Main.o -o $@

$(OBJ)/Main.o: $(MAIN)
	$(CC) $(FLAGS) -c $(MAIN) -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz
