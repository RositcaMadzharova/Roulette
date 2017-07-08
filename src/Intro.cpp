/*
 * Intro.cpp
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#include "Intro.h"

Intro::Intro()
{
	// TODO Auto-generated constructor stub
	
}

Intro::~Intro()
{
	// TODO Auto-generated destructor stub
}



void ShowIntro(Intro* intro)
{
	//DrawBackground()
	intro->start.Show();
	intro->resume.Show();
	intro->addCredit.Show();
	intro->volume[0].Show();
	intro->volume[1].Show();
	intro->info.Show();
}

void Intro::ShowInfo(Info& info)
{

	ShowInfo(info);

}
void Intro::ShowGame()
{

}

void Intro::ShowNewGame()
{

}
