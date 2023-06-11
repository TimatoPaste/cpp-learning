#include <iostream>
#include "SDL2/include/SDL2/SDL.h"
#include "SDL2/include/SDL2/SDL_ttf.h"
#include "Desk.h"
#include <vector>
#include <cmath>

	SDL_Window* window;
	SDL_Renderer* renderer;
int main(int argc,char* argv[]){
	//init true type font to use text
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	window = SDL_CreateWindow("Seating Chart Maker",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800,SDL_WINDOW_FULLSCREEN_DESKTOP);
	renderer = SDL_CreateRenderer(window,-1,0);
	
	std::vector<Desk> desks;
	Desk current;
	current.drawn = true;
	current.textDisplay = true;
	
	desks.push_back(current);
	
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	int mouseX;
	int mouseY;
	while(true){
		//gets mouse x and y
		SDL_GetMouseState(&mouseX,&mouseY);
		
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			
			switch(event.type){
				case SDL_MOUSEBUTTONDOWN:
					Desk newDesk;
					newDesk.drawn = true;
					newDesk.textDisplay = true;
					desks.push_back(newDesk);
					break;
			}
		}
		
		
		
		if(keystates[SDL_SCANCODE_ESCAPE]){
			break;
		}
		
		if(keystates[SDL_SCANCODE_S]){
			std::cout<<"starting sorting now!";
		}
		SDL_PumpEvents();
		
		//clear frame + draw new
		SDL_SetRenderDrawColor(renderer,255,255,255,255);
		SDL_RenderClear(renderer);
		
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
		desks[desks.size()-1].desk.x = mouseX;
		desks[desks.size()-1].desk.y = mouseY;
		for(int a = 0;a<desks.size();a++){
			if(desks[a].drawn){
				SDL_SetRenderDrawColor(renderer,desks[a].drawColor[0],desks[a].drawColor[1],desks[a].drawColor[2],255);
				SDL_RenderDrawRect(renderer,&desks[a].desk);
			}
			if(desks[a].filled){
				SDL_SetRenderDrawColor(renderer,desks[a].fillColor[0],desks[a].fillColor[1],desks[a].fillColor[2],255);
				SDL_RenderFillRect(renderer,&desks[a].desk);
			}
			if(desks[a].textDisplay){
				SDL_Color color = {desks[a].textColor[0],desks[a].textColor[1],desks[a].textColor[2]};
				SDL_Surface* words = TTF_RenderText_Solid(desks[a].font,"hi",color);//placeholder
				SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,words);
				SDL_RenderCopy(renderer,texture,NULL,&desks[a].desk);
			}
		}
		
		SDL_RenderPresent(renderer);
	}
	return 0;
}