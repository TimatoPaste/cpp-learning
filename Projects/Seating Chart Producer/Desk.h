#include <SDL2/SDL.h>
#include <string>
#include "Student.h"
#include <array>

struct Desk{
	
	SDL_Renderer* renderer;
	
	TTF_Font* font;
	
	const char* text;
	
	bool drawn;
	std::array<int,3> drawColor;
	
	bool filled;
	std::array<int,3> fillColor;
	
	bool textDisplay;
	std::array<int,3> textColor;
	
	Student student;
	
	SDL_Rect desk;
	
	//constructor for default values
	Desk(){
		font = TTF_OpenFont("OpenSans-Regular.ttf",25);
		drawn = false;
		filled = false;
		text = "";
		textDisplay = false;
		
		drawColor = {0,0,0};
		fillColor = {0,0,0};
		textColor = {0,0,0};
		
		desk.x = 0;
		desk.y = 0;
		desk.w = 100;
		desk.h = 50;
	}
	
	//renders current instant without clearing window
	void stamp(){
		//checks each attribute and performs tasks accordingly
		if(filled){
			SDL_SetRenderDrawColor(renderer,fillColor[0],fillColor[1],fillColor[2],255);
			SDL_RenderFillRect(renderer,&desk);
		}
		if(drawn){
			SDL_SetRenderDrawColor(renderer,drawColor[0],drawColor[1],drawColor[2],255);
			SDL_RenderDrawRect(renderer,&desk);
		}
		if(textDisplay){
			SDL_Color color = {textColor[0],textColor[1],textColor[2]};
			SDL_Surface* words = TTF_RenderText_Solid(font,text,color);
			SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,words);
			SDL_RenderCopy(renderer,texture,NULL,&desk);
		}
	}
	
	bool containsCoord(int x, int y){
		if(desk.x<x&&desk.x+desk.w>x&&desk.y<y&&desk.y+desk.h>y){
			return true;
		}
		return false;
	}
	
	bool containsDesk(Desk a){
		//checks four corners
		if(containsCoord(a.desk.x,a.desk.y)||containsCoord(a.desk.x+a.desk.w,a.desk.y+a.desk.h)||containsCoord(a.desk.x+a.desk.w,a.desk.y)||containsCoord(a.desk.x,a.desk.y+a.desk.h)){
			return true;
		}
		//checks four midpoints b/w corners on edges
		else if(containsCoord(a.desk.x+a.desk.w/2,a.desk.y)||containsCoord(a.desk.x+a.desk.w/2,a.desk.y+a.desk.h)||containsCoord(a.desk.x,a.desk.y+a.desk.h/2)||containsCoord(a.desk.x+a.desk.w,a.desk.y+a.desk.h/2)){
			return true;
		}
		
		//checks for middle of desk
		else if(containsCoord(a.desk.x+a.desk.w/2,a.desk.y+a.desk.h/2)){
			return true;
		}
		
		return false;
	}
};