#include <iostream>
#include <vector>
#include <string>
#include "LPiece.h"
#include "Piece.h"

using namespace std;

LPiece::LPiece(int size) : Piece(size)	{
	color="yellow";
//	fillVec();
	//set first coordinates (r1,c1) to upper right corner of L
	//other 3 points based on (r1,c1)
	r1=0;
	c1=5;
	r2=r1+1;
	c2=c1;
	r3=r1+1;
	c3=c1-1;
	r4=r1+1;
	c4=c1-2;	
	numR=0;
}

void LPiece::rotate()	{
	numR=numR%4;

	if ( c3 <= 7 && c3 >= 1)	{ 
	switch (numR) {
		case 0:
			//first 90 degree rotation
			r1=r1+2;
			r2=r2+1;
			c2=c2-1;
			r4=r4-1;
			c4=c4+1;	
			break;
		case 1:
			//second 90 degree rotation
			c1=c1-2;
			r2=r2-1;
			c2=c2-1;
			r4=r4+1;
			c4=c4+1;
			break;
		case 2:
			//third 90 degree rotation
			r1=r1-2;
			r2=r2-1;
			c2=c2+1;
			r4=r4+1;
			c4=c4-1;
			break;
		case 3:
			//fourth 90 degree rotation
			c1=c1+2;
			r2=r2+1;
			c2=c2+1;
			r4=r4-1;
			c4=c4-1;
			break;
	}
	cout << "NumR: " << numR << endl << endl;
	numR++;
	}
}

//void LPiece::fillVec()	{
//	shape[0][2]= 1;
//	
//	for (int i=0; i<(Piece::getSize()); i++)	{
//		shape[1][i]= 1;
//	}
//}


void LPiece :: right(){
	Piece::right();
}
void LPiece :: left(){
	Piece::left();
}
void LPiece :: down(){
	Piece::down();
}
