//Brittany Harrington, Elizabeth Vista, Jessie Frio
//CSE 20212
////Final Project: Tetris
//LPiece .h file

#ifndef LPIECE_H
#define LPIECE_H
#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"
using namespace std;

class LPiece : public Piece	{
	public:
		LPiece(int size=3);
		virtual void rotate();
		virtual void right();
		virtual void left();
		virtual void down();

	private:
		int numR;
};
#endif
