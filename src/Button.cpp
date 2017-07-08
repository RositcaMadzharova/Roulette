<<<<<<< HEAD
/*
 * Button.cpp
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#include "Button.h"

Button::Button()
{
	height = 0;
	width = 0;
	x = 0;
	y = 0;
	// TODO Auto-generated constructor stub
	
}

Button::~Button()
{
	// TODO Auto-generated destructor stub
}


void Button::Show()
{
	//Draw
}
=======
/*
 * Button.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#include "Button.h"

Button::Button(int x, int y)
	:LTexture(x,y)
{
}

bool Button::isClicked(int x, int y) {
		if (x >= getX() && x <= getWidth() + getX() && y >= getY()
						&& y <= getY() + getHeight()) {

			return true;
		}

	return false;
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

>>>>>>> origin/master
