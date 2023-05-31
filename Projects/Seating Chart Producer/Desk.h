#include <SDL2/SDL.h>
#include <string>

using namespace std;
class Desk{
	public:
		//new font to create text objects from
		TFF_Font* font = TFF_OpenFont("OpenSans-Regular.ttf",25);
		SDL_Rect desk;
		//when calling, must dereference later.
		//calling objectName.x will get this pointer if it is public because it is a member of the object
		//*objectName.x gives value
		int* x;
		int* y;
		int* w;
		int* h;
		Desk(int xI,int yI,int wI,int hI,){
			desk.x = xI;
			desk.y = yI;
			desk.w = wI;
			desk.h = hI;
			x = &desk.x;
			y = &desk.y;
			w = &desk.w;
			h = &desk.h;
		}
		void text(SDL_Renderer* renderer,int r,int g,int b){
		}
		void draw(SDL_Renderer* renderer,int r,int g,int b){
			SDL_SetRenderDrawColor(r,g,b);
			SDL_RenderDrawRect(renderer,&desk);
		}
		void fill(SDL_Renderer* renderer,int r,int g,int b){
			SDL_SetRenderDrawColor(r,g,b);
			SDL_RenderFillRect(renderer,&desk);
		}
};