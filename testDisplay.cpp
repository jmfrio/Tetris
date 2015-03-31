#include <iostream>
#include <string>
#include <vector>
#include "BoxPiece.h"
#include "tPiece.h"
#include "sPiece.h"
#include "zPiece.h"
#include "jPiece.h"
#include "LPiece.h"
#include "LinePiece.h"
#include "Piece.h"

using namespace std;

int main()	{

/* Displays the vector containing each piece except for 
the L shaped piece since we are changing elements of the 
piece classes and have already made changes to LPiece
making it incompatible with this program */

//piece constructors
	BoxPiece BoxPiece_1(3);
	LinePiece LinePiece_1(4);
	jPiece jPiece_1(3);
//	LPiece LPiece_1(3);
	tPiece tPiece_1(3);
	sPiece sPiece(3);
	zPiece zPiece(3);


//piece display functions
	BoxPiece_1.Display();
	LinePiece_1.Display();
	jPiece_1.Display();
//	LPiece_1.Display();
	tPiece_1.Display();
	sPiece.Display();
	zPiece.Display();

}
