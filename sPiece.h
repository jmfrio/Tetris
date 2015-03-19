#ifndef SPIECE_H
#define SPIECE_H
#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"

using namespace std;

class sPiece : public Piece	{
 	public:
		sPiece(int size=3);
    		virtual void fillVec();
	private:
	    	string color;
};

#endif
