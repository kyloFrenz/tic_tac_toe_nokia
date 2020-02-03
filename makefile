CXX = g++
CXXFLAGS = -Wall -g -std=c++11 -Iinclude/

tic_tac_toe: tic_tac_toe.o player.o board.o gameplay.o
	$(CXX) $(CXXFLAGS) -o tic_tac_toe tic_tac_toe.o player.o board.o gameplay.o

tic_tac_toe.o: tic_tac_toe.cpp
	$(CXX) $(CXXFLAGS) -c tic_tac_toe.cpp

board.o: src/board.cpp include/board.hpp
	$(CXX) $(CXXFLAGS) -c src/board.cpp

player.o: src/player.cpp include/player.hpp
	$(CXX) $(CXXFLAGS) -c src/player.cpp

gameplay.o: src/gameplay.cpp include/gameplay.hpp include/board.hpp include/player.hpp
	$(CXX) $(CXXFLAGS) -c src/gameplay.cpp

clean:
	rm *.o
	rm tic_tac_toe