all: tetris

tetris:
	g++ *.cpp -lSDL2 -o tetris
clean:
	-rm tetris
