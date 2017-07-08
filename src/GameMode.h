/*
 * GameMode.h
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#ifndef GAMEMODE_H_
#define GAMEMODE_H_

#include "Globals.h"
#include "Button.h"
#include "NumberButton.h"
#include "RouletteWheel.h"

class GameMode
{
public:
	GameMode();
	virtual ~GameMode();

	friend void ShowGameMode(GameMode*);

	void ShowAccounting();
	int ShowRouletteSpin(); // return winning number
	void ShowLastSpins(); // from XML using TTF

	void ShowGameMode();
private:
	RouletteWheel roulette;
	NumberButton pools[37];
	Button lastSpins;
	Button accounting;
};

#endif /* GAMEMODE_H_ */
