#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Piece	{
	public:
		Piece(int size=3);
		virtual void rotate()=0;
		void Display();
		//virtual void fillVec()=0;
		//void resetTemp();
		//void updateTemp();
		//int getidNum();
		int getSize();
		//vector<vector <int> > shape;
		//vector<vector <int> > shapeTemp;
		//variables for the different coordinates
		int r1, c1, r2, c2, r3, c3, r4, c4;
	private:
		int size;
		//int idNum;
};
#endif
