#include <iostream>
#include "SDL2/include/SDL2/SDL.h"
#include "SDL2/include/SDL2/SDL_ttf.h"
#include "Desk.h"
#include "Button.h"
#include "Text.h"
#include <array>
#include <string>
#include <vector>
#include <cmath>

	SDL_Window* window;
	SDL_Renderer* renderer;
int main(int argc,char* argv[]){
	//init true type font to use text
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	window = SDL_CreateWindow("Seating Chart Maker",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800,SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window,-1,0);
	
	//init vector for groups functionality
	Text currentGroupDisplay;//gui
		currentGroupDisplay.renderer = renderer;
		currentGroupDisplay.box.x = 0;
		currentGroupDisplay.box.y = 0;
		currentGroupDisplay.box.w = textWidthFactor;
		currentGroupDisplay.box.h = textWidthFactor*2;
		currentGroupDisplay.text = std::to_string(currentGroup).c_str();

	int currentGroup = 0;
	int textWidthFactor = 20;
	
	std::array<int,3> currentGroupDrawColor = {0,255,0};
	std::array<int,3> defaultDrawColor = {0,0,0};
	
	std::vector<std::vector<Desk>> groups;//data
	std::vector<Desk> firstGroup;
	Desk firstDesk;//first hovering desk
		firstDesk.renderer = renderer;
		firstDesk.drawn = true;
		firstDesk.textDisplay = true;	
		firstDesk.text = "hi";
	firstGroup.push_back(firstDesk);
	groups.push_back(firstGroup);
	
	//vars for user input
	SDL_Event event;
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	int mouseX;
	int mouseY;
	bool overlap;
	while(true){
		SDL_GetMouseState(&mouseX,&mouseY);
		
		//checks if hovering desk is overlapping with any other desks
		overlap = false;
		for(int grpItr = 0;grpItr<groups.size();grpItr++){
			//exclude the hovering desk if checking the current group
			if(grpItr == currentGroup){
				for(int dskItr = 0;dskItr<groups[grpItr].size()-1;dskItr++){
					if(groups[grpItr][dskItr].containsDesk(groups[currentGroup][groups[currentGroup].size()-1])){
						overlap = true;
						break;
					}
				}
			}
			else{
				for(int dskItr = 0;dskItr<groups[grpItr].size();dskItr++){
					if(groups[grpItr][dskItr].containsDesk(groups[currentGroup][groups[currentGroup].size()-1])){
						overlap = true;
						break;
					}
				}
			}
		}
		
		if(keystates[SDL_SCANCODE_ESCAPE]){
			break;
		}
		SDL_PumpEvents();
		
		while(SDL_PollEvent(&event)){
			//switch is more convenient here so that I don't have to reference the members of the event multiple times with if-statements
			switch(event.type){
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym){
						case SDLK_LEFT:
							//changes color of previous group back to normal
							for(int dskItr = 0;dskItr < groups[currentGroup].size();dskItr++){
								groups[currentGroup][dskItr].drawColor = defaultDrawColor;
							}
							if(currentGroup>0){
								//get rid of hovering
								groups[currentGroup].erase(groups[currentGroup].end());
								currentGroup--;
								//adds hovering
								Desk hoverDesk;
									hoverDesk.renderer = renderer;
									hoverDesk.drawn = true;
									hoverDesk.textDisplay = true;	
									hoverDesk.text = "hi";
								groups[currentGroup].push_back(hoverDesk);
								if(groups[groups.size()-1].size() == 0){
									groups.erase(groups.end());
								}
							}
							std::cout<<groups.size()<<"\n";
							for(int a = 0;a<groups.size();a++){
								std::cout<<groups[a].size()<<" ";
							}
							std::cout<<"\n\n";
							break;
						case SDLK_RIGHT:
							//changes color of previous group back to normal
							for(int dskItr = 0;dskItr < groups[currentGroup].size();dskItr++){
								groups[currentGroup][dskItr].drawColor = defaultDrawColor;
							}
						
							//get rid of hovering
							groups[currentGroup].erase(groups[currentGroup].end(),groups[currentGroup].end()+1);
							currentGroup++;
							Desk hoverDesk;
								hoverDesk.renderer = renderer;
								hoverDesk.drawn = true;
								hoverDesk.textDisplay = true;	
								hoverDesk.text = "hi";
							if(currentGroup == groups.size()){
								std::vector<Desk> newGroup;
								//adds hovering
								newGroup.push_back(hoverDesk);
								groups.push_back(newGroup);
							}
							else{
								groups[currentGroup].push_back(hoverDesk);
							}
							
							std::cout<<groups.size()<<"\n";
							for(int a = 0;a<groups.size();a++){
								std::cout<<groups[a].size()<<" ";
							}
							std::cout<<"\n\n";
							break;
					}
					break;
				case SDL_MOUSEBUTTONDOWN:
					switch(event.button.button){
						//erasing from higher groups causes crash due to invalidated pointers. The other ones were safe
						//prevent ptr invalidation by using iterators and setting value to returned one from erase function, ensures all values are valid
						//iterators just point to the address of members of a data structure (address is the index in this case)
						//.begin() points to beginning element .end() points to place after the last element (past-the-end), like the .size() for iterators
						//the iterators hold indexes/addresses as vals, dereference to get the vals from the vector that they are pointing to
						//the type of the iterator pertains to what type of data structure it will be iterating through
						//parentheses around the dereferencing op to prioritize it before functions
						
						case SDL_BUTTON_LEFT:
							if(!overlap){
								Desk newDesk;
									newDesk.renderer = renderer;
									newDesk.drawn = true;
									newDesk.textDisplay = true;	
									newDesk.text = "hi";
								groups[currentGroup].push_back(newDesk);
							}
							else{
								std::cout<<"The desk is overlapping with other desks. Please choose another area\n";
							}
							
							break;
						
						//iterators are not breaking, but why aren't the if statements activating the prints?
						case SDL_BUTTON_RIGHT:
							int group = 0;
							for(std::vector<std::vector<Desk>>::iterator grpItr = groups.begin();grpItr<groups.end();grpItr++){
								if(group == currentGroup){
									//exclude the hovering desk
									for(std::vector<Desk>::iterator dskItr = (*grpItr).begin();dskItr<(*grpItr).end()-1;dskItr++){
										if((*dskItr).containsCoord(mouseX,mouseY)){
											dskItr = (*grpItr).erase(dskItr);
										}
									}
								}
								else{
									for(std::vector<Desk>::iterator dskItr = (*grpItr).begin();dskItr<(*grpItr).end();dskItr++){
										if((*dskItr).containsCoord(mouseX,mouseY)){
											dskItr = (*grpItr).erase(dskItr);
										}
									}
								}
								group++;
							}
							for(std::vector<std::vector<Desk>>::iterator grpItr = groups.end()-1;grpItr > groups.begin()-1;grpItr--){
								if((*grpItr).size() != 0){
									groups.erase(grpItr+1,groups.end());
									break;
								}
							}
							break;
					}
					break;
			}	
		}
		
		//changes color of current group
		for(int dskItr = 0;dskItr < groups[currentGroup].size();dskItr++){
			groups[currentGroup][dskItr].drawColor = currentGroupDrawColor;
		}
		
		//centered current desk onto cursor
		groups[currentGroup][groups[currentGroup].size()-1].desk.x = mouseX-groups[currentGroup][groups[currentGroup].size()-1].desk.w/2;
		groups[currentGroup][groups[currentGroup].size()-1].desk.y = mouseY-groups[currentGroup][groups[currentGroup].size()-1].desk.h/2;
		
		if(overlap){
			groups[currentGroup][groups[currentGroup].size()-1].filled = true;
			groups[currentGroup][groups[currentGroup].size()-1].fillColor = {255,0,0};
			groups[currentGroup][groups[currentGroup].size()-1].text = "Invalid Location";
		}
		else{
			groups[currentGroup][groups[currentGroup].size()-1].filled = false;
			groups[currentGroup][groups[currentGroup].size()-1].fillColor = {0,0,0};
			groups[currentGroup][groups[currentGroup].size()-1].text = "";
		}
		
		//clear frame
		SDL_SetRenderDrawColor(renderer,255,255,255,255);
		SDL_RenderClear(renderer);
		
		//draw desks
		for(int grpItr = 0;grpItr<groups.size();grpItr++){
			for(int dskItr = 0;dskItr<groups[grpItr].size();dskItr++){
				groups[grpItr][dskItr].stamp();
			}
		}
		
		//update group status indicator
		if(currentGroup != 0){
			currentGroupDisplay.box.w = textWidthFactor+textWidthFactor*std::floor(std::log10(currentGroup));
		}
		else{
			currentGroupDisplay.box.w = textWidthFactor;
		}
		
		currentGroupDisplay.text = std::to_string(currentGroup).c_str();
		currentGroupDisplay.stamp();
		
		//update frame
		SDL_RenderPresent(renderer);
	}
	return 0;
}


/*
Note to self:

-group switching is buggy
-jump to case error in the switch for the mouse discrimination


*/