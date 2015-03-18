Piece: test.o Piece.o
	g++ -o Piece test.o Piece.o

test.o: test.cpp
	g++ -c test.cpp

Piece.o: Piece.cpp Piece.h
	g++ -c Piece.cpp

clean:
	rm Piece *.o
