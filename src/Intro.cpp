/*
 * Intro.cpp
 *
 *  Created on: Jul 6, 2017
 *      Author: mediff
 */

#include "Intro.h"

Intro::Intro(std::string iImage)
{
introWindow=SDL_CreateWindow("Intro Screen",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,0);
gRenderer=SDL_CreateRenderer(introWindow,-1,SDL_RENDERER_PRESENTVSYNC);
introImage=IMG_Load(iImage.c_str());
introTexture=SDL_CreateTextureFromSurface(gRenderer,introImage);

SDL_RenderCopy(gRenderer,introTexture,NULL,NULL);
SDL_RenderPresent(gRenderer);

insertCredit=new Button ({0,0,0,0},{200,100,100,20});
insertCredit->loadFromFile("BUTTON.png",gRenderer);
insertCredit->Render(gRenderer);

volume[0]=new Button ({0,0,0,0},{200,150,100,20});
volume[0]->loadFromFile("BUTTON.png",gRenderer);
volume[0]->Render(gRenderer);

volume[1]=new Button ({0,0,0,0},{300,150,100,20});
volume[1]->loadFromFile("BUTTON.png",gRenderer);
volume[1]->Render(gRenderer);

info=new Button ({0,0,0,0},{200,200,100,20});
info->loadFromFile("BUTTON.png",gRenderer);
info->Render(gRenderer);

startNewGame=new Button ({0,0,0,0},{200,250,100,20});
startNewGame->loadFromFile("BUTTON.png",gRenderer);
startNewGame->Render(gRenderer);

resumeGame=new Button ({0,0,0,0},{200,300,100,20});
resumeGame->loadFromFile("BUTTON.png",gRenderer);
resumeGame->Render(gRenderer);

 SDL_RenderCopy(gRenderer,insertCredit->buttonTexture,NULL,&insertCredit->positionOnScreen);
 SDL_RenderPresent(gRenderer);



}

Intro::~Intro()
{
	delete insertCredit;
	introWindow=NULL;
	introImage=NULL;
	introTexture=NULL;
}

