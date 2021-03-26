#ifndef MEGAMILLIONSLOTTERY_H
#define MEGAMILLIONSLOTTERY_H
#include "MegaMillionsTicket.h"
#include <iostream>
#include <string>
using namespace std;

class MegaMillionsLottery {
public:
	enum WinningPossibility {MEGABALL, ONEPLUSMEGABALL, TWOPLUSMEGABALL, THREE, THREEPLUSMEGABALL, FOUR, FOURPLUSMEGABALL, FIVE, FIVEPLUSMEGABALL, NOTWINNING };
	MegaMillionsLottery();
	MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball);
	int getBall1();							//declaring and initializing all the public functions, accessors and enum used to keep track of the extent of tally between the ticket and the lottery.
	int getBall2();
	int getBall3();
	int getBall4();
	int getBall5();
	int getMegaBall();
	MegaMillionsTicket quickPick();
	WinningPossibility checkTicket(MegaMillionsTicket ticket);
	string whatHappened(MegaMillionsTicket ticket);
private:
	int mBall1;
	int mBall2;
	int mBall3;
	int mBall4;
	int mBall5;
	int mMegaBall;
};
#endif