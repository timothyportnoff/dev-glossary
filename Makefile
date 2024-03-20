#Compiler: gcc for C program, g++ for C++:
CC = g++
#CC = gcc

#Compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS = -g -Wall

#Libraries
#  -lncurses	Adds graphical support is using the ncurses library
LIBS = -lncurses

all: main.cc
	${CC} ${CFLAGS} -o a.out main.cc ${LIBS}

#.PHONY rule keeps make from doing something with a file named clean
.PHONY: clean

clean:
	rm -f *.o
