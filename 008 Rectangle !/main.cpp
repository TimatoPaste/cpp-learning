//Draws a rectangle in a window and closes after 3 seconds
#include <SDL2/SDL.h>
#include <iostream>

int main(int argc,char* argv[]){
	
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("008 Rectangle!",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800,SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,0);
	
	//layers graphics in order of the commands, so do background first, then the rectangle
	
	//set draw color to white
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	
	//fill background with draw color
	SDL_RenderClear(renderer);
	
	//set draw color to black
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	
	SDL_Rect rect;
		rect.x = 200;
		rect.y = 200;
		rect.w = 200;
		rect.h = 200;
	
	
	//wants address of SDL_Rect object, dereferences in the function
	//draws rectangle with draw color
	SDL_RenderDrawRect(renderer,&rect);
	
	//purple
	SDL_SetRenderDrawColor(renderer, 188, 140, 255, 255);
	
	//fills rectangle purple
	SDL_RenderFillRect(renderer,&rect);
	
	//update graphics based on the changes made
	SDL_RenderPresent(renderer);
	
	//3 second delay
	SDL_Delay(3000);
	
	
	//terminate
	return 0;
}