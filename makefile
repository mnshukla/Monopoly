CXXFLAGS=-Wall -g -o
SRCS = Space.cpp Action.cpp Gameboard.cpp Player.cpp Bank.cpp MoveAction.cpp GotoAction.cpp LCard.cpp IGCard.cpp Card.cpp main.cpp 

all: main

main: *.cpp *.h
	g++ $(SRCS) $(CXXFLAGS) main

clean:
	rm -f *.o *~ main
