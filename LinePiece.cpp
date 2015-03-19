#include <iostream>
#include <string>
#include <vector>
#include "LinePiece.h"
#include "Piece.h"

using namespace std;

LinePiece :: LinePiece(int size) : Piece(size) {
	color = "red";
	fillVec();
}

void LinePiece :: fillVec(){
 	for( int i=0; i<(Piece::getSize()); i++){
		shape[0][i] = 1;
	}
}
