#pragma once
#include "SDL.h"
#include <vector>

struct Point
{
	int x = 0;
	int y = 0;
};

class SDL_Circle
{
public:
	SDL_Circle();
	//h, k are based on standard mathematical formula of a circle where the center is C(h, k)
	SDL_Circle(int radius, int h, int k);
	int SDL_RenderDrawCircle(SDL_Renderer *renderer);
	int SDL_RenderFillCircle(SDL_Renderer *renderer);
	int SDL_DijkstraFill(SDL_Renderer *renderer);
	int RadiusError(int x, int y);

private:
	int radius;
	int h;
	int k;
};

