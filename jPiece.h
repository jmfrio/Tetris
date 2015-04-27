#ifndef JPIECE_H
#define JPIECE_H

#include <iostream>
#include <string>
#include <vector>
#include "Piece.h"

using namespace std;

class jPiece : public Piece	{
	public:
		jPiece(int size=3);
		//virtual void fillVec();
		virtual void rotate();
		virtual void right();
		virtual void left();
		virtual void down();
	private:
		int color;
		int numR;
};
#endif
