#include <iostream>
#include <string>
#include "SDL2/include/SDL2/SDL.h"
#include "SDL2/include/SDL2/SDL_ttf.h"

//new import needed for this

int main(int argc,char* argv[]){
	SDL_Init(SDL_INIT_EVERYTHING);
	//start text "engine"
	//I combined the ttf package and the sdl package in the files
	TTF_Init();
	SDL_Window* window = SDL_CreateWindow("011 Text",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800,SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,0);
	
	//TTF_OpenFont("directory to .ttf font file",int fontSize); Make font object
	TTF_Font* OpenSans = TTF_OpenFont("OpenSans-Regular.ttf",25);
	//brackets because it is a c structure
	SDL_Color black = {0,0,0};
	
	//character variable for the text
	//Only need to dereference a pointer if it's pointing to an address. If it points to a value, 
	//you can just print that value or change it with the pointer name.
	//in this case, only the char* pointer is constant, so the value of the variable text is able to be changed
	//if it was const char* const text = ... value that it pointed to would not be able to be changed also
	
	
	//how to convert int to char
	int clicks = 0;
	
	//c_str() returns a const char*
	//to_string() returns a string
	SDL_Surface* message = TTF_RenderText_Solid(OpenSans,std::to_string(clicks).c_str(),black);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,message);
	
	SDL_Rect TextBox;
		TextBox.x = 0;
		TextBox.y = 0;
		TextBox.w = 200;
		TextBox.h = 100;
	
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	//this is the drawing statement. SDL_RenderCopy(SDL_Renderer*,SDL_Texture*,SDL_Rect* for source,SDL_Rect*)
	SDL_RenderCopy(renderer,texture,NULL,&TextBox);
	SDL_RenderPresent(renderer);
	
	
	//looking for keypresses
	SDL_Event event;
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	
	int mouseX;
	int mouseY;
		
	while(true){
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_MOUSEMOTION:
					SDL_GetMouseState(&mouseX,&mouseY);
					TextBox.x = mouseX-TextBox.w/2;
					TextBox.y = mouseY-TextBox.h/2;
					break;
				case SDL_MOUSEBUTTONDOWN:
					SDL_GetMouseState(&mouseX,&mouseY);
					clicks++;
					break;
			}
		}
		if(keystates[SDL_SCANCODE_ESCAPE]){
			break;
		}
		SDL_PumpEvents();
		SDL_SetRenderDrawColor(renderer,255,255,255,255);
		SDL_RenderClear(renderer);
		//update the surface and texture to correspond to the new clicks int value
		message = TTF_RenderText_Solid(OpenSans,std::to_string(clicks).c_str(),black);
		texture = SDL_CreateTextureFromSurface(renderer,message);
		SDL_RenderCopy(renderer,texture,NULL,&TextBox);
		SDL_RenderPresent(renderer);
		
	}
	return 0;
}
