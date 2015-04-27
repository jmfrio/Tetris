#ifndef BOXPIECE_H
#define BOXPIECE_H

#include <iostream>
#include <string>
#include <vector>
#include "Piece.h"

using namespace std;

class BoxPiece : public Piece	{
	public:
		BoxPiece(int=3);
//		virtual void fillVec();
		virtual void rotate();
		virtual void right();
		virtual void left();
		virtual void down();

	private:
		//int color;
		int numR;
};
#endif
