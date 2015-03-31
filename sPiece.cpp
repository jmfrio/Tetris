#include <iostream>
#include <vector>
#include <string>
#include "sPiece.h"
#include "Piece.h"

using namespace std;

sPiece :: sPiece(int size) : Piece(size)	{
	color = "green";
 	//fillVec();
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

/*void sPiece :: fillVec()	{
	for( int i=1; i<(Piece::getSize()); i++){
		shape[0][i] = 1;
	}
	for( int j=0; j<(Piece::getSize() - 1); j++){
    		shape[1][j] = 1;
  	}
}*/

void sPiece :: rotate(){
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

void sPiece :: right(){
	Piece::right();
}
void sPiece :: left(){
	Piece::left();
}
void sPiece :: down(){
	Piece::down();
}
