//Brittany Harrington, Elizabeth Vista, Jessie Frio
//CSE 20212
////Final Project: Tetris
//tPiece.h file

#ifndef TPIECE_H
#define TPIECE_H

#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"
using namespace std;

class tPiece : public Piece	{
	public:
		tPiece(int size=3);
		virtual void rotate();
		virtual void right();
		virtual void left();
		virtual void down();

	private:
		int numR;

};

#endif
