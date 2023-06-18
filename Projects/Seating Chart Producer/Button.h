#include <SDL2/SDL.h>
#include <string>
#include <array>

struct Button{
	
	SDL_Renderer* renderer;
	
	TTF_Font* font;
	
	const char* text;
	
	bool drawn;
	std::array<int,3> drawColor;
	
	bool filled;
	std::array<int,3> fillColor;
	
	bool textDisplay;
	std::array<int,3> textColor;
	
	SDL_Rect button;
	
	//constructor for default values
	Button(){
		font = TTF_OpenFont("OpenSans-Regular.ttf",25);
		drawn = false;
		filled = false;
		textDisplay = false;
		
		drawColor = {0,0,0};
		fillColor = {0,0,0};
		textColor = {0,0,0};
		
		button.x = 0;
		button.y = 0;
		button.w = 100;
		button.h = 50;
	}
	
	//renders current instant without clearing window
	void stamp(){
		//checks each attribute and performs tasks accordingly
		if(filled){
			SDL_SetRenderDrawColor(renderer,fillColor[0],fillColor[1],fillColor[2],255);
			SDL_RenderFillRect(renderer,&button);
		}
		if(drawn){
			SDL_SetRenderDrawColor(renderer,drawColor[0],drawColor[1],drawColor[2],255);
			SDL_RenderDrawRect(renderer,&button);
		}
		if(textDisplay){
			SDL_Color color = {textColor[0],textColor[1],textColor[2]};
			SDL_Surface* words = TTF_RenderText_Solid(font,text,color);
			SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,words);
			SDL_RenderCopy(renderer,texture,NULL,&button);
		}
	}
	
	bool containsCoord(int x, int y){
		if(button.x<x&&button.x+button.w>x&&button.y<y&&button.y+button.h>y){
			return true;
		}
		return false;
	}
};