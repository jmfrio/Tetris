#include <iostream>
#include <vector>
#include <string>
#include "sPiece.h"
#include "Piece.h"

using namespace std;

sPiece :: sPiece(int size) : Piece(size)	{
  color = "green";
  fillVec();
}

void sPiece :: fillVec()	{
	for( int i=1; i<(Piece::getSize()); i++){
		shape[0][i] = 1;
	}
	for( int j=0; j<(Piece::getSize() - 1); j++){
    		shape[1][j] = 1;
  	}
}
