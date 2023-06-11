#include <SDL2/SDL.h>
#include <string>
#include "Student.h"
#include <array>

struct Desk{
	
	TTF_Font* font;
	
	bool drawn;
	std::array<int,3> drawColor;
	
	bool filled;
	std::array<int,3> fillColor;
	
	bool textDisplay;
	std::array<int,3> textColor;
	
	Student student;
	
	SDL_Rect desk;
	
	//constructor for default values
	Desk(){
		font = TTF_OpenFont("OpenSans-Regular.ttf",25);
		drawn = false;
		filled = false;
		textDisplay = false;
		
		for(int a = 0;a<3;a++){
			drawColor[a] = 0;
			fillColor[a] = 0;
			textColor[a] = 0;
		}
		
		desk.x = 0;
		desk.y = 0;
		desk.w = 100;
		desk.h = 50;
	}
	
	void setDrawColor(std::array<int,3> a){
		for(int b = 0;b<drawColor.size();b++){
			drawColor[b] = a[b];
		}
	}
	
	void setFillColor(std::array<int,3> a){
		for(int b = 0;b<fillColor.size();b++){
			fillColor[b] = a[b];
		}
	}
	
	void setTextColor(std::array<int,3> a){
		for(int b = 0;b<textColor.size();b++){
			textColor[b] = a[b];
		}
	}
};