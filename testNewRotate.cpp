#include <iostream>
#include <string>
#include <vector>
#include "LinePiece.h"
#include "Piece.h"

using namespace std;

int main()	{

//piece constructors
LinePiece LinePiece_1(4);

LinePiece_1.Display();
//displays the Line-piece in its initial orientation
LinePiece_1.rotate();
LinePiece_1.Display();
LinePiece_1.rotate();
LinePiece_1.Display();
//Line-piece has been returned to its initial orientation

}

