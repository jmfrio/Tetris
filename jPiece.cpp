//Brittany Harrington, Elizabeth Vista, Jessie Frio
//CSE 20212
//Final Project: Tetris
//function implementations for jPiece.cpp

#include <iostream>
#include <vector>
#include <string>
#include "jPiece.h"
#include "Piece.h"

using namespace std;

jPiece::jPiece(int size) : Piece(size)	{
	color=3;
	//set initial conditions
	r1=0;
	c1=3;
	r2=r1+1;
	c2=c1;
	r3=r1+1;
	c3=c1+1;
	r4=r1+1;
	c4=c1+2;	
	numR=0;	
}

//function that contains specific rotation instructions for coordinates of jPiece
void jPiece::rotate()	{
	numR=numR%4;
	//only rotate if rotating will keep piece within board bounds
	if (c4 <= 8 && c3 >=1)	{
		switch (numR) {
			case 0:
				//first 90 degree rotation
				c1=c1+2;
				r2=r2-1;
				c2=c2+1;
				r4=r4+1;
				c4=c4-1;	
				break;
			case 1:
				//second 90 degree rotation
				r1=r1+2;
				r2=r2+1;
				c2=c2+1;
				r4=r4-1;
				c4=c4-1;
				break;
			case 2:
				//third 90 degree rotation
				c1=c1-2;
				r2=r2+1;
				c2=c2-1;
				r4=r4-1;
				c4=c4+1;
				break;
			case 3:
				//fourth 90 degree rotation
				r1=r1-2;
				r2=r2-1;
				c2=c2-1;
				r4=r4+1;
				c4=c4+1;
				break;
		}
		//cout << "NumR: " << numR << endl << endl;
		numR++;
	}
}


void jPiece :: right(){
	Piece::right();
}
void jPiece :: left(){
	Piece::left();
}
void jPiece :: down(){
	Piece::down();
}
