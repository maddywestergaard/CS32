//
//  Game.h
//  Project1
//
//  Created by Maddy Westergaard on 4/4/18.
//  Copyright © 2018 Maddy Westergaard. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <stdio.h>

class City;

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nFlatulans);
    ~Game();
    
    // Mutators
    void play();
    int decodeDirection(char dir);
    
    
    static const int UP      = 0;
    static const int DOWN    = 1;
    static const int LEFT    = 2;
    static const int RIGHT   = 3;
    static const int NUMDIRS = 4;
    
private:
    City* m_city;
};


#endif /* Game_h */
