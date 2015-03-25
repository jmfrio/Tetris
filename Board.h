// Elizabeth Vista
// Fundamentals of Computing II
// Final Project -- Tetris
// board.h -- board that holds Tetris pieces


#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "Piece.h"
#include "BoxPiece.h"
#include "LinePiece.h"
#include "lPiece.h"
#include "jPiece.h"
#include "sPiece.h"
#include "zPiece.h"
#include "tPiece.h"

using namespace std;

class Board {
	public:
		Board();                            // constructor
		void display();                     // output current board
		int isSpotFull(int, int);           // return 1 if piece is in spot (x,y), 0 otherwise
		void fillRow(int);                  // set values in a particular row
		int isRowFull(int);                 // returns 1 if row is full, 0 if not
		void deleteRow(int);                // deletes row (to be used when row is filled) 
		void addPiece(int);                 // put a new piece on the board
		int isGameOver();                   // to be checked after every piece finished falling, before next piece is made
		void updateCoordinates(); // set the board to match current coordinates of piece
	private:
		int width;                          // width of board
		int height;                         // height of board
		vector< vector<int> > board;        // 2D vector of ints
		vector< vector<int> > temp;         // temp board
		Piece newPiece;                     // currently falling piece
		int pieceType;                      // randomly generated type of next piece
		int newPieceR1;                     // when piece coordinates are updated, the previous ones are saved here
		int newPieceR2;                     // this way, the old coordinates can be set to 0
		int newPieceR3;
		int newPieceR4;
		int newPieceC1;
		int newPieceC2;
		int newPieceC3;
		int newPieceC4;
};


#endif

Board::Board() {
	width = 10;
	height = 20;

	vector<int> oneDvec;
	// fill a 1D vector with 0s
	for( int i=0; i<width; i++ ) {
		oneDvec.push_back(0);
		cout << oneDvec[i];
	}
	cout << endl;
	
	vector< vector<int> > twoDvec;
	// fill a 2D vector with 1D vectors of 0s
	for( int i=0; i<height; i++ ) {
		board.push_back(oneDvec);
	}
	
	srand(time(NULL));
	pieceType = (rand()%7) + 1;
	addPiece( pieceType );
}

void Board::display() {
	for( int row=0; row<height; row++ ) {
		for( int col=0; col<width; col++ ) {
			cout << board[row][col];
		}
		cout << endl;
	}
}

int Board::isSpotFull( int row, int column ) {
	if( board[row][column] == 1 ) {
		return 1;
	} else {
		return 0;
	}
}

void Board::fillRow(int row) {
	int temp;
	cout << "Please enter the " << width << " values to be placed in the row, separated by spaces:" << endl;
	for( int i=0; i<width; i++ ) {
		cin >> temp;
		board[row][i] = temp;
	}
}

int Board::isRowFull( int row ) {
	int isFull = 1;                            // assumes row is full
	for( int i=0; i<width; i++ ) {
		if( board[row][i] == 0 ) {
			isFull = 0;            // if a 0 is found (no ID#) then row is not full
		}
	}
	return isFull;
}

void Board::deleteRow( int row ) {
	for( int i=row; i>0; i-- ) { // each row from the full row up
		for( int j=0; j<width; j++ ) { // each position in that row
			board[i][j] = board[i-1][j]; // set equal to row above
		}
	}
	for( int j=0; j<width; j++ ) {
		board[height-1][j] = 0; // set first row to 0s
	}
}

void Board::addPiece( int pieceType ) {
	switch( pieceType ) {
		case 1:
			newPiece = new BoxPiece();
		case 2:
			newPiece = new LinePiece();
		case 3:
			newPiece = new lPiece();
		case 4:
			newPiece = new jPiece();
		case 5:
			newPiece = new tPiece();
		case 6:
			newPiece = new zPiece();
		case 7:
			newPiece = new sPiece();
	}
	
	board[newPiece.r1][newPiece.c1] = 1;
	board[newPiece.r2][newPiece.c2] = 1;
	board[newPiece.r3][newPiece.c3] = 1;
	board[newPiece.r4][newPiece.c4] = 1;
	newPieceR1 = newPiece.r1;
	newPieceR2 = newPiece.r2;
	newPieceR3 = newPiece.r3;
	newPieceR4 = newPiece.r4;
	newPieceC1 = newPiece.c1;
	newPieceC2 = newPiece.c2;
	newPieceC3 = newPiece.c3;
	newPieceC4 = newPiece.c4;
}

int Board::isGameOver() {
	int isOver = 0;                         // assumes that game is not over
	for( int i=0; i<width; i++ ) {
		if( board[0][i] == 1 ) {
			isOver = 1;             // if any spot in top row is full, game is over
		}
	}
	return( isOver );
}

void Board::updateCoordinates() {
	board[newPieceR1][newPieceC1] = 0;
	board[newPieceR2][newPieceC2] = 0;
	board[newPieceR3][newPieceC3] = 0;
	board[newPieceR4][newPieceC4] = 0;

	board[newPiece.r1][newPiece.c1] = 1;
	board[newPiece.r2][newPiece.c2] = 1;
	board[newPiece.r3][newPiece.c3] = 1;
	board[newPiece.r4][newPiece.c4] = 1;

	newPieceR1 = newPiece.r1;
	newPieceR2 = newPiece.r2;
	newPieceR3 = newPiece.r3;
	newPieceR4 = newPiece.r4;
	newPieceC1 = newPiece.c1;
	newPieceC2 = newPiece.c2;
	newPieceC3 = newPiece.c3;
	newPieceC4 = newPiece.c4;
}




