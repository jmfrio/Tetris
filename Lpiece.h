#ifndef L2_H
#define L2_H
#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"
using namespace std;

class L2 : public Piece	{
	public:
		L2(int size=3);
		virtual void fillVec();
	private:
		string color;
};
#endif
