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

/*void zPiece :: fillVec(){
	for( int i=0; i<(Piece::getSize() - 1); i++){
		shape[0][i] = 1;
	}
	for( int j=1; j<(Piece::getSize()); j++ ){
		shape[1][j] = 1;
	}
}*/

void zPiece :: rotate(){
	numR = numR%2;
	switch ( numR ) {
		case 0:
			r2= r1-1;
			c2= c1;
			r3= r1;
			c3= c1-1;
			r4= r1+1;
			c4= c1-1;
			break;
		case 1:
			r2= r1;
			c2= c1+1;
			r3= r1-1;
			c3= c1;
			r4= r1-1;
			c4= r1-1;
			break;
	}
	numR++;

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
