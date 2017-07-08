/*
 * NumberButton.cpp
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#include "NumberButton.h"

NumberButton::NumberButton()
{
	number = 0;
	// TODO Auto-generated constructor stub
	
}

NumberButton::~NumberButton()
{
	// TODO Auto-generated destructor stub
}

bool NumberButton::IsHover()
{
	return Button::IsHover();
}
bool NumberButton::IsClicked()
{
	return Button::IsClicked();
}

void NumberButton::Show()
{
	Button::Show();
}
