#include <iostream>
#include <string>
#include <cassert>
#include "MegaMillionsLottery.h"
#include "RandomNumber.h"

MegaMillionsLottery::MegaMillionsLottery(){
	RandomNumber r(1,75);
	RandomNumber s(1, 25);
	mBall1 = r.random();
	mBall2 = r.random();
	mBall3 = r.random();
	mBall4 = r.random();
	mBall5 = r.random();
	mMegaBall = s.random();
	while(mBall1 == mBall2 || mBall1 == mBall3 || mBall1 == mBall4 || mBall1 == mBall5) {		//the while loops ensure that the five balls ae never equal to each other.
		mBall1 = r.random();
	}
	while (mBall2 == mBall3 || mBall2 == mBall4 || mBall2 == mBall5) {
		mBall2 = r.random();
	}
	while (mBall3 == mBall4 || mBall3 == mBall5) {
		mBall3 = r.random();
	}
	while (mBall4 == mBall5) {
		mBall4 = r.random();
	}
}
MegaMillionsLottery::MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball) {
	mBall1 = ball1;					//initializing the private variables to the arguments of the constructor.
	mBall2 = ball2;
	mBall3 = ball3;
	mBall4 = ball4;
	mBall5 = ball5;
	mMegaBall = megaball;
}
int MegaMillionsLottery::getBall1() {			//defining the accessor functions.
	return(mBall1);
}
int MegaMillionsLottery::getBall2() {
	return(mBall2);
}
int MegaMillionsLottery::getBall3() {
	return(mBall3);
}
int MegaMillionsLottery::getBall4() {
	return(mBall4);
}
int MegaMillionsLottery::getBall5() {
	return(mBall5);
}
int MegaMillionsLottery::getMegaBall() {
	return(mMegaBall);
}
MegaMillionsTicket MegaMillionsLottery::quickPick() {
	RandomNumber r(1, 75);
	RandomNumber s(1, 25);
	int b1 = r.random();				//using random to assign a random ball and megaball value.
	int b2 = r.random();
	int b3 = r.random();
	int b4 = r.random();
	int b5 = r.random();
	int mb = s.random();
	while (b1 == b2 || b1 == b3 || b1 == b4 || b1 == b5) {			//while loops ensure that the ticket issued do not have the same five ball values.
		b1 = r.random();
	}
	while (b2 == b3 || b2 == b4 || b2 == b5) {
		b2 = r.random();
	}
	while (b3 == b4 || b3 == b5) {
		b3 = r.random();
	}
	while (b4 == b5) {
		b4 = r.random();
	}
	MegaMillionsTicket ticket(b1, b2, b3, b4, b5, mb);			//creates the ticket that is to be returned.
	/*cout << ticket.getBall1() << endl;			//the commented part was for me to just see if my quickpick function was indeed creating random, unequal values.
	cout << ticket.getBall2() << endl;
	cout << ticket.getBall3() << endl;
	cout << ticket.getBall4() << endl;
	cout << ticket.getBall5() << endl;
	cout << ticket.getMegaBall() << endl;*/
	return (ticket);
}
MegaMillionsLottery::WinningPossibility MegaMillionsLottery::checkTicket(MegaMillionsTicket ticket) {
	int a = ticket.getBall1();
	int b = ticket.getBall2();
	int c = ticket.getBall3();
	int d = ticket.getBall4();
	int e = ticket.getBall5();
	int f = ticket.getMegaBall();
	int outcomecounter = 0;
	MegaMillionsLottery::WinningPossibility outcome;
	int array_lottery[5] = { mBall1,mBall2,mBall3,mBall4,mBall5};	//creates an array to walk over using a for loop
	int array_ticket[5] = { a,b,c,d,e };
	for (int i = 0; i < 5; i++) {			
		b = array_lottery[i];
		for (int j = 0; j < 5; j++) {				//inner for loop ensures that every single value of the lottery balls drawn is checked against every single value of the ticket and not just the corresponding values.
			c = array_ticket[j];
			if (b == c) {
				outcomecounter++;			//counter variable keeps track of how many values match
			}
		}
	}
	if (outcomecounter == 0 && f == mMegaBall) {			//if-statement assigns appropriate enum values based on the extent of tally.
		outcome = MEGABALL;
	}
	else if (outcomecounter == 1 && f == mMegaBall) {
		outcome = ONEPLUSMEGABALL;
	}
	else if (outcomecounter == 2 && f == mMegaBall) {
		outcome = TWOPLUSMEGABALL;
	}
	else if (outcomecounter == 3 && f != mMegaBall) {
		outcome = THREE;
	}
	else if (outcomecounter == 3 && f == mMegaBall) {
		outcome = THREEPLUSMEGABALL;
	}
	else if (outcomecounter == 4 && f != mMegaBall) {
		outcome = FOUR;
	}
	else if (outcomecounter == 4 && f == mMegaBall) {
		outcome = FOURPLUSMEGABALL;
	}
	else if (outcomecounter == 5 && f != mMegaBall) {
		outcome = FIVE;
	}
	else if (outcomecounter == 5 && f == mMegaBall) {
		outcome = FIVEPLUSMEGABALL;
	}
	else{
		outcome = NOTWINNING;
	}
	//cout << outcome << endl; /**/				//diagnostic print statement.
	return (outcome);
}
string MegaMillionsLottery::whatHappened(MegaMillionsTicket ticket) {
	WinningPossibility a = checkTicket(ticket);
	string b = " ";
	switch (a) {					//switch case helps to assign the appropriate string with the appropriate enum value.
	case MEGABALL:
		b = "You matched the megaball!";
		break;
	case ONEPLUSMEGABALL:
		 b= "You matched 1 ball plus the megaball!"  ;
		break;
	case TWOPLUSMEGABALL:
		 b= "You matched 2 balls plus the megaball!"  ;
		break;
	case THREE:
		 b= "You matched 3 balls!"  ;
		break;
	case THREEPLUSMEGABALL:
		 b= "You matched 3 balls plus the megaball!"  ;
		break;
	case FOUR:
		 b= "You matched 4 balls!"  ;
		break;
	case FOURPLUSMEGABALL:
		 b= "You matched 4 balls plus the megaball!"  ;
		break;
	case FIVE:
		 b= "You matched 5 balls!"  ;
		break;
	case FIVEPLUSMEGABALL:
		 b= "You matched 5 balls plus the megaball!"  ;
		break;
	case NOTWINNING:
		 b= "You didn't win anything at all!"  ;
		break;
	default:
		 b= "You didn't win anything at all!"  ;
		break;
	}
	return (b);
}