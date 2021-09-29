#include "SDL.h"
#include "SDL_Circle.h"
#include <cstdlib>
#include <math.h>
#include <ctime>

int main(int argc, char* args[])
{
	std::srand((unsigned int)std::time(NULL));
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* Window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(Renderer, 0, 255, 0, 255);
	SDL_RenderClear(Renderer);
	SDL_Circle circle = SDL_Circle(300, 400, 450);
	SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
	circle.SDL_RenderDrawCircle(Renderer);
	circle.SDL_DijkstraFill(Renderer);
	SDL_Circle circle2;
	int l;
	for (int i = 0; i < 50; ++i)
	{
		SDL_SetRenderDrawColor(Renderer, std::rand()%256, std::rand()%256, std::rand()%256, 255);
		circle2 = SDL_Circle(std::rand()%500, std::rand()%1080, std::rand()%720);
		circle2.SDL_DijkstraFill(Renderer);
		SDL_Delay(100);
		SDL_RenderPresent(Renderer);
	}
	SDL_RenderPresent(Renderer);
	
	SDL_Delay(20000);
	SDL_DestroyWindow(Window);
	SDL_Quit();
	return(0);
}