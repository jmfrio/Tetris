#include <iostream>
#include <vector>
#include <string>
#include "jPiece.h"
#include "Piece.h"

using namespace std;

jPiece::jPiece(int size) : Piece(size)	{
	color="green";
//	fillVec();	
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

//void jPiece::fillVec()	{
//	shape[0][0]= 1;
//	for (int i=0; i<(Piece::getSize()); i++)	{
//		shape[1][i]= 1;
//	}
//}

void jPiece::rotate()	{
	numR=numR%4;
	if (c4 <= 8)	{
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
	cout << "NumR: " << numR << endl << endl;
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
