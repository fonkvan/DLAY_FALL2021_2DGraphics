#include "SDL.h"
#include "SDL_Circle.h"
#include <math.h>

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* Window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(Renderer, 0, 255, 0, 255);
	SDL_RenderClear(Renderer);
	SDL_Circle circle = SDL_Circle(250, 250, 250);
	SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
	circle.SDL_RenderDrawCircle(Renderer);
	SDL_RenderPresent(Renderer);
	

	//SDL_SetRenderDrawColor(Renderer, 156, 230, 177, 255);
	//SDL_RenderClear(Renderer);
	//SDL_Rect rectangle;
	//rectangle.x = 50;
	//rectangle.y = 50;
	//rectangle.w = 500;
	//rectangle.h = 200;
	////Sets rectangle color
	//SDL_SetRenderDrawColor(Renderer, 255, 255, 0, 255);
	////Gets rectangle on screen
	//SDL_RenderFillRect(Renderer, &rectangle);	
	////forces renderer to update
	//SDL_RenderPresent(Renderer);
	
	
	
	SDL_Delay(10000);
	SDL_DestroyWindow(Window);
	SDL_Quit();
	return(0);
}