#pragma once
#include "SDL.h"
#include <math.h>
class SDL_Circle
{
public:
	SDL_Circle();
	//h, k are based on standard mathematical formula of a circle where the center is C(h, k)
	SDL_Circle(int radius, int h, int k);
	int SDL_RenderDrawCircle(SDL_Renderer *renderer);
private:
	int radius;
	int h;
	int k;
	
	/*//Gets rectangle on screen
	SDL_Rect rectangle;
	rectangle.x = 50;
	rectangle.y = 50;
	rectangle.w = 500;
	rectangle.h = 200;
	//Sets rectangle color
	SDL_RenderFillRect(Renderer, &rectangle);	
	*/
};

