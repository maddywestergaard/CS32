#include "Game.h"
#include "Well.h"
#include "UserInterface.h"
#include <string>
#include <iostream>

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

const int WELL_X = 0;
const int WELL_Y = 0;

const int PROMPT_Y = 20;
const int PROMPT_X = 0;

const int SCORE_X = 16;
const int SCORE_Y = 8;

const int ROWS_LEFT_X = 16;
const int ROWS_LEFT_Y = 9;

const int LEVEL_X = 16;
const int LEVEL_Y = 10;

const int NEXT_PIECE_TITLE_X = 16;
const int NEXT_PIECE_TITLE_Y = 3;

const int NEXT_PIECE_X = 16;
const int NEXT_PIECE_Y = 4;


Game::Game(int width, int height)
 : m_screen(SCREEN_WIDTH, SCREEN_HEIGHT), m_level(1)
{
}

void Game::play()
{
    m_well.display(m_screen, WELL_X, WELL_Y);
    displayStatus();  //  score, rows left, level
    displayPrompt("Press the Enter key to begin playing Chetyris!");
    waitForEnter();  // [in UserInterface.h]

    std::cout << "hello";
    
    for(;;)
    {
        if ( ! playOneLevel())
            break;
        displayPrompt("Good job!  Press the Enter key to start next level!");
        waitForEnter();
        m_level++;
    }
    displayPrompt("Game Over!  Press the Enter key to exit!");
    waitForEnter();
}

void Game::displayPrompt(std::string s)     
{
    m_screen.gotoXY(PROMPT_X, PROMPT_Y);
    m_screen.printStringClearLine(s);   // overwrites previous text
    m_screen.refresh();
}

void Game::displayStatus()
{
    // [Replace this with code to display the status.]
}

bool Game::playOneLevel()
{
    while (rowsDestroyed != m_level*5 && !lost())
    {
        currentPiece = nextPiece;
        nextPiece = Piece( Piece::chooseRandomPieceType() , 0);
        m_well.addPiece(currentPiece, 0, 3);
        
        Timer t;                 // create and start a timer
        double T = 1000 - (100*(m_level-1));
        
        if (m_level == 1)
            T = 100;
        
        char move = ' ';
        
        while (!hasStopped() && move!='q')
        {
            t.start();
            double d = t.elapsed();
            while (d!= T)
            {
                getCharIfAny(move);
                switch (move)
                {
                    case '2':
                        m_well.movePiece('2');
                        break;
                    case '4':
                        m_well.movePiece('4');
                        break;
                    case '6':
                        m_well.movePiece('6');
                        break;
                    case '8':
                        break;
                    case ' ':
                        break;
                    case 'q':
                        break;
                }
            }
        }
    }
    
    if (rowsDestroyed >= m_level*5)
        return true;
    else
        return false;
}

bool Game::hasStopped()
{
    return !m_well.openUnder();
}

bool Game::lost()
{
    return false;
}
