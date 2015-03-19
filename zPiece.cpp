#include <iostream>
#include <vector>
#include <string>
#include "zPiece.h"
#include "Piece.h"

using namespace std;

zPiece :: zPiece(int size) : Piece(size)	{
	color = "red";
	fillVec();
}

void zPiece :: fillVec(){
	for( int i=0; i<(Piece::getSize() - 1); i++){
		shape[0][i] = 1;
	}
	for( int j=1; j<(Piece::getSize()); j++ ){
		shape[1][j] = 1;
	}
}

