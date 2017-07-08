/*
 * Win.h
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#ifndef WIN_H_
#define WIN_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <ctime>

class Win
{
public:
	Win();
	virtual ~Win();

	void ShowWin(); // show winnig screen for 6s

private:

};

#endif /* WIN_H_ */
