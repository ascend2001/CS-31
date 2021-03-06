//
//  main.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright ? 2017 Howard Stahl. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Die.h"
#include "Player.h"
#include "Centennial.h"
#include "Board.h"


void clearScreen();

int main()
{
    using namespace cs31;
    using namespace std;

    clearScreen();

    Centennial game;
    Centennial game3;//
    std::string action, message = "(r)oll (q)uit: ";
    std::cout << message;

    // for now...
    int i, value;
    Die d1;
    Die d2;
    Die d,d3,d4,d5,d6;
    for (i = 1; i <= 50; i++)
    {
        d.roll();
        value = d.getValue();
        assert(value >= 1 && value <= 6);
    }
    // Player test code
    Player p, human, computer;
    Player p2, human2, computer2;       //for own testing purposes.
    // in the beginning of time, nothing has been rolled yet and the spot needed is 1...
    assert(!p.hasRolledOne());
    assert(!p.hasRolledTwo());
    assert(!p.hasRolledThree());
    assert(!p.hasRolledFour());
    assert(!p.hasRolledFive());
    assert(!p.hasRolledSix());
    assert(!p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 1);
    // now the player has rolled 1... so the spot next needed is 2...
    p.rolled(1);
    assert(p.hasRolledOne());
    assert(!p.hasRolledTwo());
    assert(!p.hasRolledThree());
    assert(!p.hasRolledFour());
    assert(!p.hasRolledFive());
    assert(!p.hasRolledSix());
    assert(!p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 2);
    // only rolls from 1-12 are relevant...
    p.rolled(100);
    assert(p.hasRolledOne());
    assert(!p.hasRolledTwo());
    assert(p.whatSpotIsNeededNext() == 2);
    // rolls must be sequential for things to count...
    //rolls must also turn the appropriate the hasRolled booleans to true.
    p.rolled(3);
    assert(p.hasRolledOne());
    assert(!p.hasRolledTwo());
    assert(!p.hasRolledThree());
    assert(p.whatSpotIsNeededNext() == 2);
    p.rolled(2);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(!p.hasRolledThree());
    assert(!p.hasRolledFour());
    assert(!p.hasRolledFive());
    assert(!p.hasRolledSix());
    assert(!p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 3); 
    p.rolled(3);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(!p.hasRolledFour());
    assert(!p.hasRolledFive());
    assert(!p.hasRolledSix());
    assert(!p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 4); 
    p.rolled(4);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(!p.hasRolledFive());
    assert(!p.hasRolledSix());
    assert(!p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 5); 
    p.rolled(5);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(!p.hasRolledSix());
    assert(!p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 6); 
    p.rolled(6);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(!p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 7); 
    p.rolled(7);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 8); 
    p.rolled(8);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(p.hasRolledSeven());
    assert(p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 9); 
    p.rolled(9);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(p.hasRolledSeven());
    assert(p.hasRolledEight());
    assert(p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 10); 
    p.rolled(10);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(p.hasRolledSeven());
    assert(p.hasRolledEight());
    assert(p.hasRolledNine());
    assert(p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 11); 
    p.rolled(11);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(p.hasRolledSeven());
    assert(p.hasRolledEight());
    assert(p.hasRolledNine());
    assert(p.hasRolledTen());
    assert(p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 12);
    p.rolled(12);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(p.hasRolledSeven());
    assert(p.hasRolledEight());
    assert(p.hasRolledNine());
    assert(p.hasRolledTen());
    assert(p.hasRolledEleven());
    assert(p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 13);

    // work the Player via Dies
    d1.setValue(6);
    d2.setValue(5);
    d3.setValue(4);
    p.roll(d1, d2, d3);
    assert(p.whatWasRolled() == "Die1: 6 Die2: 5 Die3: 4\n");

    // Board test code
    Board b;
    assert(b.getHumanSpot() == 0);
    assert(b.getComputerSpot() == 0);
    assert(b.isGameOver() == false);
    assert(b.isHumanWinner() == false);
    b.setHumanSpot(3);
    b.setComputerSpot(6);
    assert(b.getHumanSpot() == 3);
    assert(b.getComputerSpot() == 6);
    assert(b.isGameOver() == false);
    assert(b.isHumanWinner() == false);
    b.setHumanSpot(12);
    assert(b.getHumanSpot() == 12);
    assert(b.getComputerSpot() == 6);
    assert(b.isGameOver() == false);
    assert(b.isHumanWinner() == false);
    b.setGameOver(true);
    b.markHumanAsWinner();
    assert(b.isGameOver() == true);
    assert(b.isHumanWinner() == true);

    // Centennial test code
    assert(game.isGameOver() == false);
    assert(game.determineGameOutcome() == Centennial::GAMENOTOVER);
    human = game.getHuman();
    computer = game.getComputer();
    assert(human.whatSpotIsNeededNext() == 1);
    assert(computer.whatSpotIsNeededNext() == 1);
    d1.setValue(1);
    d2.setValue(2);
    d3.setValue(3);
    d4.setValue(4);
    d5.setValue(5);
    d6.setValue(6);
    game.humanPlay(d6, d5, d4);
    human = game.getHuman();
    assert(human.whatSpotIsNeededNext() == 1);
    game.computerPlay(d1, d2, d3);
    computer = game.getComputer();
    assert(computer.whatSpotIsNeededNext() == 7);
    game.humanPlay(d4, d2, d1);
    human = game.getHuman();
    assert(human.whatSpotIsNeededNext() == 8);
    game.computerPlay(d5, d2, d1);
    computer = game.getComputer();
    assert(computer.whatSpotIsNeededNext() == 9);
    game.humanPlay(d6, d2, d3);
    human = game.getHuman();
    assert(human.whatSpotIsNeededNext() == 10);
    game.computerPlay(d1, d2, d3);
    computer = game.getComputer();
    assert(computer.whatSpotIsNeededNext() == 9);
    game.humanPlay(d4, d5, d6);
    human = game.getHuman();
    assert(human.whatSpotIsNeededNext() == 12);
    game.computerPlay(d3, d2, d1);
    computer = game.getComputer();
    assert(computer.whatSpotIsNeededNext() == 9);
    assert(game.isGameOver() == false);
    assert(game.determineGameOutcome() == Centennial::GAMENOTOVER);
    game.humanPlay(d2, d4, d6);
    assert(game.isGameOver() == true);
    assert(game.determineGameOutcome() == Centennial::HUMANWONGAME);
    game3.humanPlay(d1, d1, d1);
    assert(game3.isGameOver() == false);
    human2 = game3.getHuman();
    assert(human2.whatSpotIsNeededNext() == 4);
    game3.humanPlay(d4, d5, d6);
    assert(game3.isGameOver() == false);
    human2 = game3.getHuman();
    assert(human2.whatSpotIsNeededNext() == 7);
    computer2 = game3.getComputer();
    game3.computerPlay(d3, d2, d1);
    assert(game3.isGameOver() == false);
    computer2 = game3.getComputer();
    assert(computer2.whatSpotIsNeededNext() == 7);
    game3.computerPlay(d1, d3, d5);
    assert(game3.isGameOver() == false);
    computer2 = game3.getComputer();
    assert(game3.determineGameOutcome() == Centennial::GAMENOTOVER);
    assert(computer2.whatSpotIsNeededNext() == 7);
    game3.humanPlay(d4, d2, d6);
    assert(game3.isGameOver() == false);
    assert(game3.determineGameOutcome() == Centennial::GAMENOTOVER);
    human2 = game3.getHuman();
    assert(human2.whatSpotIsNeededNext() == 7);
    game3.humanPlay(d4, d1, d5);
    assert(game3.isGameOver() == false);
    assert(game3.determineGameOutcome() == Centennial::GAMENOTOVER);
    human2 = game3.getHuman();
    assert(human2.whatSpotIsNeededNext() == 7);
    


    //cout << "all tests passed!" << endl;
    //return 0;
    Centennial game2;
    do
    {
        getline(cin, action);
        while (action.size() == 0)
        {
            getline(cin, action);  // no blank entries allowed....
        }
        switch (action[0])
        {
        default:   // if bad move, nobody moves
            cout << '\a' << endl;  // beep
            continue;
        case 'Q':
        case 'q':
            return 0;
        case 'r':
        case 'R':
            game2.humanPlay();
            cout << game2.display("") << endl;
            if (!game2.isGameOver())
            {
                game2.computerPlay();
                cout << game2.display(message) << endl;
            }
            break;
        }

    } while (!game2.isGameOver());

   
    return(0);
}


///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
        &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr || strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif

