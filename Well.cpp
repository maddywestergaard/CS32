#include "Well.h"
#include "UserInterface.h"
#include <iostream>
using namespace std;

Well::Well()
{
    for (int i=0; i < WELL_DEPTH ;i++)
    {
        for (int j=0; j < WELL_LENGTH; j++)
        {
            if (i== WELL_DEPTH-1 || j==0 || j == WELL_LENGTH-1)
                m_well[i][j] = '@';
            else
                m_well[i][j] = ' ';
        }
    }
}

void Well::display(Screen& screen, int x, int y)
{
    for (int i=0; i < WELL_DEPTH ;i++)
    {
        for (int j=0; j < WELL_LENGTH; j++)
        {
            cout << m_well[i][j];
        }
        cout << endl;
    }
}

bool Well::rowFilled(int i)
{
    for (int j=0; j < WELL_LENGTH; j++)
    {
        if ( m_well[i][j] != '$')
            return false;
    }
    return true;
}

void Well::destroyRow(int row)
{
    for (int i=0; i < WELL_DEPTH ;i++)
    {
        for (int j=0; j < WELL_LENGTH; j++)
        {
            m_well[i][j] = m_well[i-1][j];
        }
    }
    
    for (int j = 1; j < (WELL_LENGTH-1); j++)
    {
        m_well[0][j] = ' ';
    }
    
    m_well[0][0] = '@';
    m_well[0][WELL_LENGTH-1] = '@';
    rowsDestroyed++;
}

void Well::addPiece(Piece piece, int x, int y)
{
    currentPiece = piece;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            m_well[i+x][j+y] = currentPiece.getChar(i, j);
    
    currentPieceX = x;
    currentPieceY = y;
}

void Well::movePiece(char move)
{
    switch (move)
    {
        case '4':
            if (openLeft())
            {
                currentPieceY--;
                adjustWell();
            }
            break;
        case '6':
            if (openRight())
            {
                currentPieceY++;
                adjustWell();
            }
            break;
        case '2':
            if (openUnder())
            {
                currentPieceX++;
                adjustWell();
            }
        case '8':
        {
            currentPiece.setOrientation(currentPiece.getOrient() + 1);
            adjustWell();
        }
        default:
            break;
    }
}

bool Well::openUnder()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (m_well[i + currentPieceX+1][j + currentPieceY] == '@' || m_well[i + currentPieceX+1][j + currentPieceY] == '$')
                return false;
        }
    }
    return true;
}

bool Well::openLeft()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (m_well[i + currentPieceX][j + currentPieceY - 1] == '@' || m_well[i + currentPieceX][j + currentPieceY - 1] == '$')
                return false;
        }
    }
    return true;
}

bool Well::openRight()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (m_well[i + currentPieceX][j + currentPieceY + 1] == '@' || m_well[i + currentPieceX][j + currentPieceY + 1] == '$')
                return false;
        }
    }
    return true;
}

void Well::adjustWell()
{
    for (int i = 0; i < 4; i++) //adds new piece
    {
        for (int j = 0; j < 4; j++)
        {
            m_well[i + currentPieceX][j + currentPieceY] = currentPiece.getChar(i, j);
        }
    }
    
    for (int i = 0; i < 4; i++) // clears old piece
    {
        for (int j = 0; j < 4; j++)
        {
            if (m_well[currentPieceX-1][j] == '#')
                m_well[currentPieceX-1][j] = ' ';
            
            if (m_well[currentPieceX+4][j] == '#')
                m_well[currentPieceX+4][j] = ' ';
            
            if (m_well[i][currentPieceY-1] == '#')
                m_well[i][currentPieceY-1] = ' ';
            
            if (m_well[i][currentPieceY+4] == '#')
                m_well[i][currentPieceY+4] = ' ';
        }
    }
}

