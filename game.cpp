// Fundamentals of Computing II
// Final Project -- Tetris
// game.h -- driver program for Tetris game

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

#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "graphics.h"

int main ( int argc, char* args[] ) {

  Board game;	//instantiate board
  graphics SDL;	//instantiate SDL graphics
  bool quit = false;
  SDL_Event e;
  char choice;

	//display opening text: Game title, instructions on key commands, Level and score
  system("clear");
  cout << " Tetris " << endl <<  endl;
  cout << "Key Controls:" << endl << "Right - move piece right" <<endl << "Left  - move piece left" << endl << "Up    - rotate piece" << endl << "Down  - move to bottom" << endl << "Space - pause for 5 seconds " << endl<< "Esc   - quit window" << endl << endl;
  cout << "Level:" << endl;
  cout << endl << "Score:" << endl;


  //while the window is open
  while( ! quit ) {
	  //while the game is still being played and the window is open
	  while ( ! game.isGameOver() && ! quit )	{
		  //if the level is higher than two, remove grid lines-- makes game more difficult 
		  if ( game.getLevel() > 2 ) 
			  SDL.clearGrid();
		  //regardless of level, add new piece to board
		  game.addPiece();

		  //If a spot is marked as filled, use fillRect to fill it with corresponding color
		  for( int row=0; row<20; row++){
			  for( int col=0; col<10; col++){
				  if( game.isSpotFull( row , col) == 1 ){
					  int color = game.getSpotNumber( row , col );
					  SDL.fillRect(col, row, color);
				  }
				  else
				  //otherwise clear the rectangle
					  SDL.clearRect(col,row);
			  }
		  }			    
		  while( ! game.pieceFinishedFalling() && ! quit ) {
			  //while the piece is falling...
			  //move piece down automatically
			  game.down();
			  //delay * level speeds up the automatic drop line for each level
			  SDL_Delay( (10-game.getLevel()) * 50 );

			  //continue updating board as piece drops, filling corresponding boxes and clearing others
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

			  //SDL commands...
			  while ( SDL_PollEvent( &e ) != 0 ) { //while there are events to be processed
				  if( e.type == SDL_QUIT ) { //if the x button is pressed
					  quit = true; //exits the while loop
					  break;
				  }	
				  else if( e.type == SDL_KEYDOWN ) {	//if the window is still open...
					  switch( e.key.keysym.sym ) {
						  case SDLK_DOWN : 	//if user presses down arrow: piece falls all the way
							  while( ! game.pieceFinishedFalling() ) {
								  game.down();
							  }		
							  break;
						  case SDLK_SPACE :	//space bar pauses game
							  system("clear");
							  cout << "PAUSED GAME" << endl;
							  SDL_Delay(5000);
							  system("clear");
							  cout << " Tetris " << endl <<  endl;
							  cout << "Key Controls:" << endl << "Right - move piece right" <<endl << "Left  - move piece left" << endl << "Up    - rotate piece" << endl << "Down  - move to bottom" << endl << "Space - pause for 5 seconds " << endl<< "Esc   - quit window" << endl << endl;

							  cout << "Level: " << game.getLevel() << endl;
							  cout << endl << "Score: " << game.getScore() << endl;
							  break;
						  case SDLK_UP : //up arrow rotates piece clockwise 90 degrees
							  game.rotate();
							  break;
						  case SDLK_LEFT : 	//left arrow moves piece left
							  game.left();
							  break;
						  case SDLK_RIGHT : 	//right arrow moves piece left
							  game.right();
							  break;
						  case SDLK_ESCAPE :	//escape quits the game
							  SDL.close();
							  quit = true;
							  break;
						  default : 
							  break;
					  }
				  }	   

			  }

		  }
		  game.setBoard();	//set new board at the end of each loop cycle
		  system("clear");	//clear terminal window
	 	  //re-display opening text: title, instructions, level and score
		  cout << " Tetris " << endl <<  endl;
		  cout << "Key Controls:" << endl << "Right - move piece right" <<endl << "Left  - move piece left" << endl << "Up    - rotate piece" << endl << "Down  - move to bottom" << endl << "Space - pause for 5 seconds " << endl<< "Esc   - quit window" << endl << endl;

		  cout << "Level: " << game.getLevel() << endl;
		  cout << endl << "Score: " << game.getScore() << endl;

	  }
  quit = true;
  }  

  SDL.close();		//once game is over, close window and clear screen
  system("clear");

  //display game over message
  cout << " Tetris " << endl <<  endl;
  cout << "GAME OVER" << endl << endl;

  //display final level and score
  cout << "Final Level: " << game.getLevel() << endl;
  cout << endl << "Final Score: " << game.getScore() << endl;
}
