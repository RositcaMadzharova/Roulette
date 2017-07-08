//============================================================================
// Name        : Roulette.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Pools.h"
#include "Credits.h"
#include "Globals.h"
using namespace std;

int main(int args, char* argc[]) {
Credits cr(200);
cout<<cr.GetCredit();
Pools p1(cr,5,5,5);


cout<<p1.PossibleWin()<<endl;

gWindow=SDL_CreateWindow("Main viktor ",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_W,SCREEN_H,0);\
gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
SDL_Surface * background = IMG_Load("chessboard.png");
SDL_Texture * texture=SDL_CreateTextureFromSurface(gRenderer,background);
SDL_RenderCopy(gRenderer,texture,NULL,NULL);
SDL_RenderPresent(gRenderer);

p1.loadFromFile(gRenderer,"Pools.png");
SDL_Rect rec= {0,0,118,118};
p1.render(gRenderer,&rec,0,SDL_FLIP_NONE);

//SDL_RenderCopy(gRenderer,p1.mTexture,NULL,&rec);
//SDL_RenderPresent(gRenderer);
SDL_Delay(5000);

	return 0;
}
