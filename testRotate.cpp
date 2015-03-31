#include <iostream>
#include <string>
#include <vector>
#include "tPiece.h"
#include "Piece.h"

using namespace std;

int main()	{

//piece constructors

tPiece tPiece_1(3);

tPiece_1.Display();
//displays the t-piece in its initial orientation
tPiece_1.rotate();
tPiece_1.Display();
tPiece_1.rotate();
tPiece_1.Display();
tPiece_1.rotate();
tPiece_1.Display();
tPiece_1.rotate();
tPiece_1.Display();
//t-piece has been returned to its initial orientation

}

