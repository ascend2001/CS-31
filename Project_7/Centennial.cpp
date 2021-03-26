//
//  Centennial.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Centennial.h"
#include <iostream>
#include <string>

namespace cs31
{
    // human goes first
    Centennial::Centennial() : isHumanTurn(true)
    {

    }

    // prints the state of the game play with each round of play
    std::string Centennial::display(std::string msg)
    {
        using namespace std;
        std::string s("");
        if (isHumanTurn)
        {
            s += "Human-";
            s += mHuman.whatWasRolled();
        }
        else
        {
            s += "Computer-";
            s += mComputer.whatWasRolled();
        }
        s += mBoard.display();

        if (isGameOver())
        {
            if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Centennial!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Centennial!\n";
            }
        }
        else
        {
            s = s + msg;
        }
        return(s);
    }

    //  randomly play a human turn in the game
    void Centennial::humanPlay()
    {
        isHumanTurn = true;
        int spot = mHuman.whatSpotIsNeededNext();   //returns the spot that the player needs
        mHuman.roll();
        Die D1 = mHuman.getDie1();                  //using accessors to get at the value rolled by dice.
        Die D2 = mHuman.getDie2();
        Die D3 = mHuman.getDie3();
        int v1 = D1.getValue();
        int v2 = D2.getValue();
        int v3 = D3.getValue();
        //while loop checks for multiple values that might match the spot or spot++ from the combination of the values showed by the dice.
        while (v1 == spot || v2 == spot || v3 == spot || (v1 + v2) == spot || (v2 + v3) == spot || (v1 + v3) == spot || (v1 + v2 + v3) == spot) {
                mBoard.setHumanSpot(spot);
                spot++;     //to change the spot value in every iteration until the player can't progress any further.
        }
        if (spot == 13) {       //spot 13 would be returned if the player is at spot 12.
            mBoard.markHumanAsWinner();
        }
        
        // mark that it is the human's turn
        // let the human player randomly roll
        // look at what was rolled and update the board spots accordingly
    }

    //  force a certain roll in the human's turn of the game by cheating...
    void Centennial::humanPlay(Die d1, Die d2, Die d3)
    {
        isHumanTurn = true;
        int spot = mHuman.whatSpotIsNeededNext();   //returns the spot that the player needs
        mHuman.roll(d1, d2, d3);                    //assigning the arguments to private member varibales to enable cheating.
        int v1 = d1.getValue();                     //using accessors to get at the value rolled by dice.
        int v2 = d2.getValue();
        int v3 = d3.getValue();
        //while loop checks for multiple values that might match the spot or spot++ from the combination of the values showed by the dice.
        while (v1 == spot || v2 == spot || v3 == spot || (v1 + v2) == spot || (v2 + v3) == spot || (v1 + v3) == spot || (v1 + v2 + v3) == spot) {
            
            mBoard.setHumanSpot(spot);
            
            spot++;                             //to change the spot value in every iteration until the player can't improve any further.
        }
        if (spot == 13) {                   //spot 13 would be returned if the player is at spot 12.
            mBoard.markHumanAsWinner();
        }
        spot = mHuman.whatSpotIsNeededNext();
        
        // mark that it is the human's turn
        // force the human player to cheat
        // look at what was rolled and update the board spots accordingly
    }

    //  randomly play a computer turn in the game
    void Centennial::computerPlay()
    {
        isHumanTurn = false;
        int spot = mComputer.whatSpotIsNeededNext();    //returns the spot that the player needs
        mComputer.roll();                                  //assigning the arguments to private member varibales to enable cheating.
        Die D1 = mComputer.getDie1();                   //using accessors to get at the value rolled by dice.
        Die D2 = mComputer.getDie2();
        Die D3 = mComputer.getDie3();
        int v1 = D1.getValue();
        int v2 = D2.getValue();
        int v3 = D3.getValue();
       
        //while loop checks for multiple values that might match the spot or spot++ from the combination of the values showed by the dice.
        while (v1 == spot || v2 == spot || v3 == spot || (v1 + v2) == spot || (v2 + v3) == spot || (v1 + v3) == spot || (v1 + v2 + v3) == spot) {
            
            mBoard.setComputerSpot(spot);
            
            spot++;                 //to change the spot value in every iteration until the player can't progress any further.
        }
        if (spot == 13) {           //spot 13 would be returned if the player is at spot 12.
            mBoard.markComputerAsWinner();
        }
            
        
        // mark that it is no longer the human's turn
        // let the computer player randomly roll
        // look at what was rolled and update the board spots accordingly
    }

    //  force a certain roll in the computer's turn of the game by cheating...
    void Centennial::computerPlay(Die d1, Die d2, Die d3)
    {
        isHumanTurn = false;
        int spot = mComputer.whatSpotIsNeededNext();    //returns the spot that the player needs
        mComputer.roll(d1,d2,d3);
        int v1 = d1.getValue();                         //using accessors to get at the value rolled by dice.
        int v2 = d2.getValue();
        int v3 = d3.getValue();
        
        //while loop checks for multiple values that might match the spot or spot++ from the combination of the values showed by the dice.
        while (v1 == spot || v2 == spot || v3 == spot || (v1 + v2) == spot || (v2 + v3) == spot || (v1 + v3) == spot || (v1 + v2 + v3) == spot) {
           
            mBoard.setComputerSpot(spot);
            
            spot++;                     //to change the spot value in every iteration until the player can't improve any further.
        }
        if (spot == 13) {           //spot 13 would be returned if the player is at spot 12.
            mBoard.markComputerAsWinner();
        }
           

        
        // mark that it is no longer the human's turn
        // force the computer player to cheat
        // look at what was rolled and update the board spots accordingly
    }

    //  determine the current state of the game
    // Officially, the human won if that player has rolled 12,11,10,9,8,7,6,5,4,3,2 & 1
    // Officially, the computer won if that player has rolled 12,11,10,9,8,7,6,5,4,3,2 & 1
    // If neither, then the game is still underway
    Centennial::GAMEOUTCOME  Centennial::determineGameOutcome() const ///////       
    {
        Centennial::GAMEOUTCOME result = Centennial:: GAMEOUTCOME::GAMENOTOVER; //the default state of the game is that it is in progress.
        if (mBoard.isGameOver()==true && mBoard.isHumanWinner()==true) {    //the human only wins if the game is over and and the human is at the last spot.
            result = GAMEOUTCOME::HUMANWONGAME;
        }
        if (mBoard.isGameOver() == true && mBoard.isHumanWinner() == false){    //the computer only wins if the game is over and and the computer is at the last spot.
            result = GAMEOUTCOME::COMPUTERWONGAME;
        }// for now, just to get it to build...
        return(result);
    }

    //  determine if the game has ended
    // HINT: call determineGameOutcome( )
    bool Centennial::isGameOver()
    {
        bool result = false;
        if (determineGameOutcome()==HUMANWONGAME||determineGameOutcome()==COMPUTERWONGAME) {    //the game is over if either player wins the game.
            result = true;
        }
        // for now, just to get it to build...
        return(result);
    }

    // trivial getter operation
    Player Centennial::getHuman() const
    {
        return(mHuman);
    }

    // trivial getter operation
    Player Centennial::getComputer() const
    {
        return(mComputer);
    }

    // trivial getter operation
    Board  Centennial::getBoard() const
    {
        return(mBoard);
    }
}
