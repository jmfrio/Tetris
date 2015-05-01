//Brittany Harrington, Jessie Frio, Elizabeth Frio
//CSE 20212
//Final Project: Tetris-- graphics.h class that contains SDL function definitions and implementations. Functions include drawing the board and grid lines, filling it rectangles and clearing respective objects.

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
#include <SDL2/SDL_ttf.h>
#include <string>

class graphics {

	public:
		graphics();
		bool init( void ); //initializes SDL and creates window
		void close( void ); //clears window and quits SDL

		void drawBoard( void );	
		void drawGrid( void );
		void clearGrid( void );
		void clearBoard( void );
		void fillRect( int, int, int);
		void clearRect( int, int );
//		void drawText( void );

	private:
		int window_width;
		int window_height;

		int screen_left;
		int screen_right;

		int screen_width;
		int screen_height;

		SDL_Window* Window; 
		SDL_Renderer* Renderer;
		SDL_Texture* Texture;
		SDL_Surface* Surface;
//		TTF_Font* TitleFont;
//		TTF_Font* OtherFont;
//		TTF_Font* AnotherFont;
//		SDL_Surface* sText;

};

graphics :: graphics(){

	//set window width and height to 500x800
	window_width=500;
	window_height=800;

	//leave indentation on screen
	screen_left=50;
	screen_right=450;

	screen_width=400;
	screen_height=800;

	SDL_Window* Window = NULL; 
	SDL_Renderer* Renderer = NULL;
	SDL_Texture* Texture = NULL;
	SDL_Surface* Surface = NULL;
//	TTF_Font* TitleFont = NULL;
//	TTF_Font* OtherFont = NULL;
//	TTF_Font* AnotherFont = NULL;
//	SDL_Surface* sText = NULL;

	drawBoard();
	drawGrid();
	//	drawText();
}

bool graphics :: init ( void ) {
	//cout << "init" << endl;
	bool success = true;

	//initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) <0 ) {
		cout << "SDL_Init Error: " << SDL_GetError() << endl;
		success = false;
	}
	else { 
		//Create window
		Window = SDL_CreateWindow( "TETRIS" , SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN );
		if( Window == NULL ) {
			cout << "SDLCreateWindow Error: " << SDL_GetError() << endl;
			success = false;
		}
		else {
			Renderer = SDL_CreateRenderer( Window, 1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if ( Renderer == NULL ) {
				cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
				close();
			}
			else {
				Surface = SDL_GetWindowSurface( Window );
				SDL_FillRect ( Surface, NULL, SDL_MapRGB (Surface -> format, 0, 0, 0 ) );
			}
		}
	}

	//initialize TTF
//	TTF_Init();

	return success;
}

//function to close Window and quit SDL
void graphics :: close ( void ) {

	SDL_DestroyTexture( Texture );
	SDL_DestroyRenderer( Renderer );
	SDL_DestroyWindow ( Window );
	Window = NULL;

	SDL_Quit();

}

void graphics :: drawBoard(){
	//cout << "drawboard" << endl;

	if ( !init() ) //if init returns false
		printf( "Failed to initialzie!\n" );
	else { //if init returns true
		//Colors: RGBA - A is for opaqueness
		SDL_SetRenderDrawColor( Renderer, 0, 0, 0, 255 );
		SDL_RenderClear ( Renderer );	

		//DRAW HORIZONTAL GRID LINES
		SDL_SetRenderDrawColor( Renderer, 255, 255, 255, 255 );

		SDL_RenderDrawLine( Renderer, screen_left, 0*(screen_height/20)-1, screen_right, 0*(screen_height/20)-1 );
		SDL_RenderDrawLine( Renderer, screen_left, 20*(screen_height/20)-1, screen_right, 20*(screen_height/20)-1 );

		//DRAW VERTICAL GRID LINES
		SDL_RenderDrawLine( Renderer, screen_left+0*(screen_width/10)-1, 0, screen_left+0*(screen_width/10)-1, screen_height );
		SDL_RenderDrawLine( Renderer, screen_left+10*(screen_width/10)-1, 0, screen_left+10*(screen_width/10)-1, screen_height );

		SDL_RenderPresent( Renderer );

	}
}


void graphics :: fillRect( int col, int row, int pieceColor ){

	SDL_Rect fillRect = { screen_left+col*(screen_width/10), row*(screen_height/20), (screen_width/10)-2, (screen_height/20)-2 };

	switch ( pieceColor ) {


		//red
		case 1: SDL_SetRenderDrawColor( Renderer, 255, 78, 90, 255 );
			break;
			//green
		case 2: SDL_SetRenderDrawColor( Renderer, 0, 255, 137, 255 );
			break;
			//blue
		case 3: SDL_SetRenderDrawColor( Renderer, 0, 0, 255, 255 );
			break;
			//yellow
		case 4: SDL_SetRenderDrawColor( Renderer, 255, 255, 58, 255 );
			break;
			//purple
		case 5: SDL_SetRenderDrawColor( Renderer, 122, 40, 255, 255 );
			break;
			//pink
		case 6: SDL_SetRenderDrawColor( Renderer, 253, 76, 194, 255 );
			break;
			//light blue
		case 7: SDL_SetRenderDrawColor( Renderer, 0, 191, 255, 255 );
			break;
	}


	SDL_RenderFillRect( Renderer, &fillRect );

	SDL_RenderPresent( Renderer );

}
//function to clear a certain rectangle on the grid
void graphics :: clearRect( int col, int row){

	SDL_Rect fillRect = { screen_left+col*(screen_width/10), row*(screen_height/20), (screen_width/10)-2, (screen_height/20)-2 };
	SDL_SetRenderDrawColor( Renderer, 0, 0, 0, 255 );
	SDL_RenderFillRect( Renderer, &fillRect );

	SDL_RenderPresent( Renderer );

}

//function to clear board and redraw grid lines
void graphics :: clearBoard( void ) {

	SDL_SetRenderDrawColor( Renderer, 0, 0, 0, 255 );
	SDL_RenderClear ( Renderer );

	//DRAW HORIZONTAL GRID LINES
	SDL_SetRenderDrawColor( Renderer, 255, 255, 255, 255 );
	SDL_RenderDrawLine( Renderer, screen_left, 0*(screen_height/20)-1, screen_right, 0*(screen_height/20)-1 );
	SDL_RenderDrawLine( Renderer, screen_left, 20*(screen_height/20)-1, screen_right, 20*(screen_height/20)-1 );

	//DRAW VERTICAL GRID LINES
	SDL_RenderDrawLine( Renderer, screen_left+0*(screen_width/10)-1, 0, screen_left+0*(screen_width/10)-1, screen_height );
	SDL_RenderDrawLine( Renderer, screen_left+10*(screen_width/10)-1, 0, screen_left+10*(screen_width/10)-1, screen_height );

	SDL_RenderPresent( Renderer );

}

void graphics :: drawGrid( void ){
	//DRAW HORIZONTAL GRID LINES
	SDL_SetRenderDrawColor( Renderer, 255, 255, 255, 255 );
	for ( int i=1; i<20; i++){
		SDL_RenderDrawLine( Renderer, screen_left, i*(screen_height/20)-1, screen_right, i*(screen_height/20)-1 );
	}
	//DRAW VERTICAL GRID LINES
	SDL_SetRenderDrawColor( Renderer, 255, 255, 255, 255 );
	for( int i=1; i<10; i++){
		SDL_RenderDrawLine( Renderer, screen_left+i*(screen_width/10)-1, 0, screen_left+i*(screen_width/10)-1, screen_height );
	}
	SDL_RenderPresent( Renderer );
}

void graphics :: clearGrid( void ){
	//DRAW HORIZONTAL GRID LINES
	SDL_SetRenderDrawColor( Renderer, 0, 0, 0, 255 );
	for ( int i=1; i<=20; i++){
		SDL_RenderDrawLine( Renderer, screen_left, i*(screen_height/20)-1, screen_right, i*(screen_height/20)-1 );
	}
	//DRAW VERTICAL GRID LINES
	SDL_SetRenderDrawColor( Renderer, 0, 0, 0, 255 );
	for( int i=1; i<10; i++){
		SDL_RenderDrawLine( Renderer, screen_left+i*(screen_width/10)-1, 0, screen_left+i*(screen_width/10)-1, screen_height );
	}
	SDL_RenderPresent( Renderer );
}
/*
void graphics :: drawText( void ){

	TitleFont = TTF_OpenFont( "CHICORY_.TTF", 30);
	OtherFont = TTF_OpenFont( "04B_19__.TTF", 20);
	AnotherFont = TTF_OpenFont( "04B_30__.TTF", 20);

	SDL_Color clrFg = { 255, 255, 255, 255 };
	SDL_Rect Destination = {0, 0, 50, 50};

	cout << "drawfont" << endl;
	sText = TTF_RenderText_Solid( TitleFont, "TETRIS", clrFg );
	cout << "tears" << endl;
	SDL_BlitSurface( sText, NULL, Surface, &Destination );

	cout << "happy" << endl;
}*/
