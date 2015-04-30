//Brittany Harrington, Elizabeth Vista, Jessie Frio
//CSE 20212
////Final Project: Tetris
////Piece.h file (base class piece)

#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Piece	{
	public:
		Piece(int size=3);
		virtual void rotate();
		int getSize();
		int color;
		int r1, c1, r2, c2, r3, c3, r4, c4;
		virtual void right();
		virtual void left();
		virtual void down();
	private:
		int size;
};
#endif
