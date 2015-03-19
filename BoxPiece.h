#ifndef BOXPIECE_H
#define BOXPIECE_H

#include <iostream>
#include <string>
#include <vector>
#include "Piece.h"

using namespace std;

class BoxPiece : public Piece	{
	public:
		BoxPiece(int size=3);
		virtual void fillVec();
	private:
		string color;
