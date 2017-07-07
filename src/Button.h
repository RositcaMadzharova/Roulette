/*
 * Button.h
 *
 *  Created on: Jul 6, 2017
 *      Author: mediff
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include <SDL2/SDL_Ttf.h>
#include <string>
#include <iostream>

class Button {
public:
	Button(SDL_Rect={0,0,0,0},SDL_Rect={0,0,0,0});
	virtual ~Button();
	bool loadFromFile(std::string , SDL_Renderer *);
    bool isHovered();
    bool isClicked(	SDL_Event &e);
	void Render(SDL_Renderer *);
	SDL_Texture * buttonTexture;
	SDL_Rect positionOnScreen;
	SDL_Rect positionFromPicture;
private:


};

#endif /* BUTTON_H_ */
