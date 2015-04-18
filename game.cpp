// Elizabeth Vista
// Fundamentals of Computing II
// Final Project -- Tetris
// game.h -- driver program for board class

#include "Piece.h"
#include "BoxPiece.h"
#include "LinePiece.h"
#include "LPiece.h"
#include "jPiece.h"
#include "sPiece.h"
#include "zPiece.h"
#include "tPiece.h"

#include <iostream>
#include "Board.h"
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	Board game;
	// display board
	game.display();
	cout << "finished initial display" << endl;
	game.addPiece();
	cout << "finished adding piece" << endl;
	game.display();
	cout << "displayed board with new piece " << endl;


	//work with first piece
	game.right();
	game.display();
	game.right();
	game.display();
	game.down();
	game.down();
	game.down();
	game.down();
	game.down();
	game.down();
	game.display();


	game.rotate();
	game.display();
	game.rotate();
	game.display();
	game.rotate();
	game.display();
	game.rotate();
	game.display();
	//add second piece and work with that
	game.addPiece();
	cout << "finished adding piece" << endl;
	game.display();
	cout << "displayed board with new piece " << endl;
}


