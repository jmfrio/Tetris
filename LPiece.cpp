#include <iostream>
#include <vector>
#include <string>
#include "LPiece.h"
#include "Piece.h"

using namespace std;

LPiece::LPiece(int size) : Piece(size)	{
	color="yellow";
	fillVec();	
}

void LPiece::fillVec()	{
	shape[0][2]= 1;
	for (int i=0; i<(Piece::getSize()); i++)	{
		shape[1][i]= 1;
	}
}
