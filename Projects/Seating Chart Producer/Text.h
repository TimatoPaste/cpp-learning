#include <SDL2/SDL.h>
#include <string>
#include <array>

struct Text{
	
	SDL_Renderer* renderer;
	
	TTF_Font* font;
	
	const char* text;
	
	std::array<int,3> textColor;
	
	SDL_Rect box;
	
	//constructor for default values
	Text(){
		font = TTF_OpenFont("OpenSans-Regular.ttf",25);
		text = "";
		
		textColor = {0,0,0};
		
		box.x = 0;
		box.y = 0;
		box.w = 100;
		box.h = 50;
	}
	
	//renders current instant without clearing window
	void stamp(){
		SDL_Color color = {textColor[0],textColor[1],textColor[2]};
		SDL_Surface* words = TTF_RenderText_Solid(font,text,color);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,words);
		SDL_RenderCopy(renderer,texture,NULL,&box);
	}
};