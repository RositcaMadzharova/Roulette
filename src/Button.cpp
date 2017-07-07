/*
 * Button.cpp
 *
 *  Created on: Jul 6, 2017
 *      Author: mediff
 */

#include "Button.h"

Button::Button(SDL_Rect source, SDL_Rect destination)
{
	//setting position on screen rect
	positionOnScreen.x = destination.x;
	positionOnScreen.y = destination.y;
	positionOnScreen.w = destination.w;
	positionOnScreen.h = destination.h;

	//setting position from picture
	positionFromPicture.x = source.x;
	positionFromPicture.y = source.y;
	positionFromPicture.w = source.w;
	positionFromPicture.h = source.h;

	//setting button pictures
	buttonTexture = NULL;
}

Button::~Button()
{
	// TODO Auto-generated destructor stub
}

bool Button::loadFromFile(std::string path, SDL_Renderer* renderer)
{
	SDL_Texture* newTexture = NULL;

	//load picture for figures
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL)
	{
		std::cerr << "Unable to load image " << path.c_str()
				<< " SDL_image Error: " << IMG_GetError();
	}
	else
	{

		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			std::cerr << "Unable to create texture from " << path.c_str()
					<< " SDL Error: " << SDL_GetError();
		}
		else
		{
			//get image dimensions;
			positionFromPicture.w = loadedSurface->w;
			positionFromPicture.h = loadedSurface->h;
		}

		//free old surface
		SDL_FreeSurface(loadedSurface);
	}

	//return success
	buttonTexture = newTexture;
	return buttonTexture != NULL;
}

bool Button::isHovered()
{
	int x,y;
	SDL_GetMouseState(&x,&y);
	if (x >= positionOnScreen.x &&
			x <= positionOnScreen.w + positionOnScreen.x &&
			y >= positionOnScreen.y &&
			y <= positionOnScreen.h + positionOnScreen.y)
		{
			//std::cout<<"We are monsterst"<<std::endl;

			return true;
		}
	//std::cout<<"OPaaa"<<std::endl;
	return false;
}

bool Button::isClicked(	SDL_Event &e)
{
	if(isHovered() && e.type==SDL_MOUSEBUTTONDOWN)
		return true;
	return false;
}

void Button::Render(SDL_Renderer* renderer)
{
	SDL_RenderPresent(renderer);
	SDL_RenderCopy(renderer, buttonTexture, &positionFromPicture, &positionOnScreen);
}
