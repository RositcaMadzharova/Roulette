<<<<<<< HEAD
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
=======
/*
 * Button.h
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#include <vector>
#include "LTexture.h"


class Button : public LTexture {
public:
	Button(int x = 0, int y = 0);
	virtual bool isClicked(int x, int y);
	virtual ~Button();
private:
};

#endif /* BUTTON_H_ */
>>>>>>> origin/master
