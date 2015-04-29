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

#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "graphics.h"

int main ( int argc, char* args[] ) {

  Board game;
  graphics SDL;
  bool quit = false;
  SDL_Event e;
  char choice;

  system("clear");
           cout << " Tetris " << endl <<  endl;
           cout << "Key Controls:" << endl << "Right - move piece right" <<endl << "Left  - move piece left" << endl << "Up    - rotate piece" << endl << "Down  - move to bottom" << endl << "Space - pause for 5 seconds " << endl<< "Esc   - quit window" << endl << endl;
  cout << "Level:" << endl;
  cout << endl << "Score:" << endl;

 
  while( ! quit ) {
    while ( ! game.isGameOver() && ! quit )	{
    if ( game.getLevel() > 2 ) 
      SDL.clearGrid();
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
      while( ! game.pieceFinishedFalling() && ! quit ) {
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

	//

  while ( SDL_PollEvent( &e ) != 0 ) { //while there are events to be processed
    if( e.type == SDL_QUIT ) { //if the x button is pressed
      quit = true; //exits the while loop
      break;
    }
    else if( e.type == SDL_KEYDOWN ) {
      switch( e.key.keysym.sym ) {
        case SDLK_DOWN : 
	  //game.ALLdown()
	  while( ! game.pieceFinishedFalling() ) {
		game.down();
	  }
	  break;
	case SDLK_SPACE :
	   system("clear");
	   cout << "PAUSED GAME" << endl;
	   SDL_Delay(5000);
   	   system("clear");
           cout << " Tetris " << endl <<  endl;
           cout << "Key Controls:" << endl << "Right - move piece right" <<endl << "Left  - move piece left" << endl << "Up    - rotate piece" << endl << "Down  - move to bottom" << endl << "Space - pause for 5 seconds " << endl<< "Esc   - quit window" << endl << endl;

	   cout << "Level: " << game.getLevel() << endl;
	   cout << endl << "Score: " << game.getScore() << endl;
	  break;
        case SDLK_UP : 
	  game.rotate();
	  break;
        case SDLK_LEFT : 
	  game.left();
	  break;
        case SDLK_RIGHT : 
	  game.right();
	  break;
	case SDLK_ESCAPE :
	  SDL.close();
	  quit = true;
	  break;
        default : 
	  break;
      }
    }	   
    
  }

      }
  game.setBoard();
  system("clear");
          cout << " Tetris " << endl <<  endl;
          cout << "Key Controls:" << endl << "Right - move piece right" <<endl << "Left  - move piece left" << endl << "Up    - rotate piece" << endl << "Down  - move to bottom" << endl << "Space - pause for 5 seconds " << endl<< "Esc   - quit window" << endl << endl;

  cout << "Level: " << game.getLevel() << endl;
  cout << endl << "Score: " << game.getScore() << endl;

  }
}  

SDL.close();	
    system("clear");

          cout << " Tetris " << endl <<  endl;
    cout << "GAME OVER" << endl << endl;


  cout << "Final Level: " << game.getLevel() << endl;
  cout << endl << "Final Score: " << game.getScore() << endl;
}
