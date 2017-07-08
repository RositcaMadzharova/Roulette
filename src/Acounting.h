/*
 * Acounting.h
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#ifndef ACOUNTING_H_
#define ACOUNTING_H_

#include "Globals.h"
#include <set>
using namespace std;

class Acounting
{
public:
	Acounting();
	virtual ~Acounting();

	int getCredits();

	void AddCredits(int); // number of credits
	void AddBet(int); // number of credits bet
	void WinBet(int, double); // credits, multiplier

	void AddBonus(); // after spin of wheel use this
					 // +13% of creditsBet
	double GetBonus();


private:
	set<int> black;
	set<int> red;

	double profitByNumber[37];
	static int creditsIn;
	static int creditsOut;
	int creditsLeft;
	int creditsBet;
	double bonus;
};

#endif /* ACOUNTING_H_ */
