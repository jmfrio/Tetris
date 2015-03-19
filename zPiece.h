#ifndef ZPIECE_H
#define ZPIECE_H

#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"
using namespace std;

class zPiece : public Piece{
 	public:
		zPiece(int size=3);
		virtual void fillVec();
	private:
		string color;

};

#endif
