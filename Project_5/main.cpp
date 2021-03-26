#include <iostream>
#include <string>
#include <cassert>
#include "MegaMillionsLottery.h"
#include "MegaMillionsTicket.h"
#include "RandomNumber.h"
using namespace std;

int main() {
	MegaMillionsTicket t (1, 10, 9, 8, 7, 6);
	cout << t.getBall1() << endl;
	cout << t.getBall2()<<endl;
	cout << t.getBall3()<<endl;
	cout << t.getBall4()<<endl;
	cout << t.getBall5()<<endl;
	cout << t.getMegaBall()<<endl;
	MegaMillionsLottery l(1, 2, 3, 4, 5, 6);
	cout << l.getBall1()<<endl;
	cout << l.getBall2()<<endl;
	cout << l.getBall3()<<endl;
	cout << l.getBall4()<<endl;
	cout << l.getBall5()<<endl;
	cout << l.getMegaBall()<<endl;
	MegaMillionsTicket a=l.quickPick();
	l.checkTicket(a);
	cout << l.whatHappened(a) << endl;
    MegaMillionsTicket q(34, 12, 8, 45, 32, 6);
    assert(q.getBall1() == 34);
    assert(q.getBall2() == 12);
    assert(q.getBall3() == 8);
    assert(q.getBall4() == 45);
    assert(q.getBall5() == 32);
    assert(q.getMegaBall() == 6);
    MegaMillionsLottery w(75, 74, 1, 2, 37, 21);
    assert(w.getBall1() == 75);
    assert(w.getBall2() == 74);
    assert(w.getBall3() == 1);
    assert(w.getBall4() == 2);
    assert(w.getBall5() == 37);
    assert(w.getMegaBall() == 21);

    MegaMillionsTicket ticket(1, 2, 3, 4, 5, 6);
    assert(ticket.getBall1() == 1);
    assert(ticket.getBall2() == 2);
    assert(ticket.getBall3() == 3);
    assert(ticket.getBall4() == 4);
    assert(ticket.getBall5() == 5);
    assert(ticket.getMegaBall() == 6);
    MegaMillionsLottery lottery(1, 2, 3, 4, 5, 6);
    assert(lottery.getBall1() == 1);
    assert(lottery.getBall2() == 2);
    assert(lottery.getBall3() == 3);
    assert(lottery.getBall4() == 4);
    assert(lottery.getBall5() == 5);
    assert(lottery.getMegaBall() == 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 5 balls plus the megaball!");

    ticket = MegaMillionsTicket(1, 2, 3, 4, 5, 12);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVE);
    assert(lottery.whatHappened(ticket) == "You matched 5 balls!");

    MegaMillionsLottery lottery1(74, 71, 33, 14, 49, 26);
    ticket = MegaMillionsTicket(74, 2, 33, 14, 49, 26);
    assert(lottery1.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FOURPLUSMEGABALL);
    assert(lottery1.whatHappened(ticket) == "You matched 4 balls plus the megaball!");


    ticket = MegaMillionsTicket(1, 2, 3, 4, 15, 12);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FOUR);
    assert(lottery.whatHappened(ticket) == "You matched 4 balls!");

    MegaMillionsLottery lottery3(74, 71, 33, 14, 49, 26);
    ticket = MegaMillionsTicket(74, 2, 33, 14, 15, 26);
    assert(lottery3.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::THREEPLUSMEGABALL);
    assert(lottery3.whatHappened(ticket) == "You matched 3 balls plus the megaball!");

    MegaMillionsLottery lottery4(74, 71, 33, 14, 49, 26);
    ticket = MegaMillionsTicket(74, 2, 33, 14, 15, 4);
    assert(lottery4.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::THREE);
    assert(lottery4.whatHappened(ticket) == "You matched 3 balls!");

    MegaMillionsLottery lottery5(14, 45, 3, 54, 38, 5);
    ticket = MegaMillionsTicket(74, 2, 3, 24, 38, 5);
    assert(lottery5.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::TWOPLUSMEGABALL);
    assert(lottery5.whatHappened(ticket) == "You matched 2 balls plus the megaball!");

    MegaMillionsLottery lottery6(4, 1, 3, 7, 9, 6);
    ticket = MegaMillionsTicket(74, 2, 33, 14, 9, 6);
    assert(lottery6.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::ONEPLUSMEGABALL);
    assert(lottery6.whatHappened(ticket) == "You matched 1 ball plus the megaball!");

    MegaMillionsLottery lottery7(74, 71, 33, 14, 49, 26);
    ticket = MegaMillionsTicket(47, 2, 66, 23, 15, 26);
    assert(lottery7.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::MEGABALL);
    assert(lottery7.whatHappened(ticket) == "You matched the megaball!");

    MegaMillionsLottery lottery8(74, 71, 33, 14, 49, 33);
    ticket = MegaMillionsTicket(33, 14, 66, 71, 34, 33);
    assert(lottery8.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::THREEPLUSMEGABALL);
    assert(lottery8.whatHappened(ticket) == "You matched 3 balls plus the megaball!");

    MegaMillionsLottery lottery2(35, 12, 34, 54, 50, 23);
    ticket = MegaMillionsTicket(1, 2, 3, 4, 15, 12);
    assert(lottery2.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::NOTWINNING);
    assert(lottery2.whatHappened(ticket) == "You didn't win anything at all!");



    MegaMillionsTicket quickPickTicket(1, 2, 3, 4, 5, 6);
    for (int i = 0; i < 20; i++)
    {
        quickPickTicket = lottery.quickPick();
        // all the ball numbers need to be different...
        assert(quickPickTicket.getBall1() != quickPickTicket.getBall2() &&
            quickPickTicket.getBall1() != quickPickTicket.getBall3() &&
            quickPickTicket.getBall1() != quickPickTicket.getBall4() &&
            quickPickTicket.getBall1() != quickPickTicket.getBall5() &&
            quickPickTicket.getBall2() != quickPickTicket.getBall3() &&
            quickPickTicket.getBall2() != quickPickTicket.getBall4() &&
            quickPickTicket.getBall2() != quickPickTicket.getBall5() &&
            quickPickTicket.getBall3() != quickPickTicket.getBall4() &&
            quickPickTicket.getBall3() != quickPickTicket.getBall5() &&
            quickPickTicket.getBall4() != quickPickTicket.getBall5());
    }
}