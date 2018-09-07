//
//  History.h
//  Project1
//
//  Created by Maddy Westergaard on 4/6/18.
//  Copyright © 2018 Maddy Westergaard. All rights reserved.
//

#ifndef History_h
#define History_h

#include "globals.h"
#include <stdio.h>

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
private:
    int m_nRows;
    int m_nCols;
    int preachNum;
    int positions[globals::MAXROWS][globals::MAXCOLS];
};

#endif /* History_h */
