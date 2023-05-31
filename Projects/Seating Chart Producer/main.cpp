#include <iostream>
#include <SDL2/SDL.h>
#include "Rectangle.h"
	SDL_Window* window;
	SDL_Renderer* renderer;
int main(int argc,char* argv[]){
	//init true type font to use text
	TTF_Init();
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Seating Chart Maker",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800,SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window,-1,0);
	
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderClear(renderer);
	
	SDL_RenderPresent(renderer);
	
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	Rectangle apple(100,100,100,100);
	
	apple.fill(renderer);
	apple.draw(renderer);
	SDL_RenderPresent(renderer);//updates changes in graphics onto the screen
	
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	while(true){
		if(keystates[SDL_SCANCODE_ESCAPE]){
			break;
		}
		if(keystates[SDL_SCANCODE_A]){
			cout<<*apple.x;
		}
		if(keystates[SDL_SCANCODE_B]){
			apple.translate(1,0);
		}
		SDL_PumpEvents();
		
		//clear frame + draw new
		SDL_SetRenderDrawColor(renderer,255,255,255,255);
		SDL_RenderClear(renderer);
		
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
		apple.fill(renderer);
		apple.draw(renderer);
		SDL_RenderPresent(renderer);
	}
	TTF.Quit();
	SDL.Quit();
	return 0;
}