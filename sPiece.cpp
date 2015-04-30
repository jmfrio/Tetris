//Brittany Harrington, Elizabeth Vista, Jessie Frio
//CSE 20212
////Final Project: Tetris
//sPiece function implementations

#include <iostream>
#include <vector>
#include <string>
#include "sPiece.h"
#include "Piece.h"

using namespace std;

sPiece :: sPiece(int size) : Piece(size)	{
	color = 7;
	r1= 0;
	c1= 4;
	r2= r1;		//0
	c2= c1+1;	//5
	r3= r1+1;	//1
	c3= c1;		//4
	r4= r1+1;	//1
	c4= c1-1;	//3
	numR=0;

}


void sPiece :: rotate(){
	if (r1 >= 1 && c3 <= 8 && c1 <= 8 )	{
		numR= numR%2;
		switch ( numR ) {
			case 0 :
				r2= r1+1;
				c2= c1;
				r3= r1;
				c3= c1-1;
				r4= r1-1;
				c4= c1-1;
				break;
			case 1 :
				r2= r1;
				c2= c1-1;
				r3= r1-1;
				c3= c1;
				r4= r1-1;
				c4= c1+1;
				break;
		}		
		numR++;
	}
}


void sPiece :: right(){
	Piece::right();
}
void sPiece :: left(){
	Piece::left();
}
void sPiece :: down(){
	Piece::down();
}
