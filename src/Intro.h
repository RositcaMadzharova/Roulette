<<<<<<< HEAD
/*
 * Intro.h
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#ifndef INTRO_H_
#define INTRO_H_

#include "Info.h"
#include "Button.h"

class Intro
{
public:
	Intro();
	virtual ~Intro();

	friend void ShowIntro(Intro*);

	void ShowInfo(Info&);
	void ShowGame();
	void ShowNewGame();
	void ChangeVolume(int); // -/+ volume


private:

	Button start;
	Button resume; // load
	Button addCredit; // after clicking wait for input from keyboard
					  // and addCredit in Accounting
	Button volume[2]; // -/+
	Button info;

};

#endif /* INTRO_H_ */
=======
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
>>>>>>> origin/master
