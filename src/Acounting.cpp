/*
 * Acounting.cpp
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#include "Acounting.h"

Acounting::Acounting()
{
	bonus = 0;
	creditsBet = 0;
	creditsLeft = 0;
	int myintsb[] =
	{
		2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31,
		33, 35
	};

	for (int i = 0; i < NUMBERS / 2; i++)
	black.insert(myintsb[i]);

	int myintsr[] =
	{
		1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32,
		34, 36
	};

	for (int i = 0; i < NUMBERS / 2; i++)
	red.insert(myintsr[i]);

	// TODO Auto-generated constructor stub

}

Acounting::~Acounting()
{
	// TODO Auto-generated destructor stub
}

