//Brittany Harrington, Elizabeth Vista, Jessie Frio
//CSE 20212
////Final Project: Tetris
//sPiece .h file

#ifndef SPIECE_H
#define SPIECE_H
#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"

using namespace std;

class sPiece : public Piece	{
	public:
		sPiece(int size=3);
		virtual void rotate();
		virtual void right();
		virtual void left();
		virtual void down();

	private:
		int numR;
};

#endif
