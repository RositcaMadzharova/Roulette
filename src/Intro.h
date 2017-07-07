/*
 * Intro.h
 *
 *  Created on: Jul 6, 2017
 *      Author: mediff
 */

#ifndef INTRO_H_
#define INTRO_H_
#include "Button.h"
#include "Globals.h"
#include <string>

class Intro {
public:
	Intro(std::string);
	virtual ~Intro();
	Button *insertCredit;
	Button *volume[2];
	Button *info;
	Button *startNewGame;
	Button *resumeGame;
private:
	SDL_Surface * introImage;
	SDL_Texture * introTexture;
	SDL_Window * introWindow;
};

#endif /* INTRO_H_ */
