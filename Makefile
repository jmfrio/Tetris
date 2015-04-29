all: tetris

tetris:
	g++ *.cpp -lSDL2 -lSDL_ttf -o tetris
clean:
	-rm tetris
