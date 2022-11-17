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
HOARE = $(SRC)/Hoare.cpp
HOARE_H = $(SRC)/Hoare.h
LOMUTO = $(SRC)/Lomuto.cpp
LOMUTO_H = $(SRC)/Lomuto.h
MEDIAN = $(SRC)/Median.cpp
MEDIAN_H = $(SRC)/Median.h
OBJ_FILES = $(OBJ)/Main.o $(OBJ)/Hoare.o $(OBJ)/Lomuto.o $(OBJ)/Median.o

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $@

$(OBJ)/Main.o: $(MAIN) $(HOARE_H) $(LOMUTO_H) $(MEDIAN_H)
	$(CC) $(FLAGS) -c $(MAIN) -o $@

$(OBJ)/Hoare.o: $(HOARE) $(HOARE_H)
	$(CC) $(FLAGS) -c $(HOARE) -o $@

$(OBJ)/Lomuto.o: $(LOMUTO) $(LOMUTO_H)
	$(CC) $(FLAGS) -c $(LOMUTO) -o $@

$(OBJ)/Median.o: $(MEDIAN) $(MEDIAN_H)
	$(CC) $(FLAGS) -c $(MEDIAN) -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz
