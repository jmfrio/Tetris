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
	game.addPiece();
	game.display();
}




