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
	bool quit = false;
	SDL_Event e;

	//cout << "BEGINNING GAME..." << endl;
	char choice;
	while ( !quit ) { //while the x has not been pressed
	//game.display();
	  if( e.type == SDL_QUIT ) //if the x button is pressed
	    quit = true; //exits the while loop
	while ( ! game.isGameOver() )	{
		game.addPiece();
		for( int row=0; row<20; row++){
			for( int col=0; col<10; col++){
			   if( game.isSpotFull( row , col) == 1 ){
				int color = game.getSpotNumber( row , col );
				SDL.fillRect(col, row, color);
			   }
			   else
				SDL.clearRect(col,row);
			}
		}
		//cout << endl;
		//game.display();

		while( ! game.pieceFinishedFalling() ) {
		  game.down();
		  SDL_Delay( (10-game.getLevel()) * 50 );
			for( int row=0; row<20; row++){
			for( int col=0; col<10; col++){
			   if( game.isSpotFull( row , col) == 1 ){
				int color = game.getSpotNumber( row , col );
				SDL.fillRect(col, row, color);
			   }
			   else
				SDL.clearRect(col,row);
			}
			}
		/*	cout << endl << "Please make choice: \n (1) press 'l' to move piece left \n (2) press 'r' to move piece right \n (3) press 'd' to move down \n (4) press 'f' to flip/rotate piece" << endl;
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
*/			



	  while ( SDL_PollEvent( &e ) != 0 ) { //while there are events to be processed
		if( e.type == SDL_KEYDOWN ) {
		   switch( e.key.keysym.sym ) {
			case SDLK_UP :
			   game.rotate();
			   break;
			case SDLK_DOWN :
			   if( game.pieceFinishedFalling() != 1)
			   game.down();
			   break;
			case SDLK_LEFT :
			   if( game.pieceFinishedFalling() != 1)
			   game.left();
			   break;
			case SDLK_RIGHT :
			   if( game.pieceFinishedFalling() != 1)
			   game.right();
			   break;
			default :
			   
			   break;
		   }
		}	
			   


			//game.display();
			//cout << endl;
	 }
}
		game.setBoard();

	}

//cout << endl << endl;
//cout << "GAME OVER" << endl;



//clear the board and display a game over message
SDL.clearBoard();
SDL_Delay(5000);
SDL.close();

}
}
