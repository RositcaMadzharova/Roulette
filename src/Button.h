/*
 * Button.h
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#ifndef BUTTON_H_
#define BUTTON_H_

class Button
{
public:
	Button();
	virtual ~Button();

	bool IsHover();
	bool IsClicked();

	void Show();

private:
	int x;
	int y;
	int width;
	int height;

};

#endif /* BUTTON_H_ */
