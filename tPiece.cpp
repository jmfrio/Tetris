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
<<<<<<< HEAD
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
			c2= c1+1;
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
			c4= c1+1;
			break;
=======
	if ( r1 >=1 && c1 >=1 && c1 <=8 )	{
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
				c2= c1+1;
				r3= r1-1;
				c3= c1;
				r4= r1-1;
				c4= c1-1;
				break;
			case 2:
				r2= r1-1;
				c2= c1+1;
				r3= r1;
				c3= c1+1;
				r4= r1+1;
				c4= c1+1;
				break;
			case 3:
				r2= r1+1;
				c2= c1-1;
				r3= r1+1;
				c3= c1;
				r4= r1+1;
				c4= c1+1;
				break;
		}
		numR++;	
>>>>>>> 031ee40a1e3ca24fa9748e25e475c9d177089fbc
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
