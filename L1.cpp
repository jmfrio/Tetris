#include <iostream>
#include <vector>
#include <string>
#include "L1.h"
#include "Piece.h"

using namespace std;

L1::L1(int size) : Piece(size)	{
	color="green";
	fillVec();	
}

void L1::fillVec()	{
	shape[0][0]=(Piece::getidNum());
	for (int i=0; i<(Piece::getSize()); i++)	{
		shape[1][i]=(Piece::getidNum());
	}
}
