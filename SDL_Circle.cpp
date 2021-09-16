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
	int RE;
	SDL_RenderDrawPoint(renderer, h, k);
	while (x > y)
	{
		RE = RadiusError(x, y);
		SDL_RenderDrawPoint(renderer, x, y);
		SDL_RenderPresent(renderer);
		SDL_RenderDrawPoint(renderer, x, yl);
		SDL_RenderPresent(renderer);
		SDL_RenderDrawPoint(renderer, xl, y);
		SDL_RenderPresent(renderer);
		SDL_RenderDrawPoint(renderer, xl, yl);
		SDL_RenderPresent(renderer);
		SDL_RenderDrawPoint(renderer, y, x);
		SDL_RenderPresent(renderer);
		SDL_RenderDrawPoint(renderer, y, xl);
		SDL_RenderPresent(renderer);
		SDL_RenderDrawPoint(renderer, yl, x);
		SDL_RenderPresent(renderer);
		SDL_RenderDrawPoint(renderer, yl, xl);
		SDL_RenderPresent(renderer);
		++y;
		--yl;
		if (RE > 0)
		{
			--x;
			++xl;
		}
	}
	//int x = h + radius;
	//int xl = h - radius;
	//int y = k;
	//int yl = y;
	//int initParam = (int)round(pow((double)(x - 0.5), 2.00) + pow((double)(y + 1.00), 2.00) - pow((double)radius, 2.00));
	//int thisParam = initParam;
	//int nextParam;
	//SDL_RenderDrawPoint(renderer, h, k);
	//while (x > y)
	//{
	//	SDL_RenderDrawPoint(renderer, x, y);
	//	SDL_RenderPresent(renderer);
	//	SDL_RenderDrawPoint(renderer, xl, y);
	//	SDL_RenderPresent(renderer);
	//	SDL_RenderDrawPoint(renderer, xl, yl);
	//	SDL_RenderPresent(renderer);
	//	SDL_RenderDrawPoint(renderer, x, yl);
	//	SDL_RenderPresent(renderer);
	//	SDL_RenderDrawPoint(renderer, y, x);
	//	SDL_RenderPresent(renderer);
	//	SDL_RenderDrawPoint(renderer, yl, x);
	//	SDL_RenderPresent(renderer);
	//	SDL_RenderDrawPoint(renderer, y, xl);
	//	SDL_RenderPresent(renderer);
	//	SDL_RenderDrawPoint(renderer, yl, xl);
	//	SDL_RenderPresent(renderer);
	//	++y;
	//	--yl;
	//	if (thisParam <= 0)
	//	{
	//		nextParam = (int)round((double)(thisParam + 2.00*(y + 1.00) + 1.00));
	//	}
	//	else
	//	{
	//		--x;
	//		++xl;
	//		nextParam = (int)round((double)(thisParam + 2.00*(y + 1.00) - 2*(x - 1.00) + 1.00));
	//	}
	//	thisParam = nextParam;
	//}
	return -1;
}

int SDL_Circle::RadiusError(int x, int y)
{
	int RE = (x*x) - ((h*x)<<1) + (h*h) + (y*y) + (((k-1)*y)<<1) + ((k-1) * (k-1)) - (radius * radius);
	int XC = 1 - ((h*x)<<1) - (x<<1);
	return (RE<<1) + XC;
}