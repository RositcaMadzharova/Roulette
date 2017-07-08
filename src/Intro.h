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
