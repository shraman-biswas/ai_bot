CXX	=	gcc
FLAGS	=	-Wall -O3 -ggdb
SOURCE	=	main.c
BIN	=	main

all:
	$(CXX) $(FLAGS) $(SOURCE) -o $(BIN)

clean:
	rm -f *~ *o $(BIN)
