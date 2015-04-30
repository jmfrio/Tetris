//Brittany Harrington, Elizabeth Vista, Jessie Frio
//CSE 20212
//Final Project: Tetris
//LinePiece .h file

#ifndef LINEPIECE_H
#define LINEPIECE_H

#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"

using namespace std;

class LinePiece : public Piece {
	public:
		LinePiece(int=4);
		virtual void rotate();
		virtual void right();
		virtual void left();
		virtual void down();

	private:
		int numR;
};
#endif
