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
		vector<vector <int> > shape;
		vector<vector <int> > shapeTemp;
	private:
		int size;
		int idNum;
};
#endif
