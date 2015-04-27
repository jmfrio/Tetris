// Elizabeth Vista
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

#include <SDL2/SDL.h>
#include <string>
#include "graphics.h"

int main ( int argc, char* args[] ) {

	Board game;
	graphics SDL;

	cout << "BEGINNING GAME..." << endl;
	char choice;
	//game.display();
	while ( ! game.isGameOver() )	{
		game.addPiece();
		for( int i=0; i<20; i++){
			for( int j=0; j<10; j++){
			   if( game.isSpotFull(i,j) == 1 )
				SDL.fillRect(j, i);
			   else
				SDL.clearRect(j,i);
			}
		}
		cout << endl;
		game.display();

		while( ! game.pieceFinishedFalling() ) {
			cout << endl << "Please make choice: \n (1) press 'l' to move piece left \n (2) press 'r' to move piece right \n (3) press 'd' to move down \n (4) press 'f' to flip/rotate piece" << endl;
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

			cout << endl;
			game.display();
			cout << endl;
		}
		game.setBoard();
	}
cout << endl << endl;
cout << "GAME OVER" << endl;

}

