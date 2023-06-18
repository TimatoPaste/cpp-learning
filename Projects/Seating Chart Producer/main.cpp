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
	Desk first;
	first.drawn = true;
	first.textDisplay = true;
	first.text = "hi";//later replace with student names and grades
	first.renderer = renderer;
	
	desks.push_back(first);
	
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	int mouseX;
	int mouseY;
	while(true){
		//gets mouse x and y
		SDL_GetMouseState(&mouseX,&mouseY);
		
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			//creates new desk each click, replacing the current desk at the back of the vector
			if(event.type == SDL_MOUSEBUTTONDOWN){
				if(event.button.button == SDL_BUTTON_LEFT){
					Desk newDesk;
						newDesk.drawn = true;
						newDesk.textDisplay = true;
						newDesk.text = "hi";
						newDesk.renderer = renderer;
						desks.push_back(newDesk);
				}
				else if(event.button.button == SDL_BUTTON_RIGHT){
					std::cout<<"right click";
				}
			}
		}
		
		if(keystates[SDL_SCANCODE_ESCAPE]){
			break;
		}
		
		if(keystates[SDL_SCANCODE_S]){
			std::cout<<"starting sorting now!";
		}
		
		//updates keystates array
		SDL_PumpEvents();
		
		//clear frame + draw new
		SDL_SetRenderDrawColor(renderer,255,255,255,255);
		SDL_RenderClear(renderer);
		
		//current desk follows mouse, centered
		desks[desks.size()-1].desk.x = mouseX-desks[desks.size()-1].desk.w/2;
		desks[desks.size()-1].desk.y = mouseY-desks[desks.size()-1].desk.h/2;
		
		//renders desks
		for(int a = 0;a<desks.size();a++){
			desks[a].stamp();
		}
		
		SDL_RenderPresent(renderer);
	}
	return 0;
}


/*
Note to self:

-when implementing the sort and display, make sure not to include the desk that is following the cursor.

To do:

-implement way to group tables while placing them, maybe one key will cycle through existing groups while another key creates a new group or deletes one



*/