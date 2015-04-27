#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"

using namespace std;

Piece::Piece(int Size)	{
	size=Size;

}

void Piece::Display()	{
cout << "r1: " << r1 << "   c1: " << c1 << endl;
cout << "r2: " << r2 << "   c2: " << c2 << endl;
cout << "r3: " << r3 << "   c3: " << c3 << endl;
cout << "r4: " << r4 << "   c4: " << c4 << endl;
}


void Piece::rotate()	{
	//cout << "entering rotate function" << endl;
        if ( (c1 > 8) || (c2 > 8) || (c3 > 8) || (c4 > 8) ) {
           //     cout << "too far right" << endl;
        }
        else if ( (c1 < 1) || (c2 < 1) || (c3 < 1) || (c4 < 1) ) {
             //   cout << "too far left" << endl;
        }
        else if ( (r1 < 1 ) || (r2 < 1) || (r3 < 1) || (r4 < 1) ) {
               // cout << "top of board" << endl;
       	}
	 else if ( (r1 > 18) || (r2 > 18) || (r3 >18) || (r4 > 18) ) {
                //cout << "bottom of board" << endl;
        } else  {
		Piece::rotate();
	}
}

int Piece::getSize()	{
	return size;
}

void Piece::right()	{
//	cout << "r1 = " << r1 << ", c1 = " << c1 << endl;
//	cout << "r2 = " << r2 << ", c2 = " << c2 << endl;
//	cout << "r3 = " << r3 << ", c3 = " << c3 << endl;
//	cout << "r4 = " << r4 << ", c4 = " << c4 << endl;
	if ( (c1 == 9) || (c2 == 9) || (c3 == 9) || (c4 ==9) ) {
	//	cout << "too far right" << endl;
	} 
	else	{
		c1= c1+1;
		c2= c2+1;
		c3= c3+1;
		c4= c4+1;
	}
}

void Piece::left()	{
	if ( (c1 == 0) || (c2 == 0) || (c3 == 0) || (c4 ==0) ) {
	//	cout << "too far left" << endl;
	} 

	else	{
		c1= c1-1;
		c2= c2-1;
		c3= c3-1;
		c4= c4-1;
	}
}

void Piece::down()	{
	if ( (r1 == 19) || (r2 == 19) || (r3 == 19) || (r4 ==19) ) {
	//	cout << "bottom of board" << endl;
	} else	{
		r1= r1+1;
		r2= r2+1;
		r3= r3+1;
		r4= r4+1;
	}
}
