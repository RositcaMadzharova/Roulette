/*
 * GameMode.cpp
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#include "GameMode.h"

GameMode::GameMode()
{
	// TODO Auto-generated constructor stub
	
}

GameMode::~GameMode()
{
	// TODO Auto-generated destructor stub
}


void ShowGameMode(GameMode* gameMode)
{
	//Draw game board
	for(int i = 0; i<NUMBERS; i++)
		gameMode->pools[i].Show();
	gameMode->lastSpins.Show();
	gameMode->accounting.Show();
}
