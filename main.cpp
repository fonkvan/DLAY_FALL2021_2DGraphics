#include "SDL.h"
#include <math.h>

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* Window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
	Uint8 x;
	Uint8 y;
	Uint8 r = 250;
	Uint8 h = 500;
	Uint8 k = 500;
	Uint8 y0 = r;
	Uint8 x0 = h + sqrt(pow(r, 2) - pow(y0 - k, 2));
	x = x0;
	y = y0;
	while (x >= y)
	{
		SDL_RenderDrawPoint(Renderer, x, y);
		SDL_RenderDrawPoint(Renderer, -x, y);
		SDL_RenderDrawPoint(Renderer, x, -y);
		SDL_RenderDrawPoint(Renderer, -x, -y);
		x = sqrt(pow(x, 2) - (y<<1) - 1) + h;
		y = y + 1;
	}
	SDL_Delay(5000);
	SDL_DestroyWindow(Window);
	SDL_Quit();
	return(0);
}