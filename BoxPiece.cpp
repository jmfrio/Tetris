#include <iostream>
#include <string>
#include <vector>
#include "BoxPiece.h"
#include "Piece.h"

using namespace std;

BoxPiece :: BoxPiece(int size) : Piece(size)	{
	color = "yellow";
	fillVec();
}

void BoxPiece :: fillVec(){
  for( int i=0; i<2; i++){
    for( int j=0; j<2; j++){
        shape[i][j] = 1;
    }
  }
}

