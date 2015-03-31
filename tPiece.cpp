#include <iostream>
#include <vector>
#include <string>
#include "tPiece.h"
#include "Piece.h"

using namespace std;

tPiece :: tPiece(int size) : Piece(size)	{
	color = "purple";
 	//fillVec();
	r1= 0;
	c1= 5;
	r2= r1+1;	
	c2= c1-1;	
	r3= r1+1; 	
	c3= c1;		
	r4= r1+1;	
	c4= c1+1;	
	numR = 0;
}

/*void tPiece :: fillVec()	{
	shape[0][1] = 1;
		for( int i=0; i<(Piece::getSize()); i++ ){
			shape[1][i] = 1;
	  	}
}*/

void tPiece :: rotate(){
	numR= numR%4;
	switch ( numR ) {
		case 0:
			r2= r1-1;
			c2= c1-1;
			r3= r1;
			c3= c1-1;
			r4= r1+1;
			c4= c1-1;
			break;
		case 1:
			r2= r1-1;
			c2= c1+1
			r3= r1-1;
			c3= c1;
			r4= r1-1;
			c4= c1-1;
			break;
		case 2:
			r2= r1-1;
			c2= c1+1;
			r3= r1;
			c3= c1;
			r4= r1+1;
			c4= c1+1;
			break;
		case 3:
			r2= r1+1;
			c2= c1-1;
			r3= r1+1;
			c3= c1;
			r4= r1+1;
			c4= c1+1
			break;
	}
	numR++;	
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
