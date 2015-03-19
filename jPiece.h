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
		virtual void fillVec();
	private:
		string color;
};
#endif
