//Elizabeth Vista, Brittany Harrington, Jessie Frio
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
#include <SDL2/SDL_ttf.h>
#include <string>

class Board {
	public:
		Board();                            // constructor
		int isSpotFull(int, int);           // return 1 if piece is in spot (x,y), 0 otherwise
		int isRowFull(int);                 // returns 1 if row is full, 0 if not
		void deleteRow(int);                // deletes row (to be used when row is filled) 
		int getSpotNumber( int, int);	    // returns spot on the board
		void addPiece();                    // put a new piece on the board
		int isGameOver();                   // to be checked after every piece finished falling, before next piece is made
		void updateCoordinates();           // set the board to match current coordinates of piece
		void setBoard();                    // set board=temp (to be used when piece is finished falling)
		void right();			    // function to move piece on board to the right 
		void left();			    // function to move piece on board to the left
		void down();			    // function to move piece on board down
		void rotate();			    // function to rotate a piece on the board
		int pieceFinishedFalling();		//function that checks if a piece is finished falling
		int getLevel();				//function that fetches the current level

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
	//initialize 10x20 board
	width = 10;
	height = 20;
	score=0;
	level=1;
	rows_deleted=0;	
	rows_deleted_total=0;
	
	//fill board by pushing back rows of 1D vectors
	vector<int> oneDvec;
	for( int i=0; i<width; i++ ) {
		oneDvec.push_back(0);
	}
	
	vector< vector<int> > twoDvec;
	for( int i=0; i<height; i++ ) {
		board.push_back(oneDvec);
		temp.push_back(oneDvec);
	}

	//seed random number generator for addPiece function	
	srand(time(NULL));

}

//function to check if a spot is full--used in game.cpp file
int Board::isSpotFull( int row, int column ) {
	//if a spot is filled with any number, return true
	if( temp[row][column] != 0 || board[row][column] != 0 ) {
		return 1;
	} else {
		return 0;
	}
}

//function that checks if a given row is full and ready to be deleted
int Board::isRowFull( int row ) {
	int isFull = 1;                            // assumes row is full
	for( int i=0; i<width; i++ ) {
		if( board[row][i] == 0 ) {
			isFull = 0;            // if a 0 is found (no ID#) then row is not full
		}
	}
	return isFull;
}

//function that returns location of spot on the board that is colored 
int Board::getSpotNumber( int row, int col){

	if( board[row][col] !=0 ) return board[row][col];

	else if ( temp[row][col] != 0 ) return temp[row][col];

}

//function to delete a full row
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

//function to add piece to board
void Board::addPiece() {
	int pieceType;
	//instantiate base piece class pointer
	Piece * piece_ptr;
	
	//pick a random piece type between 1-7 
	//create new piece of that random type but calling individual constructors
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
	//call function to update temporary board with new piece
	updateCoordinates();	
}

//function to check whether the game has ended
int Board::isGameOver() {
	int isOver = 0;                         // assumes that game is not over
	for( int i=0; i<width; i++ ) {
		if( board[0][i] != 0 ) {	
			isOver = 1;             // if any spot in top row is full, game is over
		}
	}
	return( isOver );
}

//update the temporary board to add a new piece 
void Board::updateCoordinates() {
	for( int i=0; i<height; i++ ) {
		for( int j=0; j<width; j++ ) {
			temp[i][j] = board[i][j];
		}
	}
	//fill spaces where new piece is placed with new piece's color
	temp[newPiece->r1][newPiece->c1] = newPiece->color;
	temp[newPiece->r2][newPiece->c2] = newPiece->color;
	temp[newPiece->r3][newPiece->c3] = newPiece->color;
	temp[newPiece->r4][newPiece->c4] = newPiece->color;
}

//update regular board to match temporary board
void Board::setBoard() {
	for( int i=0; i<height; i++ ) {
		for( int j=0; j<width; j++ ) {
			board[i][j] = temp[i][j];
		}
	}

	//if a row is full, delete that row and increment number of rows that have been deleted (1) with that turn and (2) since the level began
	for( int i=0; i<height; i++ ) {
		if( isRowFull(i) ) {
			deleteRow(i);	//delete current row
			rows_deleted++;	//increment number of rows deleted with this play
			rows_deleted_total++;	//increment total number of rows deleted
		}
	}
	//every ten rows, move up a level
	if (rows_deleted_total % 5 == 0 && rows_deleted_total != 0)	{
		level++;	
		rows_deleted_total=0;		//reset rows_deleted to zero so that level doesn't go up twice in a row	
		cout << "Level " << level << endl;
	}
	//update score based on number of rows deleted with that play
	//equation for score --> points = m*level -- where m is a set value based on number of rows deleted and level is the current level
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
	rows_deleted=0;	//reset number of rows deleted at the end of a play
}

//function to move the current working piece to the right
void Board::right()	{
	//check to make sure that there is no piece directly to the right of the falling piece
	if ( board[newPiece->r1][newPiece->c1+1]==0 && board[newPiece->r2][newPiece->c2+1]==0 && 
	     board[newPiece->r3][newPiece->c3+1]==0 && board[newPiece->r4][newPiece->c4+1]==0 ) {	
		//if empty, called piece function to move piece 
		newPiece->right();	
		//reupdate temporary board with this movement
		updateCoordinates();	
	}
}

//function to move the current working piece to the left
void Board::left()	{
	//check to make sure that there is piece directly to the left of the falling piece
	if ( board[newPiece->r1][newPiece->c1-1]==0 && board[newPiece->r2][newPiece->c2-1]==0 && 
	     board[newPiece->r3][newPiece->c3-1]==0 && board[newPiece->r4][newPiece->c4-1]==0 ) {
		//if able, move piece to left using piece left() function and update temp board
		newPiece->left();	
		updateCoordinates();	
	}
}

//function to move the current working piece down
void Board::down()	{
	newPiece->down();	
	updateCoordinates();	
}

//function to rotate current working piece 
void Board::rotate()	{
	newPiece-> rotate();
	updateCoordinates();
}

//function to check if piece is finished falling (i.e. hit the bottom or hit another piece)
int Board::pieceFinishedFalling() {
	//if piece is at bottom (r==19) or piece is touching another piece, return true 
	if( (newPiece->r1)==19 || (newPiece->r2)==19 || (newPiece->r3)==19 || (newPiece->r4)==19 || 
		board[newPiece->r1+1][newPiece->c1]!=0 || board[newPiece->r2+1][newPiece->c2]!=0 || 
		board[newPiece->r3+1][newPiece->c3]!=0 || board[newPiece->r4+1][newPiece->c4]!=0 )
		return 1;
	else
		return 0;
}

//return current level
int Board::getLevel(){
	return level;
}


#endif
