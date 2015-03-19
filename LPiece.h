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
		virtual void fillVec();
	private:
		string color;
};
#endif
