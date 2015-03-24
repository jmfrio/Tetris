#ifndef LINEPIECE_H
#define LINEPIECE_H

#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"

using namespace std;

class LinePiece : public Piece {
	public:
		LinePiece(int size=4);
		//virtual void fillVec();
		virtual void rotate();
	private:
		string color;
		int numR;
};
#endif
