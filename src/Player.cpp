/*
 * Player.cpp
 *
 *  Created on: Jul 5, 2017
 *      Author: mediff
 */

#include "Player.h"

Player::Player(int c,int b ,bool isBet) {
this->credit=c;
this->bet=b;
this->isBet=isBet;

}

void Player::setCredit() {
	this->credit=credit;

}

int Player::getCredit() {
	if(isBet==true)
	{
		credit=credit-bet;
		isBet=false;
	}
	return credit;
}

void Player::setBet(int b) {
	this->bet=(credit>b && b>0)?b:0;
	isBet=true;
}

void Player::PrintInfo() {
	std::cout<<"Credit "<<getCredit()<<std::endl;
	std::cout<<"Bet "<<getBet()<<std::endl;
}

int Player::getBet() {
	return bet;
}

Player::~Player() {

}


