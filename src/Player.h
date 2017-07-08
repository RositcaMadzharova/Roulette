/*
 * Player.h
 *
 *  Created on: Jul 5, 2017
 *      Author: mediff
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
using std::cout;
using std::endl;

class Player {

public:
	Player(int c =0,int b=0,bool isBet=false);
	void setCredit();
	int getCredit();
	void setBet(int);
	int getBet();
	void PrintInfo();
	virtual ~Player();
private:
	int credit;
	int bet;
	bool isBet;

};

#endif /* PLAYER_H_ */
