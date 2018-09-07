#ifndef WELL_INCLUDED
#define WELL_INCLUDED

#include "Piece.h"

class Screen;

const int WELL_DEPTH = 20;
const int WELL_LENGTH = 12;

class Well
{
public:
    Well();
    void display(Screen& screen, int x, int y);
    bool rowFilled(int i);
    void destroyRow(int row);
    void addPiece(Piece piece, int x, int y);
    bool openUnder();
    void movePiece(char move);
    bool openLeft();
    bool openRight();
    void adjustWell();
private:
    int rowsDestroyed;
    char m_well[WELL_DEPTH][WELL_LENGTH];
    int currentPieceX;
    int currentPieceY;
    Piece currentPiece;
};

#endif // WELL_INCLUDED
