//
//  Board.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Board.h"


namespace cs31
{
    Board::Board() : mHumanSpot(0), mComputerSpot(0), mGameOver(false), mHumanWon(false)
    {

    }

    //   trivial setter operation
    void Board::setGameOver(bool value)
    {
        if (value == true || value == false) {      //protects the private variable from being set to any nonsense boolean.
            mGameOver = value;
        }
    }

    //   trivial getter operation
    bool Board::isGameOver() const
    {
        return(mGameOver);       // only returns the mGameOver private variable which is altered by other functions.        
    }

    //   trivial setter operation
    void Board::markHumanAsWinner()
    {
        mGameOver = true;               //marks the game as over and moves the human to spot 12 and changes the mHumanWon boolean to true.
        mHumanWon = true;
        mHumanSpot = 12;
    }

    //   trivial setter operation
    void Board::markComputerAsWinner()
    {
        mGameOver = true;               //marks the game as over and moves the human to spot 12 and changes the mHumanWon boolean to true.
        mHumanWon = false;
        mComputerSpot = 12;
    }

    //   trivial getter operation
    bool Board::isHumanWinner() const
    {
        return(mHumanWon);              //getter operation to access the private variable from other classes.
    }

    // remember how far along the board the human player is
    void Board::setHumanSpot(int spot)
    {
        // the only legal spots are values between 0 and 12
        if (spot >= 0 && spot <= 12)
        {
            mHumanSpot = spot;             //to place the human player to the appropriate spot as returned from the player.whatSpotIsNeededNext() function
        }
    }

    // trivial getter operation
    int  Board::getHumanSpot()
    {
        return(mHumanSpot);
    }

    // trivial getter operation
    int  Board::getComputerSpot()
    {
        return(mComputerSpot);
    }

    // remember how far along the board the computer player is
    void Board::setComputerSpot(int spot)
    {
        // the only legal spots are values between 0 and 12
        if (spot >= 0 && spot <= 12)
        {
            mComputerSpot = spot;               //to place the computer player to the appropriate spot as returned from the player.whatSpotIsNeededNext() function
        }
    }

    // print the state of the board
    // called by Centennial to show the state of game play with each round of play
    std::string Board::display() 
    {
        std::string s = "\t--Centennial Game--\n";
        for (int i = 1; i <= 9 && i <= mHumanSpot; i++)
        {
            s += "  ";
        }
        for (int i = 10; i <= 12 && i <= mHumanSpot; i++)
        {
            s += "   ";
        }
        s += "H";
        if (mGameOver && mHumanWon)
        {
            s += "  << WINNER!";
        }
        s += "\n";
        s += "  1 2 3 4 5 6 7 8 9 10 11 12\n";
        for (int i = 1; i <= 9 && i <= mComputerSpot; i++)
        {
            s += "  ";
        }
        for (int i = 10; i <= 12 && i <= mComputerSpot; i++)
        {
            s += "   ";
        }
        s += "C";
        if (mGameOver && !mHumanWon)
        {
            s += "  << WINNER!";
        }
        s += "\n";
        s += "\n";

        return(s);
    }




}
