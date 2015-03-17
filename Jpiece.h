#ifndef JPIECE_H
#define JPIECE_H
#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"
using namespace std;

class L1 : public Piece	{
	public:
		L1(int size=3);
		virtual void fillVec();
	private:
		string color;
};
#endif
