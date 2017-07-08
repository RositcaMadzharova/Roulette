/*
 * RouletteWheel.h
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#ifndef ROULETTEWHEEL_H_
#define ROULETTEWHEEL_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <ctime>

const int RADIUS_OF_ROULETTE = 50; // ???
const int RADIUS_OF_NUMBER_RING = 30; // ???

class RouletteWheel
{
public:
	RouletteWheel();
	virtual ~RouletteWheel();

	void Spin(); // spin roulette and ball
				 // from outerRing to numberRing
	int WinningNumber(); // rand() % 37;


private:
	SDL_Texture* ball;
	SDL_Texture* roulette;

	void spinBall();
};

#endif /* ROULETTEWHEEL_H_ */
