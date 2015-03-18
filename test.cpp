#include <iostream>
#include <string>
#include <vector>
#include "L1.h"
#include "L2.h"
#include "Line.h"
#include "Piece.h"

using namespace std;

int main()	{
	L1 L1_1(3);
	Line Line1(4);
	L2 L2_1(3);

	L1 * derived_ptr=&L1_1;
	derived_ptr->Display();
	derived_ptr->rotate();
	derived_ptr->rotate();

	Line * derived_ptr1=&Line1;
	derived_ptr1->Display();
	derived_ptr1->rotate();
	derived_ptr1->rotate();

	L2 * derived_ptr2=&L2_1;
	derived_ptr2->Display();
	derived_ptr2->rotate();
	derived_ptr2->rotate();
}
