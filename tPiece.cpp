//Brittany Harrington, Elizabeth Vista, Jessie Frio
//CSE 20212
////Final Project: Tetris
//tPiece function implementations

#include <iostream>
#include <vector>
#include <string>
#include "tPiece.h"
#include "Piece.h"

using namespace std;

tPiece :: tPiece(int size) : Piece(size)	{
	color = 6;
 	//set initial coordinates
	r1= 0;
	c1= 4;
	r2= r1+1;	
	c2= c1-1;	
	r3= r1+1; 	
	c3= c1;		
	r4= r1+1;	
	c4= c1+1;	
	numR = 0;
}

void tPiece :: rotate(){

	if ( r1 >=1 && c1 >=1 && c1 <=8 )	{
		numR= numR%4;
		switch ( numR ) {
			case 0:
				r1= r3;
				c1= c3+1;
				r2= r3-1;
				c2= c3;
				r4= r3+1;
				c4= c3;
				break;
			case 1:
				r1= r3+1;
				c1= c3;
				r2= r3;
				c2= c3+1;
				r4= r3;
				c4= c3-1;				
				break;
			case 2:
				r1= r3;
				c1= c3-1;
				r2= r3+1;
				c2= c3;
				r4= r3-1;
				c4= c3;
				break;
			case 3:
				r1= r3-1;
				c1= c3;
				r2= r3;
				c2= c3-1;
				r4= r3;
				c4= c3+1;
				break;
		}
		numR++;	

	}
}

void tPiece :: right(){
	Piece::right();
}
void tPiece :: left(){
	Piece::left();
}
void tPiece :: down(){
	Piece::down();
}
