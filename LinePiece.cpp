
//Brittany Harrington, Elizabeth Vista, Jessie Frio
////CSE 20212
////Final Project: Tetris
//LinePiece.cpp function implementations

#include <iostream>
#include <string>
#include <vector>
#include "LinePiece.h"
#include "Piece.h"

using namespace std;

LinePiece :: LinePiece(int size) : Piece(size) {
	color = 2;
	//set initial coordinates;
	r2= 0;
	c2= 4;
	r1= r2;
	c1= c2-1;
	r3= r2;
	c3= c2+1;
	r4= r2;
	c4= c2+2;
	numR = 0;
}

//function rotation instructions for line coordinates
void LinePiece::rotate()	{
	//only rotate if within bounds of board
	if ( r2 >= 1 && c2 >= 1 && c2 <= 7 ) { 
		numR = numR%2;
		switch (numR) {
			case 0:
				//first 90 degree rotation
				r1= r2-1;
				c1= c2;
				r3= r2+1;
				c3= c2;
				r4= r2+2;	
				c4= c2;
				break;
			case 1:
				//second 90 degree rotation
				r1= r2;
				c1= c2-1;
				r3= r2;
				c3= c2+1;
				r4= r2;
				c4= c2+2;
				break;
		}
		//cout << "NumR : " << numR << endl << endl;
		numR++;
	}
}

void LinePiece :: right(){
	Piece::right();
}
void LinePiece :: left(){
	Piece::left();
}
void LinePiece :: down(){
	Piece::down();
}
