//makes a green window that closes in 3 seconds

#include <iostream>
#include <SDL2/SDL.h>

//have to have a c header because SDL written in c
int main(int argc,char* argv[]){
	SDL_Init(SDL_INIT_EVERYTHING);
	
	/*
		SDL_Window * SDL_CreateWindow(const char *title,int x, int y, int w, int h, Uint32 flags);
		
		Flags(attributes) from docs:
			SDL_WINDOW_FULLSCREEN - fullscreen window
			SDL_WINDOW_FULLSCREEN_DESKTOP - fullscreen window at the current desktop resolution
			SDL_WINDOW_OPENGL - window usable with OpenGL context
			SDL_WINDOW_VULKAN - window usable with a Vulkan instance
			SDL_WINDOW_SHOWN - window is visible
			SDL_WINDOW_HIDDEN - window is not visible
			SDL_WINDOW_BORDERLESS - no window decoration
			SDL_WINDOW_RESIZABLE - window can be resized
			SDL_WINDOW_MINIMIZED - window is minimized
			SDL_WINDOW_MAXIMIZED - window is maximized
			SDL_WINDOW_INPUT_GRABBED - window has grabbed input focus
			SDL_WINDOW_INPUT_FOCUS - window has input focus
			SDL_WINDOW_MOUSE_FOCUS - window has mouse focus
			SDL_WINDOW_FOREIGN - window not created by SDL
			SDL_WINDOW_ALLOW_HIGHDPI - window should be created in high-DPI mode if supported (>= SDL 2.0.1)
			SDL_WINDOW_MOUSE_CAPTURE - window has mouse captured (unrelated to INPUT_GRABBED, >= SDL 2.0.4)
			SDL_WINDOW_ALWAYS_ON_TOP - window should always be above others (X11 only, >= SDL 2.0.5)
			SDL_WINDOW_SKIP_TASKBAR - window should not be added to the taskbar (X11 only, >= SDL 2.0.5)
			SDL_WINDOW_UTILITY - window should be treated as a utility window (X11 only, >= SDL 2.0.5)
			SDL_WINDOW_TOOLTIP - window should be treated as a tooltip (X11 only, >= SDL 2.0.5)
			SDL_WINDOW_POPUP_MENU - window should be treated as a popup menu (X11 only, >= SDL 2.0.5)
	*/
	
	//declare window
	SDL_Window *window = SDL_CreateWindow("test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,400,SDL_WINDOW_SHOWN);
	
	//declare renderer for the window
	//SDL_CreateRenderer(SDL_Window, index, flags)
	//index means in what order the renderers will initialize because there will sometimes be more than one. -1 means it's the first one
	//later indexes will appear on top of the earlier ones
	//0 means no flags
	/*
		flags:
			SDL_RENDERER_SOFTWARE - the renderer is a software fallback
			SDL_RENDERER_ACCELERATED - the renderer uses hardware acceleration
			SDL_RENDERER_PRESENTVSYNC - present is synchronized with the refresh rate
			SDL_RENDERER_TARGETTEXTURE - the renderer supports rendering to texture
	*/
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	
	//set color of whatever the renderer draws
	//SDL_SetRenderDrawColor(SDL_Renderer,r,g,b,alpha)
	SDL_SetRenderDrawColor(renderer,0,255,0,255);
	
	//fill background color with draw color
	SDL_RenderClear(renderer);
	
	//update the graphics of a renderer based on what changed (in this case, we changed the background color)
	SDL_RenderPresent(renderer);
	
	//waits 3 seconds
	SDL_Delay(3000);
	
	std::cout<<"it worked!";
	//terminates
	return 0;
}