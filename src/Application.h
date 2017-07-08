/*
 * Application.h
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Intro.h"
#include "GameMode.h"
#include "Info.h"
#include "Win.h"
#include "Acounting.h"
#include "Music.h"

class Application
{
public:
	Application();
	virtual ~Application();

	void ShowBakgound();

	void AutoSave(); // to XML
	void Load(); // from XML

	void NewGame(); // free XML


private:
	int state; //which background using

	Intro intro;
	GameMode game;
	Info info;
	Win win;
	Acounting accounting;

};

#endif /* APPLICATION_H_ */
