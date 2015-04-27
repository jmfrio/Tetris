//pElizabeth Vista
// Fundamentals of Computing II
// Final Project -- Tetris
// board.h -- board that holds Tetris pieces


#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include "BoxPiece.h"
#include "LinePiece.h"
#include "LPiece.h"
#include "jPiece.h"
#include "sPiece.h"
#include "zPiece.h"
#include "tPiece.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>


using namespace std;

#include <SDL2/SDL.h>
#include <string>

class Board {
	public:
		Board();                            // constructor
		void display();                     // output current board
		int isSpotFull(int, int);           // return 1 if piece is in spot (x,y), 0 otherwise
		void fillRow(int);                  // set values in a particular row
		int isRowFull(int);                 // returns 1 if row is full, 0 if not
		void deleteRow(int);                // deletes row (to be used when row is filled) 
		int getSpotNumber( int, int);
		void addPiece();                    // put a new piece on the board
		int isGameOver();                   // to be checked after every piece finished falling, before next piece is made
		void updateCoordinates();           // set the board to match current coordinates of piece
		void setBoard();                    // set board=temp (to be used when piece is finished falling)
		void right();
		void left();
		void down();
		void rotate();
		int pieceFinishedFalling();
		int getLevel();

	private:
		int score;			//score of game
		int level;			//current level
		int rows_deleted;		//number of rows deleted on that turn
		int rows_deleted_total;		//total number of rows that have been deleted
		int width;                          // width of board
		int height;                         // height of board
		vector< vector<int> > board;        // 2D vector of ints
		vector< vector<int> > temp;         // temp board
		Piece *newPiece;                    // currently falling piece
		int pieceType;                      // randomly generated type of next piece
};

Board::Board() {
	width = 10;
	height = 20;
	score=0;
	level=1;
	rows_deleted=0;
	rows_deleted_total=0;
	
	vector<int> oneDvec;
	// fill a 1D vector with 0s
	for( int i=0; i<width; i++ ) {
		oneDvec.push_back(0);
//		cout << oneDvec[i];
	}
//	cout << endl;
	
	vector< vector<int> > twoDvec;
	// fill a 2D vector with 1D vectors of 0s
	for( int i=0; i<height; i++ ) {
		board.push_back(oneDvec);
		temp.push_back(oneDvec);
	}
	
	srand(time(NULL));

}

void Board::display() {
	for( int row=0; row<height; row++ ) {
		for( int col=0; col<width; col++ ) {
			cout << temp[row][col];
		}
		cout << endl;
	}
}

int Board::isSpotFull( int row, int column ) {
	if( temp[row][column] != 0 || board[row][column] != 0 ) {
		return 1;
	} else {
		return 0;
	}
}

void Board::fillRow(int row) {
	int input;
	cout << "Please enter the " << width << " values to be placed in the row, separated by spaces:" << endl;
	for( int i=0; i<width; i++ ) {
		cin >> input;
		board[row][i] = input;
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

int Board::getSpotNumber( int row, int col){

if( board[row][col] !=0 ) return board[row][col];

else if ( temp[row][col] != 0 ) return temp[row][col];

}

void Board::deleteRow( int row ) {
	for( int i=row; i>0; i-- ) { // each row from the full row up
		for( int j=0; j<width; j++ ) { // each position in that row
			board[i][j] = board[i-1][j]; // set equal to row above
		}
	}
	for( int j=0; j<width; j++ ) {
		board[0][j] = 0; // set first row to 0s
	}
}

void Board::addPiece() {
	int pieceType;
	Piece * piece_ptr;
	
	pieceType = (rand() % 7) + 1;
	switch( pieceType ) {
		case 1:
			newPiece = new BoxPiece(3);
			break;
		case 2:
			newPiece = new LinePiece(3);
			break;
		case 3:
			newPiece = new LPiece(3);
			break;
		case 4:
			newPiece = new jPiece(3);
			break;
		case 5:
			newPiece = new tPiece(3);
			break;
		case 6:
			newPiece = new zPiece(3);
			break;
		case 7:
			newPiece = new sPiece(3);
			break;
	}
//	cout << "new piece is number: " << pieceType << endl;
//	cout << "entering updateCoordinates function" << endl;
	updateCoordinates();	
//	cout << "exiting updateCoordinates function" << endl;
//	setBoard();
}

int Board::isGameOver() {
	int isOver = 0;                         // assumes that game is not over
	for( int i=0; i<width; i++ ) {
		if( board[0][i] != 0 ) {
			isOver = 1;             // if any spot in top row is full, game is over
		}
	}
	return( isOver );
}

void Board::updateCoordinates() {
	// revert back to board (delete previous piece position)
//	cout << "entering for loop" << endl;
	for( int i=0; i<height; i++ ) {
		for( int j=0; j<width; j++ ) {
			temp[i][j] = board[i][j];
		}
	}
//	cout << "deleted previous piece position" << endl;
	// put updated piece coordinates onto temp board
	temp[newPiece->r1][newPiece->c1] = newPiece->color;
	temp[newPiece->r2][newPiece->c2] = newPiece->color;
	temp[newPiece->r3][newPiece->c3] = newPiece->color;
	temp[newPiece->r4][newPiece->c4] = newPiece->color;
}

void Board::setBoard() {
	for( int i=0; i<height; i++ ) {
		for( int j=0; j<width; j++ ) {
			board[i][j] = temp[i][j];
		}
	}
	for( int i=0; i<height; i++ ) {
		if( isRowFull(i) ) {
			deleteRow(i);
			rows_deleted++;	//increment number of rows deleted with this play
			rows_deleted_total++;	//increment total number of rows deleted
		}
	}
	//every ten rows, move up a level
	if (rows_deleted_total % 4 == 0 && rows_deleted_total != 0)	{
		level++;
		cout << "Level " << level << endl;
	}
	if (rows_deleted == 1)	{
		score=score + (400)*(level);
	}	
	else if (rows_deleted == 2)	{
		score=score + (1000)*(level);
	}
	else if (rows_deleted == 3)	{
		score=score + (3000)*(level);
	}
	else if (rows_deleted >= 4)	{
		score=score + (12000)*(level);
	}
	cout << "Score= " << score << endl;
	rows_deleted=0;
}

void Board::right()	{
	if ( board[newPiece->r1][newPiece->c1+1]==0 && board[newPiece->r2][newPiece->c2+1]==0 && 
	     board[newPiece->r3][newPiece->c3+1]==0 && board[newPiece->r4][newPiece->c4+1]==0 ) {	
	newPiece->right();	
	updateCoordinates();	
//	setBoard();
	}
}

void Board::left()	{
	if ( board[newPiece->r1][newPiece->c1-1]==0 && board[newPiece->r2][newPiece->c2-1]==0 && 
	     board[newPiece->r3][newPiece->c3-1]==0 && board[newPiece->r4][newPiece->c4-1]==0 ) {
	newPiece->left();	
	updateCoordinates();	
//	setBoard();
	}
}

void Board::down()	{
	newPiece->down();	
	updateCoordinates();	
//	setBoard();
}

void Board::rotate()	{
//	cout << "entering board rotate function" << endl;
	newPiece-> rotate();
	updateCoordinates();
//	setBoard();
}

int Board::pieceFinishedFalling() {
	if( (newPiece->r1)==19 || (newPiece->r2)==19 || (newPiece->r3)==19 || (newPiece->r4)==19 || 
		board[newPiece->r1+1][newPiece->c1]!=0 || board[newPiece->r2+1][newPiece->c2]!=0 || 
		board[newPiece->r3+1][newPiece->c3]!=0 || board[newPiece->r4+1][newPiece->c4]!=0 )
		return 1;
	else
		return 0;
}

int Board::getLevel(){
	return level;
}


#endif
