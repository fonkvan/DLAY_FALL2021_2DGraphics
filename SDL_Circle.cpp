#include "SDL_Circle.h"

SDL_Circle::SDL_Circle()
{
	radius = 100;
	h = 0;
	k = 0;
}

SDL_Circle::SDL_Circle(int radius, int h, int k)
{
	SDL_Circle::radius = radius;
	SDL_Circle::h = h;
	SDL_Circle::k = k;
}

int SDL_Circle::SDL_RenderDrawCircle(SDL_Renderer* renderer)
{
	int x = h + radius;
	int xl = h - radius;
	int y = k;
	int yl = y;
	int initParam = (int)round(pow(x - 0.5, 2) + pow(y + 1, 2) - pow(radius, 2));
	int thisParam = initParam;
	int nextParam;
	SDL_RenderDrawPoint(renderer, h, k);
	while (x > y)
	{
		SDL_RenderDrawPoint(renderer, x, y);
		SDL_RenderPresent(renderer);
		SDL_RenderDrawPoint(renderer, xl, y);
		SDL_RenderPresent(renderer);
		SDL_RenderDrawPoint(renderer, xl, yl);
		SDL_RenderPresent(renderer);
		SDL_RenderDrawPoint(renderer, x, yl);
		SDL_RenderPresent(renderer);
		SDL_RenderDrawPoint(renderer, y, x);
		SDL_RenderPresent(renderer);
		SDL_RenderDrawPoint(renderer, yl, x);
		SDL_RenderPresent(renderer);
		SDL_RenderDrawPoint(renderer, y, xl);
		SDL_RenderPresent(renderer);
		SDL_RenderDrawPoint(renderer, yl, xl);
		SDL_RenderPresent(renderer);
		++y;
		--yl;
		if (thisParam <= 0)
		{
			nextParam = (int)round(thisParam + 2*(y + 1) + 1);
		}
		else
		{
			--x;
			++xl;
			nextParam = (int)round(thisParam + 2*(y + 1) - 2*(x - 1) + 1);
		}
		thisParam = nextParam;
	}
	return -1;
}