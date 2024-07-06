CC = gcc
FLAGS = -g -Wall -Wextra -Werror
FILES = hash.c storage.c utils.c sudoku.c main.c
BIN_NAME = solve-this
ARGS = 250030901010004000407000208005200000000098100040003000000360072070000003903000604
default:
	$(CC) $(FLAGS) $(FILES) -o $(BIN_NAME)

valgrind-check:
	valgrind --leak-check=full --show-leak-kinds=all ./$(BIN_NAME) $(ARGS) 2> output.valgrind