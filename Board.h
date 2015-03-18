// Elizabeth Vista
// Fundamentals of Computing II
// Final Project -- Tetris
// board.h -- board that holds Tetris pieces


#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Board {
	public:
		Board();                            // constructor
		void display();                     // output current board
		int getID(int, int);                // return ID held in spot (x,y)
		void fillRow(int);                  // set values in a particular row
		int isRowFull(int);                 // returns 1 if row is full, 0 if not
		void deleteRow(int);                // deletes row (to be used when row is filled) 
	private:
		int width;                          // width of board
		int height;                         // height of board
		vector< vector<int> > board;        // 2D vector of ints
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

void Board::deleteRow( int row ) {
	for( int i=row; i>0; i-- ) {           // each row from the full row up
		for( int j=0; j<width; j++ ) {        // each position in that row
			board[i][j] = board[i-1][j];  // set equal to row above
		}
	}

	for( int j=0; j<width; j++ ) {
		board[height-1][j] = 0;               // set first row to 0s
	}
}




