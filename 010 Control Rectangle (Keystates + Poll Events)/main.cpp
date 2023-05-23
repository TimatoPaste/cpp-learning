//Draws a purple rectangle controllable via WSAD or arrows, recycles at boundaries, esc to exit
#include <SDL2/SDL.h>
#include <iostream>

//globals
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Rect rect;

//clears and redraws everything to keep animation going
void reload(){
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderClear(renderer);
	
	SDL_SetRenderDrawColor(renderer,188,140,255,255);
	SDL_RenderFillRect(renderer,&rect);
	
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderDrawRect(renderer,&rect);
	
	SDL_RenderPresent(renderer);
}

int main(int argc,char* argv[]){
	std::cout<<"WSAD or Arrow Key controls\nEsc to exit";
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("010 Control Rectangle",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800,SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window,-1,0);
	
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderClear(renderer);
	
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
	
	//for the poll events
	SDL_Event event;
	
	//keystates are better for press-and-holds because that way it doesn't take time to accelerate the rate of presses
	//returns array of ints, 1 if key is pressed, 0 if not
	//SDL_GetKeyboardState(int*) returns a const Uint8* array with strings as indexes. The length of the array is put into the int* variable
	const Uint8* keystates = SDL_GetKeyboardState(NULL);//pointer because this is constantly updated by SDL_PumpEvents();
	
	Uint32 mousestates;//not pointer because not updated with method like keystates
	int mouseX;
	int mouseY;
	
	while(true){
		
		//SDL_PollEvent(address of pointer), puts event value into the address
		//SDL_PollEvent(event) returns 0 if there is no event, 1 if there is (0 is false, 1 is true)
		//however, this is better for checking for individual keypresses or events like clicks
		while(SDL_PollEvent(&event)){
			/*
			switch(value)
				case value:
					action
					break;
				case value2:
					action
					break;
			*/
			switch(event.type){
				//different types of mouse events checked for
				//look at events table and their row labeled "type" for the specific event values
				case SDL_MOUSEMOTION:
					/*
					-SDL_GetMouseState(int* x, int* y);
					-position of cursor assigned to x and y variables
					-method returns an array like SDL_GetKeyboardState(), can check for index 
					values in the same way for different types of mouse actions, different indexes
					*/
					//needs addresses in order to change the values, can also put in pointers, but then would need to 
					//dereference them in other references where you want the actual value (*mouseX)
					mousestates = SDL_GetMouseState(&mouseX,&mouseY);
					rect.x = mouseX;
					rect.y = mouseY;
					break;
				case SDL_MOUSEBUTTONDOWN:
					mousestates = SDL_GetMouseState(&mouseX,&mouseY);
					rect.x = mouseX;
					rect.y = mouseY;
					break;
				default:
					break;
			}
			//if i wanted to have the rectangle move only when I press and hold the mouse, I would want to use the array returned by SDL_GetMouseState(int* x, int* y) just like for the keyboard
		}
		
		int step = 5;
		
		//-when the button specified by the index is pressed, 
		//the value at its index in keystates array will be 1 instead of 0
		if(keystates[SDL_SCANCODE_LEFT]||keystates[SDL_SCANCODE_A]){
			rect.x -= step;
		}
		if(keystates[SDL_SCANCODE_RIGHT]||keystates[SDL_SCANCODE_D]){
			rect.x += step;
		}
		if(keystates[SDL_SCANCODE_UP]||keystates[SDL_SCANCODE_W]){
			rect.y -= step;
		}
		if(keystates[SDL_SCANCODE_DOWN]||keystates[SDL_SCANCODE_S]){
			rect.y += step;
		}
		if(keystates[SDL_SCANCODE_ESCAPE]){
			break;
		}
		//checks states instead of individual presses, so will constant instead of slow and then fast
		
		if(rect.x>800){
			rect.x = 0-rect.w;
		}
		else if(rect.x<0-rect.w){
			rect.x = 800;
		}
		if(rect.y>800){
			rect.y = 0-rect.h;
		}
		else if(rect.y<0-rect.h){
			rect.y = 800;
		}
		
		//updates the keystates array
		SDL_PumpEvents();
		//re-renders the graphics
		reload();
		//waits
		SDL_Delay(10);
	}
	
	//terminate
	return 0;
}
