
#ifndef MEGAMILLIONSTICKET_H
#define MEGAMILLIONSTICKET_H
#include <iostream>
#include <string>
using namespace std;

class MegaMillionsTicket {
public:
	MegaMillionsTicket(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball);
	int getBall1();
	int getBall2();
	int getBall3();
	int getBall4();
	int getBall5();
	int getMegaBall();
private:
	int mBall1;
	int mBall2;
	int mBall3;
	int mBall4;
	int mBall5;
	int mMegaBall;
};
#endif


