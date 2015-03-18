#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Piece	{
	public:
		Piece(int size=3);
		void rotate();
		void Display();
		virtual void fillVec()=0;
		void resetTemp();
		void updateTemp();
		int getidNum();
		int getSize();
		//vector<vector <int> > shape;
		//vector<vector <int> > shapeTemp;
	private:
		//variables for the different coordinates
		int x1, y1, x2, y2, x3, y3, x4, y4;
		int size;
		int idNum;
};
#endif
