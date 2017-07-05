/*
 * Intro.h
 *
 *  Created on: 5.07.2017 �.
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

	void showInfo();
	void showGame();
	void showNewGame();
	void changeVolume(int); // -/+ volume

private:
	Info info;
	Button start;
	Button resume; // load
	Button addCredit; // after clicking wait for input from keyboard
					  // and addCredit in Accounting
	Button volume[2]; // -/+
};

#endif /* INTRO_H_ */
