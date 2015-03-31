#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"

using namespace std;

Piece::Piece(int Size)	{
//	idNum=1;
	size=Size;

	/*vector<int> tempVec;

	for (int j=0; j<size; j++)	{
		for (int i=0; i<size; i++)	{
			tempVec.push_back(0);
		}
		shape.push_back(tempVec);
		shapeTemp.push_back(tempVec);
		tempVec.clear();
	}*/
}

void Piece::Display()	{
	/*for (int i=0; i<size; i++)	{
		for (int j=0; j<size; j++)	{
			cout << shape[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
cout << "r1: " << r1 << "   c1: " << c1 << endl;
cout << "r2: " << r2 << "   c2: " << c2 << endl;
cout << "r3: " << r3 << "   c3: " << c3 << endl;
cout << "r4: " << r4 << "   c4: " << c4 << endl;
}

//void Piece::fillVec()	{
//}

void Piece::rotate()	{
//	resetTemp();
//	int s=Piece::getSize();
//	for (int i=0; i<s; i++)	{
//		shapeTemp[i][s-1]=shape[0][i];	
//		shapeTemp[i][s-2]=shape[1][i];
//		shapeTemp[i][s-3]=shape[2][i];
//		if (s==4)	{
//			shapeTemp[i][s-4]=shape[3][i];
//		}
//	}
//	updateTemp();
//	Display();
}

/*void Piece::resetTemp()	{
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
}*/

int Piece::getSize()	{
	return size;
}

void Piece::right()	{
	c1= c1+1;
	c2= c2+1;
	c3= c3+1;
	c4= c4+1;
}

void Piece::left()	{
	c1= c1-1;
	c2= c2-1;
	c3= c3-1;
	c4= c4-1;
}

void Piece::down()	{
	r1= r1+1;
	r2= r2+1;
	r3= r3+1;
	r4= r4+1;
}
