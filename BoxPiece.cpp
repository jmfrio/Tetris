//Brittany Harrington, Elizabeth Vista, Jessie Frio
//CSE 20212
//Final Project: Tetris
//BoxPiece function implementations

#include <iostream>
#include <string>
#include <vector>
#include "BoxPiece.h"
#include "Piece.h"

using namespace std;

BoxPiece :: BoxPiece(int size) : Piece(size)	{
	color = 4;
//	set initial coordinates
	r1=0;
	c1=3;
	r2=r1;
	c2=c1+1;
	r3=r1+1;
	c3=c1+1;
	r4=r1+1;
	c4=c1;
	numR=0;

}

void BoxPiece::rotate() {
//box does not rotate
}

void BoxPiece :: right(){
	Piece::right();
}
void BoxPiece :: left(){
	Piece::left();
}
void BoxPiece :: down(){
	Piece::down();
}
