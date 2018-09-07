//
//  History.cpp
//  Project1
//
//  Created by Maddy Westergaard on 4/6/18.
//  Copyright © 2018 Maddy Westergaard. All rights reserved.
//

#include "History.h"
#include "globals.h"

globals g4;

History::History(int nRows, int nCols)
{
    m_nRows = nRows;
    m_nCols = nCols;
    
    for (int i = 0; i < m_nRows; i++)
    {
        for (int j = 0; j < m_nCols; j++)
        {
            positions[i][j] = 0;
        }
    }
}

bool History::record(int r, int c)
{
    if (r<1 || r > m_nRows || c<1 || c > m_nCols)
        return false;
    
    positions[r-1][c-1]++;
    return true;
}

void History::display() const
{
    // Position (row,col) in the city coordinate system is represented in
    // the array element grid[row-1][col-1]
    
    char grid1[globals::MAXROWS][globals::MAXCOLS];
    
    // Fill the grid with dots
    for (int r = 0; r < m_nRows; r++)
        for (int c = 0; c < m_nCols; c++)
            grid1[r][c] = '.';
    
    for (int i = 0; i < m_nRows; i++)
    {
        for (int j = 0; j < m_nCols; j++)
        {
            if (positions[i][j] != 0)
                grid1[i][j] = (char) (positions[i][j] + '@');
        }
    }
    
    g4.clearScreen();
    
    for (int r = 0; r < m_nRows; r++)
    {
        for (int c = 0; c < m_nCols; c++)
            cout << grid1[r][c];
        cout << endl;
    }
    cout << endl;
}

