#include <iostream>
#include <string>
#include <vector>
#include "LPiece.h"
#include "BoxPiece.h"
#include "jPiece.h"
#include "Piece.h"

using namespace std;

int main()	{

//piece constructors
cout << "LPiece" << endl;
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


cout << "jPiece" << endl;
//piece constructors
jPiece jPiece_1(4);

jPiece_1.Display();
//displays the Line-piece in its initial orientation
jPiece_1.rotate();
jPiece_1.Display();
jPiece_1.rotate();
jPiece_1.Display();
jPiece_1.rotate();
jPiece_1.Display();
jPiece_1.rotate();
jPiece_1.Display();
//Line-piece has been returned to its initial orientation
jPiece_1.right();
cout << "Right: " << endl;
jPiece_1.Display();
jPiece_1.right();
cout << "Right: " << endl;
jPiece_1.Display();
jPiece_1.right();
cout << "Right: " << endl;
jPiece_1.Display();
jPiece_1.down();
cout << "Down: " << endl;
jPiece_1.Display();
jPiece_1.down();
cout << "Down: " << endl;
jPiece_1.Display();
jPiece_1.down();
cout << "Down: " << endl;
jPiece_1.Display();
jPiece_1.left();
cout << "Left: " << endl;
jPiece_1.Display();
jPiece_1.left();
cout << "Left: " << endl;
jPiece_1.Display();
jPiece_1.left();
cout << "Left: " << endl;
jPiece_1.Display();


cout << "BoxPiece" << endl << endl;
BoxPiece BoxPiece_1(4);

BoxPiece_1.Display();
BoxPiece_1.right();
cout << "Right: " << endl;
BoxPiece_1.Display();
BoxPiece_1.right();
cout << "Right: " << endl;
BoxPiece_1.Display();
BoxPiece_1.right();
cout << "Right: " << endl;
BoxPiece_1.Display();
BoxPiece_1.down();
cout << "Down: " << endl;
BoxPiece_1.Display();
BoxPiece_1.down();
cout << "Down: " << endl;
BoxPiece_1.Display();
BoxPiece_1.down();
cout << "Down: " << endl;
BoxPiece_1.Display();
BoxPiece_1.left();
cout << "Left: " << endl;
BoxPiece_1.Display();
BoxPiece_1.left();
cout << "Left: " << endl;
BoxPiece_1.Display();
BoxPiece_1.left();
cout << "Left: " << endl;
BoxPiece_1.Display();
}
