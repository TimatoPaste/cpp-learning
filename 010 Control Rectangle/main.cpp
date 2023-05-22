#include <SDL2/SDL.h>
#include <iostream>

int main(int argc,char* argv[]){
	
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("009 Translate Recycling Rectangle",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800,SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,0);
	
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderClear(renderer);
	
	
	
	SDL_Rect rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = 100;
		rect.h = 100;
	
	//fill first and then draw for the outline to show
	SDL_SetRenderDrawColor(renderer, 188, 140, 255, 255);
	SDL_RenderFillRect(renderer,&rect);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer,&rect);
	
	SDL_RenderPresent(renderer);
	
	
	int recycleCount = 0;
	while(recycleCount < 3){
		rect.x += 10;
		
		
		
		//changing values will not automatically refresh, must clear and then redraw everything
		if(rect.x >= 800){
			rect.x = -100;
			rect.y += rect.h;
		}
		if(rect.y >= 800){
			rect.y = 0;
			recycleCount++;
		}
		
		//clears and redraws to produce the effect of movement
		SDL_SetRenderDrawColor(renderer,255,255,255,255);
		SDL_RenderClear(renderer);
		
		SDL_SetRenderDrawColor(renderer,180,140,255,255);
		SDL_RenderFillRect(renderer,&rect);
		
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
		SDL_RenderDrawRect(renderer,&rect);
		
		SDL_RenderPresent(renderer);
		SDL_Delay(5);
	}
	
	//terminate
	return 0;
}