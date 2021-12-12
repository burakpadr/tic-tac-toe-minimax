CC = g++ # CC: C (C)ompiler
RESOURCES = *.cpp
EXEC_NAME = exe

all: compile run

compile:
	$(CC) $(RESOURCES) -o $(EXEC_NAME)

run:
	./$(EXEC_NAME)
