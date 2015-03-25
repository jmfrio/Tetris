#include <iostream>
#include <string>
#include <vector>
#include "LPiece.h"
#include "Piece.h"

using namespace std;

int main()	{

//piece constructors
LPiece LPiece_1(4);

LPiece_1.Display();
//displays the Line-piece in its initial orientation
LPiece_1.rotate();
LPiece_1.Display();
LPiece_1.rotate();
LPiece_1.Display();
LPiece_1.rotate();
LPiece_1.Display();
LPiece_1.rotate();
LPiece_1.Display();
//Line-piece has been returned to its initial orientation
LPiece_1.right();
cout << "Right: " << endl;
LPiece_1.Display();
LPiece_1.right();
cout << "Right: " << endl;
LPiece_1.Display();
LPiece_1.right();
cout << "Right: " << endl;
LPiece_1.Display();
LPiece_1.down();
cout << "Down: " << endl;
LPiece_1.Display();
LPiece_1.down();
cout << "Down: " << endl;
LPiece_1.Display();
LPiece_1.down();
cout << "Down: " << endl;
LPiece_1.Display();
LPiece_1.left();
cout << "Left: " << endl;
LPiece_1.Display();
LPiece_1.left();
cout << "Left: " << endl;
LPiece_1.Display();
LPiece_1.left();
cout << "Left: " << endl;
LPiece_1.Display();

}

