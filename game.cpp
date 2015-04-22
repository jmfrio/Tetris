// Fundamentals of Computing II
// Final Project -- Tetris
// game.h -- driver program for board class

#include "Piece.h"
#include "BoxPiece.h"
#include "LinePiece.h"
#include "LPiece.h"
#include "jPiece.h"
#include "sPiece.h"
#include "zPiece.h"
#include "tPiece.h"
#include "Board.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

int main() {
	Board game;
	char choice;
	while ( ! game.isGameOver() )	{

	game.display();
	cout << "finished initial display" << endl;
	game.addPiece();
	cout << "finished adding piece" << endl;
	game.display();

	while( ! game.pieceFinishedFalling() ) {
		cout << "Please make choice: \n (1) press 'l' to move piece left \n (2) press 'r' to move piece right \n (3) press 'd' to move down \n (4) press 'f' to flip/rotate piece" << endl;
                cout << "Choice: ";
                cin >> choice;

                        switch (choice) {
                                case 'r':
                                        game.right();
                                        break;
                                case 'l':
                                        game.left();
                                        break;
                                case 'd':
                                        game.down();
                                        break;
                                case 'f':
                                        game.rotate();
                                        break;
                        }

		game.display();
	}
	game.setBoard();
}
/*	game.addPiece();
	while( ! game.pieceFinishedFalling() ) {
                cout << "Please make choice: \n (1) press 'l' to move piece left \n (2) press 'r' to move piece right \n (3) press 'd' to move down \n (4) press 'f' to flip/rotate piece" << endl;
                cout << "Choice: ";
                cin >> choice;

                        switch (choice) {
                                case 'r':
                                        game.right();
                                        break;
                                case 'l':
                                        game.left();
                                        break;
                                case 'd':
                                        game.down();
                                        break;
                                case 'f':
                                        game.rotate();
                                        break;
                        }

		game.display();
	}
*/	game.display();


}


