#include <iostream>
#include <vector>
#include <string>
#include "Lpiece.h"
#include "Piece.h"

using namespace std;

L2::L2(int size) : Piece(size)	{
	color="yellow";
	fillVec();	
}

void L2::fillVec()	{
	shape[0][2]=(Piece::getidNum());
	for (int i=0; i<(Piece::getSize()); i++)	{
		shape[1][i]=(Piece::getidNum());
	}
}
