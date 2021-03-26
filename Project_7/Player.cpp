//
//  Player.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"
#include <iostream>

namespace cs31
{
    // set up three six sided dies
    // indicate that none of the spots 1-12 have yet been tossed
    Player::Player() : mDie1(6), mDie2(6), mDie3(6), hasRolled1(false), hasRolled2(false), hasRolled3(false), hasRolled4(false), hasRolled5(false), hasRolled6(false), hasRolled7(false), hasRolled8(false), hasRolled9(false), hasRolled10(false), hasRolled11(false), hasRolled12(false)
    {

    }

    
    void Player::roll(Die d1, Die d2, Die d3)
    {   
        mDie1 = d1;                 //the private member functions are manually assigned to the arguments to enable cheating.
        mDie2 = d2;
        mDie3 = d3;
        int v1 = d1.getValue();     //getting the values rolled by the dice.
        int v2 = d2.getValue();
        int v3 = d3.getValue();
        //if-statements used to assign the appropritate hasRolled member functions to true based on combination of values rolled by dice.
        if (v1 == 1 || v2 == 1 || v3 == 1 || (v1 + v2) == 1 || (v1 + v3) == 1 || (v2 + v3) == 1 || (v1 + v2 + v3) == 1) {
            hasRolled1 = true;
        }
        if ((v1 == 2 || v2 == 2 || v3 == 2 || (v1 + v2) == 2 || (v1 + v3) == 2 || (v2 + v3) == 2 || (v1 + v2 + v3) == 2) ) {
            hasRolled2 = true;
        }
        if ((v1 == 3 || v2 == 3 || v3 == 3 || (v1 + v2) == 3 || (v1 + v3) == 3 || (v2 + v3) == 3 || (v1 + v2 + v3) == 3) ) {
            hasRolled3 = true;
        }
        if ((v1 == 4 || v2 == 4 || v3 == 4 || (v1 + v2) == 4 || (v1 + v3) == 4 || (v2 + v3) == 4 || (v1 + v2 + v3) == 4) ) {
            hasRolled4 = true;
        }
        if ((v1 == 5 || v2 == 5 || v3 == 5 || (v1 + v2) == 5 || (v1 + v3) == 5 || (v2 + v3) == 5 || (v1 + v2 + v3) == 5) ) {
            hasRolled5 = true;
        }
        if ((v1 == 6 || v2 == 6 || v3 == 6 || (v1 + v2) == 6 || (v1 + v3) == 6 || (v2 + v3) == 6 || (v1 + v2 + v3) == 6) ) {
            hasRolled6 = true;
        }
        if ((v1 == 7 || v2 == 7 || v3 == 7 || (v1 + v2) == 7 || (v1 + v3) == 7 || (v2 + v3) == 7 || (v1 + v2 + v3) == 7) ) {
            hasRolled7 = true;
        }
        if ((v1 == 8 || v2 == 8 || v3 == 8 || (v1 + v2) == 8 || (v1 + v3) == 8 || (v2 + v3) == 8 || (v1 + v2 + v3) == 8) ) {
            hasRolled8 = true;
        }
        if ((v1 == 9 || v2 == 9 || v3 == 9 || (v1 + v2) == 9 || (v1 + v3) == 9 || (v2 + v3) == 9 || (v1 + v2 + v3) == 9) ) {
            hasRolled9 = true;
        }
        if ((v1 == 10 || v2 == 10 || v3 == 10 || (v1 + v2) == 10 || (v1 + v3) == 10 || (v2 + v3) == 10 || (v1 + v2 + v3) == 10) ) {
            hasRolled10 = true;
        }
        if ((v1 == 11 || v2 == 11 || v3 == 11 || (v1 + v2) == 11 || (v1 + v3) == 11 || (v2 + v3) == 11 || (v1 + v2 + v3) == 11) ) {
            hasRolled11 = true;
        }
        if ((v1 == 12 || v2 == 12 || v3 == 12 || (v1 + v2) == 12 || (v1 + v3) == 12 || (v2 + v3) == 12 || (v1 + v2 + v3) == 12) ) {
            hasRolled12 = true;
        }// assign each of the arguments to the Player's member variables to enable cheating...
    }

    //randomly roll each of the player's three dies
    void Player::roll()
    {
        mDie1.roll();                   //rolling the three dice to simulate random input.
        mDie2.roll();
        mDie3.roll(); 
        int v1 = mDie1.getValue();      //getting the values rolled by the dice.
        int v2 = mDie2.getValue();
        int v3 = mDie3.getValue();
        //if-statements used to assign the appropritate hasRolled member functions to true based on combination of values rolled by dice.
        if ((v1 == 1 || v2 == 1 || v3 == 1 || (v1 + v2) == 1 || (v1 + v3) == 1 || (v2 + v3) == 1 || (v1 + v2 + v3) == 1)) {
            hasRolled1 = true;
        }
        if ((v1 == 2 || v2 == 2 || v3 == 2 || (v1 + v2) == 2 || (v1 + v3) == 2 || (v2 + v3) == 2 || (v1 + v2 + v3) == 2) ) {
            hasRolled2 = true;
        }
        if ((v1 == 3 || v2 == 3 || v3 == 3 || (v1 + v2) == 3 || (v1 + v3) == 3 || (v2 + v3) == 3 || (v1 + v2 + v3) == 3) ) {
            hasRolled3 = true;
        }
        if ((v1 == 4 || v2 == 4 || v3 == 4 || (v1 + v2) == 4 || (v1 + v3) == 4 || (v2 + v3) == 4 || (v1 + v2 + v3) == 4) ) {
            hasRolled4 = true;
        }
        if ((v1 == 5 || v2 == 5 || v3 == 5 || (v1 + v2) == 5 || (v1 + v3) == 5 || (v2 + v3) == 5 || (v1 + v2 + v3) == 5) ) {
            hasRolled5 = true;
        }
        if ((v1 == 6 || v2 == 6 || v3 == 6 || (v1 + v2) == 6 || (v1 + v3) == 6 || (v2 + v3) == 6 || (v1 + v2 + v3) == 6) ) {
            hasRolled6 = true;
        }
        if ((v1 == 7 || v2 == 7 || v3 == 7 || (v1 + v2) == 7 || (v1 + v3) == 7 || (v2 + v3) == 7 || (v1 + v2 + v3) == 7) ) {
            hasRolled7 = true;
        }
        if ((v1 == 8 || v2 == 8 || v3 == 8 || (v1 + v2) == 8 || (v1 + v3) == 8 || (v2 + v3) == 8 || (v1 + v2 + v3) == 8) ) {
            hasRolled8 = true;
        }
        if ((v1 == 9 || v2 == 9 || v3 == 9 || (v1 + v2) == 9 || (v1 + v3) == 9 || (v2 + v3) == 9 || (v1 + v2 + v3) == 9) ) {
            hasRolled9 = true;
        }
        if ((v1 == 10 || v2 == 10 || v3 == 10 || (v1 + v2) == 10 || (v1 + v3) == 10 || (v2 + v3) == 10 || (v1 + v2 + v3) == 10) ) {
            hasRolled10 = true;
        }
        if ((v1 == 11 || v2 == 11 || v3 == 11 || (v1 + v2) == 11 || (v1 + v3) == 11 || (v2 + v3) == 11 || (v1 + v2 + v3) == 11) ) {
            hasRolled11 = true;
        }
        if ((v1 == 12 || v2 == 12 || v3 == 12 || (v1 + v2) == 12 || (v1 + v3) == 12 || (v2 + v3) == 12 || (v1 + v2 + v3) == 12)) {
            hasRolled12 = true;
        }// randomly roll each of the three Die member variables
    }

    
    int  Player::whatSpotIsNeededNext()
    {
        //the default result is one as at the beginning of the game, both the players are at spot 0.
        int result = 1;
        if (hasRolled1 == true) {       //depending on the hasRolled functions that are true, the available spots are picked.
            result = 2;
        }
        if (hasRolled2 == true && result==2) {      //the && result clause enables the appropriate sequential spot to be picked.
            result = 3;
        }
        if (hasRolled3 == true && result == 3) {
            result = 4;
        }
        if (hasRolled4 == true && result == 4) {
            result = 5;
        }
        if (hasRolled5 == true && result == 5) {
            result = 6;
        }
        if (hasRolled6 == true && result == 6) {
            result = 7;
        }
        if (hasRolled7 == true && result == 7) {
            result = 8;
        }
        if (hasRolled8 == true && result == 8) {
            result = 9;
        }
        if (hasRolled9 == true && result == 9) {
            result = 10;
        }
        if (hasRolled10 == true && result == 10) {
            result = 11;
        }
        if (hasRolled11 == true && result == 11) {
            result = 12;
        }
        if (hasRolled12 == true && result == 12) {
            result = 13;
        }
        switch (result) {               //switch case manually converts all the remaining hasRolled functions to false that may have been made true due to higher irrelevant values of the dice in previous rolls.
        case 1:
            hasRolled1 = false;
            hasRolled2 = false;
            hasRolled3 = false;
            hasRolled4 = false;
            hasRolled5 = false;
            hasRolled6 = false;
            hasRolled7 = false;
            hasRolled8 = false;
            hasRolled9 = false;
            hasRolled10 = false;
            hasRolled11 = false;
            hasRolled12 = false;
            break;
        case 2:
            hasRolled2 = false;
            hasRolled3 = false;
            hasRolled4 = false;
            hasRolled5 = false;
            hasRolled6 = false;
            hasRolled7 = false;
            hasRolled8 = false;
            hasRolled9 = false;
            hasRolled10 = false;
            hasRolled11 = false;
            hasRolled12 = false;
            break;
        case 3:
            hasRolled3 = false;
            hasRolled4 = false;
            hasRolled5 = false;
            hasRolled6 = false;
            hasRolled7 = false;
            hasRolled8 = false;
            hasRolled9 = false;
            hasRolled10 = false;
            hasRolled11 = false;
            hasRolled12 = false;
            break;
        case 4:
            hasRolled4 = false;
            hasRolled5 = false;
            hasRolled6 = false;
            hasRolled7 = false;
            hasRolled8 = false;
            hasRolled9 = false;
            hasRolled10 = false;
            hasRolled11 = false;
            hasRolled12 = false;
            break;
        case 5:
            hasRolled5 = false;
            hasRolled6 = false;
            hasRolled7 = false;
            hasRolled8 = false;
            hasRolled9 = false;
            hasRolled10 = false;
            hasRolled11 = false;
            hasRolled12 = false;
            break;
        case 6:
            hasRolled6 = false;
            hasRolled7 = false;
            hasRolled8 = false;
            hasRolled9 = false;
            hasRolled10 = false;
            hasRolled11 = false;
            hasRolled12 = false;
            break;
        case 7:
            hasRolled7 = false;
            hasRolled8 = false;
            hasRolled9 = false;
            hasRolled10 = false;
            hasRolled11 = false;
            hasRolled12 = false;
            break;
        case 8:
            hasRolled8 = false;
            hasRolled9 = false;
            hasRolled10 = false;
            hasRolled11 = false;
            hasRolled12 = false;
            break;
        case 9:
            hasRolled9 = false;
            hasRolled10 = false;
            hasRolled11 = false;
            hasRolled12 = false;
            break;
        case 10:
            hasRolled10 = false;
            hasRolled11 = false;
            hasRolled12 = false;
            break;
        case 11:
            hasRolled11 = false;
            hasRolled12 = false;
            break;
        case 12:
            hasRolled12 = false;
            break;
        }
                
        return(result);
    }

   
    void Player::rolled(int spot)
    {
        if (spot == 1) {
            hasRolled1 = true;
        }
        if (spot == 2 && whatSpotIsNeededNext()==2) {       //the whatSpotisNeededNext() function in the if-condition makes any calls that are not sequential depending on the position of the player to rolled useless.
            hasRolled2 = true;
        }
        if (spot == 3 && whatSpotIsNeededNext()==3) {
            hasRolled3 = true;
        }
        if (spot == 4 && whatSpotIsNeededNext() == 4) {
            hasRolled4 = true;
        }
        if (spot == 5 && whatSpotIsNeededNext() == 5) {
            hasRolled5 = true;
        }
        if (spot == 6 && whatSpotIsNeededNext() == 6) {
            hasRolled6 = true;
        }
        if (spot == 7 && whatSpotIsNeededNext() == 7) {
            hasRolled7 = true;
        }
        if (spot == 8 && whatSpotIsNeededNext() == 8) {
            hasRolled8 = true;
        }
        if (spot == 9 && whatSpotIsNeededNext() == 9) {
            hasRolled9 = true;
        }
        if (spot == 10 && whatSpotIsNeededNext() == 10) {
            hasRolled10 = true;
        }
        if (spot == 11 && whatSpotIsNeededNext() == 11) {
            hasRolled11 = true;
        }
        if (spot == 12 && whatSpotIsNeededNext() == 12) {
            hasRolled12 = true;
        }
    }

    // trivial getter operation
    Die Player::getDie1() const
    {
        return(mDie1);
    }

    // trivial getter operation
    Die Player::getDie2() const
    {
        return(mDie2);
    }

    // trivial getter operation
    Die Player::getDie3() const
    {
        return(mDie3);
    }

    // trivial getter operation
    bool Player::hasRolledOne() const
    {
        return(hasRolled1);
    }

    // trivial getter operation
    bool Player::hasRolledTwo() const
    {
        return(hasRolled2);
    }

    // trivial getter operation
    bool Player::hasRolledThree() const
    {
        return(hasRolled3);
    }

    // trivial getter operation
    bool Player::hasRolledFour() const
    {
        return(hasRolled4);
    }

    // trivial getter operation
    bool Player::hasRolledFive() const
    {
        return(hasRolled5);
    }

    // trivial getter operation
    bool Player::hasRolledSix() const
    {
        return(hasRolled6);
    }

    // trivial getter operation
    bool Player::hasRolledSeven() const
    {
        return(hasRolled7);
    }

    // trivial getter operation
    bool Player::hasRolledEight() const
    {
        return(hasRolled8);
    }

    // trivial getter operation
    bool Player::hasRolledNine() const
    {
        return(hasRolled9);
    }

    // trivial getter operation
    bool Player::hasRolledTen() const
    {
        return(hasRolled10);
    }

    // trivial getter operation
    bool Player::hasRolledEleven() const
    {
        return(hasRolled11);
    }

    // trivial getter operation
    bool Player::hasRolledTwelve() const
    {
        return(hasRolled12);
    }

    // used solely for testing purposes to see the value of each die
    // if we are using random rolls, we won't know what was tossed
    //         unless we use this operation
    std::string Player::whatWasRolled()
    {
        using namespace std;
        std::string s = "";
        s += "Die1: ";
        s += std::to_string(mDie1.getValue());
        s += " Die2: ";
        s += std::to_string(mDie2.getValue());
        s += " Die3: ";
        s += std::to_string(mDie3.getValue());
        s += "\n";
        return(s);
    }



}
