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
		virtual void fillVec();
	private:
		string color;

};

#endif
