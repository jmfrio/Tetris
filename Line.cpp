#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "Line.h"
#include "Piece.h"

Line :: Line(int size) : Piece(size) {
  color = "red";
  fillVec();
}

void Line :: fillVec(){
  for( int i=0; i<(Piece::getSize()); i++){
        shape[0][i] = (Piece::getidNum());
  }
}

