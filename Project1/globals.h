//
//  utilities.h
//  Project1
//
//  Created by Maddy Westergaard on 4/4/18.
//  Copyright © 2018 Maddy Westergaard. All rights reserved.
//

#ifndef globals_h
#define globals_h

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>

using namespace std;

///////////////////////////////////////////////////////////////////////////
// Manifest constants
///////////////////////////////////////////////////////////////////////////
class globals
{
public:
    static const int MAXROWS = 20;               // max number of rows in a city
    static const int MAXCOLS = 30;               // max number of columns in a city
    static const int MAXFLATULANS = 100;         // max number of Flatulans allowed
    static const int INITIAL_PLAYER_HEALTH = 10;
    
    int decodeDirection(char dir);
    int randInt(int min, int max);
    void clearScreen();
    
};

#endif /* globals_h */
