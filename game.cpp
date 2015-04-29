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
  char choice;

  while( ! quit ) {
    while ( ! game.isGameOver() && ! quit )	{
    if ( game.getLevel() > 3 ) 
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
        case SDLK_UP : 
	  //game.ALLdown()
	  while( ! game.pieceFinishedFalling() ) {
		game.down();
	  }
	  break;
        case SDLK_SPACE : 
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
	  break;
        default : 
	  break;
      }
    }	   
    
  }

      }
  game.setBoard();
  }
  //clear the board and display a game over message
    SDL.clearBoard();
    SDL_Delay(5000);
}  
SDL.close();	
}
