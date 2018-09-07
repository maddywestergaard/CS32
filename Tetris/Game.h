#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Well.h"
#include "UserInterface.h"
#include "Piece.h"
#include <string>
// [Add other #include directives as necessary.]

class Game
{
  public:
    Game(int width, int height);
    void play();
    bool playOneLevel();
    void displayPrompt(std::string s);
    void displayStatus();
    bool isValid();
    bool hasStopped();
    bool lost();
    // [Add other members as necessary.]

  private:
    Well    m_well;
    Screen  m_screen;
    int     m_level;
    Piece   currentPiece;
    Piece   nextPiece;
    int     rowsDestroyed;
    
    // [Add other members as necessary.]
};

#endif // GAME_INCLUDED
