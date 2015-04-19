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
#include "Board.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	Board game;
	game.display();
	cout << "finished initial display" << endl;
	game.addPiece();
	cout << "finished adding piece" << endl;
	while( ! game.pieceFinishedFalling() ) {
		game.down();
		cout << endl << endl;
		game.display();
	}
	game.setBoard();
	game.addPiece();
	game.left();
	game.left();
	while( ! game.pieceFinishedFalling() ) {
		game.down();
		cout << endl << endl;
		game.display();
	}
	cout << endl << endl;
	game.display();



//	game.display();
//	cout << "displayed board with new piece " << endl;


	//work with first piece
/*	game.right();
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
*/
}


