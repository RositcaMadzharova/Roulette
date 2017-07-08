/*
 * NumberButton.h
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#ifndef NUMBERBUTTON_H_
#define NUMBERBUTTON_H_

#include "Button.h"

class NumberButton : public Button
{
public:
	NumberButton();
	virtual ~NumberButton();

	bool IsHover();
	bool IsClicked();

	void Show();
private:
	int number;
};

#endif /* NUMBERBUTTON_H_ */
