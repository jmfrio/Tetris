#include <iostream>
#include <vector>
#include <string>
#include "zPiece.h"
#include "Piece.h"

using namespace std;

zPiece :: zPiece(int size) : Piece(size)	{
	color = "red";
	//fillVec();
	r1= 0;
	c1= 4;
	r2= r1;		//0
	c2= c1-1;	//3
	r3= r1+1;	//1
	c3= c1;		//4
	r4= r1+1;	//1
	c4= c1+1;	//5
}


void zPiece :: rotate(){
	if ( r1 >= 1 && c4 >= 1 && c2 >= 1)	{
		numR = numR%4;
		switch ( numR ) {
			case 0:
				r1= r1+1;
				c1= c1+1;
				r2= r2;
				c2= c2+2;
				r3= r3;
				c3= c3;
				r4= r4+1;
				c4= c4-1;
				break;
			case 1:	
				r1=r1;
				c1=c1-1;
				r2= r2+1;
				c2= c2;
				r3= r3-1;
				c3= c3;
				r4= r4-2;
				c4= c4-1;
				break;
			case 2:
				r1= r1;
				c1= c1;
				r2= r2+1;
				c2= c2-1;
				r3= r3+1;
				c3= c3+1;
				r4= r4;
				c4= c4+2;
				break;
			case 3:	
				r1=r1-1;
				c1=c1;
				r2= r2-2;
				c2= c2-1;
				r3= r3;
				c3= c3-1;
				r4= r4+1;
				c4= c4;
				break;
		}
		numR++;
	}

}

void zPiece :: right(){
	Piece::right();
}
void zPiece :: left(){
	Piece::left();
}
void zPiece :: down(){
	Piece::down();
}
