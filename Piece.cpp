#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"

using namespace std;

Piece::Piece(int Size)	{
	idNum=1;
	size=Size;

	vector<int> tempVec;

	for (int j=0; j<size; j++)	{
		for (int i=0; i<size; i++)	{
			tempVec.push_back(0);
		}
		shape.push_back(tempVec);
		shapeTemp.push_back(tempVec);
		tempVec.clear();
	}
}

void Piece::Display()	{
	for (int i=0; i<size; i++)	{
		for (int j=0; j<size; j++)	{
			cout << shape[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Piece::fillVec()	{
}

void Piece::rotate()	{
	resetTemp();
	Display();
	shapeTemp[0][0]=shape[0][2];	
	shapeTemp[0][1]=shape[1][2];	
}

void Piece::resetTemp()	{
	for (int i=0; i<size; i++)	{
		for (int j=0; j<size; j++)	{
			shapeTemp[i][j]=0;	
		}
	}	
}

void Piece::updateTemp()	{
	for (int i=0; i<size; i++)	{
		for (int j=0; j<size; j++)	{
			shape[i][j]=shapeTemp[i][j];
		}
	}
}

int Piece::getidNum()	{
	return idNum;
}

int Piece::getSize()	{
	return size;
}
