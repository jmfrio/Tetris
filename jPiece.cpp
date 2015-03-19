#include <iostream>
#include <vector>
#include <string>
#include "jPiece.h"
#include "Piece.h"

using namespace std;

jPiece::jPiece(int size) : Piece(size)	{
	color="green";
	fillVec();	
}

void jPiece::fillVec()	{
	shape[0][0]= 1;
	for (int i=0; i<(Piece::getSize()); i++)	{
		shape[1][i]= 1;
	}
}
