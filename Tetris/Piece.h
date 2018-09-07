#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED

enum PieceType {
    PIECE_I, PIECE_L, PIECE_J, PIECE_T, PIECE_O, PIECE_S, PIECE_Z,
    PIECE_VAPOR, PIECE_FOAM, PIECE_CRAZY, NUM_PIECE_TYPES
};

class Piece
{
public:
    Piece();
    Piece(PieceType piece, int orient);
    virtual void setOrientation(int num);
    static PieceType chooseRandomPieceType();
    char getChar (int x, int y);
    void setOrientNum( int num);
    void setGrid(int x, int y, char val);
    int getOrient();
private:
    char grid[4][4];
    int orientation;
};

class PieceI : public Piece
{
public:
    virtual void setOrientation(int num);
};

class PieceL : public Piece
{
public:
    virtual void setOrientation(int num);
};

class PieceJ : public Piece
{
public:
    virtual void setOrientation(int num);
};

class PieceT : public Piece
{
public:
    virtual void setOrientation(int num);
};

class PieceO : public Piece
{
public:
    virtual void setOrientation(int num);
};

class PieceS : public Piece
{
public:
    virtual void setOrientation(int num);
};

class PieceZ : public Piece
{
public:
    virtual void setOrientation(int num);
};

class PieceVapor : public Piece
{
public:
    virtual void setOrientation(int num);
};

class PieceFoam : public Piece
{
public:
    virtual void setOrientation(int num);
};

class PieceCrazy : public Piece
{
public:
    virtual void setOrientation(int num);
};

#endif // PIECE_INCLUDED
