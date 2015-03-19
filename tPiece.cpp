#include <iostream>
#include <vector>
#include <string>
#include "tPiece.h"
#include "Piece.h"

using namespace std;

tPiece :: tPiece(int size) : Piece(size)	{
	color = "purple";
 	fillVec();
}

void tPiece :: fillVec()	{
	shape[0][1] = 1;
		for( int i=0; i<(Piece::getSize()); i++ ){
			shape[1][i] = 1;
	  	}
}
