#include "SDL_Circle.h"
#include <iostream>
#include <stack>

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
	int xt = h;
	int xb = xt;
	int y = k;
	int yl = y;
	int yt = k - radius;
	int yb = k + radius;
	int RE;
	int RE2;
	bool WhichCheck = h >= k;
	bool Check1;
	bool Check2;
	if (WhichCheck)
	{
		Check1 = x > y + std::abs(h - k);
		Check2 = yb > xt - std::abs(h - k);
	}
	else
	{
		Check1 = x > y - std::abs(h - k);
		Check2 = yb > xt + std::abs(h - k);
	}
	SDL_RenderDrawPoint(renderer, h, k);
	//originally was just using while (x > y) but that caused gaps.
	//the y-1 allows for overlap which gets rid of the gaps. there are still missing pixels
	//but this is likely due to the error in the radius and needing to use ints (pixels)
	while (Check1)
	{
		if ((1 + (h << 1)) == (x << 1))
		{
			std::cout << "Division by zero error" << std::endl;
			break;
		}
		RE = RadiusError(x, y);
		SDL_RenderDrawPoint(renderer, x, y);
		SDL_RenderDrawPoint(renderer, x, yl);
		SDL_RenderDrawPoint(renderer, xl, y);
		SDL_RenderDrawPoint(renderer, xl, yl);		
		++y;
		--yl;
		
		if (RE > std::abs(h - k))
		{
			--x;
			++xl;
		}
		
		if (WhichCheck)
		{
			Check1 = x > y + std::abs(h - k);
		}
		else
		{
			Check1 = x > y - std::abs(h - k);
		}
	}
	while (Check2)
	{
		++xt;
		--xb;
		RE2 = RadiusError(xt, yb);
		SDL_RenderDrawPoint(renderer, xt, yt);
		SDL_RenderDrawPoint(renderer, xb, yt);
		SDL_RenderDrawPoint(renderer, xt, yb);
		SDL_RenderDrawPoint(renderer, xb, yb);
		if (RE2 > 0)
		{
			--yb;
			++yt;
		}
		if (WhichCheck)
		{
			Check2 = yb > xt - std::abs(h - k);
		}
		else
		{
			Check2 = yb > xt + std::abs(h - k);
		}
	}
	return -1;
}

int SDL_Circle::SDL_RenderFillCircle(SDL_Renderer* renderer)
{
	int x = h + radius;
	int xl = h - radius;
	int xt = h - 1;
	int xb = xt + 2;
	int y = k;
	int yl = y;
	int yt = k - radius;
	int yb = k + radius;
	int RE;
	int RE2;
	bool WhichCheck = h >= k;
	bool Check1;
	bool Check2;
	if (WhichCheck)
	{
		Check1 = x > y + std::abs(h - k);
		Check2 = yb > xt - std::abs(h - k);
	}
	else
	{
		Check1 = x > y - std::abs(h - k);
		Check2 = yb > xt + std::abs(h - k);
	}
	SDL_RenderDrawPoint(renderer, h, k);

	while (Check1)
	{
		if ((1 + (h << 1)) == (x << 1))
		{
			std::cout << "Division by zero error" << std::endl;
			break;
		}
		RE = RadiusError(x, y);
		SDL_RenderDrawLine(renderer, h, k, x, y);
		SDL_RenderDrawLine(renderer, h, k, x, yl);
		SDL_RenderDrawLine(renderer, h, k, xl, y);
		SDL_RenderDrawLine(renderer, h, k, xl, yl);
		++y;
		--yl;

		if (RE > std::abs(h - k))
		{
			--x;
			++xl;
		}

		if (WhichCheck)
		{
			Check1 = x > y + std::abs(h - k);
		}
		else
		{
			Check1 = x > y - std::abs(h - k);
		}
	}
	while (Check2)
	{
		++xt;
		--xb;
		RE2 = RadiusError(xt, yb);
		SDL_RenderDrawLine(renderer, h, k, xt, yt);
		SDL_RenderDrawLine(renderer, h, k, xb, yt);
		SDL_RenderDrawLine(renderer, h, k, xt, yb);
		SDL_RenderDrawLine(renderer, h, k, xb, yb);
		if (RE2 > 0)
		{
			--yb;
			++yt;
		}
		if (WhichCheck)
		{
			Check2 = yb > xt - std::abs(h - k);
		}
		else
		{
			Check2 = yb > xt + std::abs(h - k);
		}
	}
	return -1;
}

int SDL_Circle::RadiusError(int x, int y)
{
	//bitshifting avoids overflows and allows us to keep ints.
	//avoiding using math library for things like pow because that would return a double
	//which is why something like (x*x) is used; to avoid casting.
	int RE = (x*x) - ((x*h)<<1) + (h*h) + (y*y) - ((y*k)<<1) + (y<<1) - (k<<1) + (k*k) + 1 - (radius*radius);
	int XC = 1 + (h<<1) - (x<<1);
	return (RE<<1) + XC;
}

int SDL_Circle::SDL_DijkstraFill(SDL_Renderer* renderer)
{
	std::stack<Point> points;
	Point p;
	for (int i = h - radius; i < h + radius; ++i)
	{
		for (int j = k - radius; j < k + radius; ++j)
		{
			if (((i - h)*(i - h)) + ((j - k)*(j - k)) <= (radius*radius))
			{
				p.x = i;
				p.y = j;
				points.push(p);
			}
		}
	}
	while (!points.empty())
	{
		SDL_RenderDrawPoint(renderer, points.top().x, points.top().y);
		points.pop();
	}
	return -1;
}