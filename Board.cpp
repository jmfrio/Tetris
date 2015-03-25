// Board.cpp -- implementation of Board.h functions

#include <iostream>
#include <vector>
#include <algorithm>
#include "Board.h"
#include "Piece.h"
#include "L1.h"
#include "L2.h"
#include "Box.h"
// add all piece classes
using namespace std;

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
}

void Board::display() {
	for( int row=0; row<height; row++ ) {
		for( int col=0; col<width; col++ ) {
			cout << board[row][col];
		}
		cout << endl;
	}
}

int Board::getID( int row, int column ) {
	return board[row][column];
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

