#include "Piece.h"
#include <random>

Piece::Piece()
{

}

void Piece::setOrientation(int num)
{
    orientation = num;
}

Piece::Piece(PieceType piece, int orient)
: orientation(orient)
{
    switch (piece)
    {
        case (PIECE_I):
            if (orientation == 0 || orientation == 2)
            {
                for (int i=0; i<4; i++)
                {
                    for (int j = 0; j<4; j++)
                    {
                        if (i == 1)
                            grid[i][j] = '#';
                        else
                            grid[i][j] = ' ';
                    }
                }
            }
            if (orientation == 1 || orientation == 3)
            {
                for (int i=0; i<4; i++)
                {
                    for (int j = 0; j<4; j++)
                    {
                        if (j == 1)
                            grid[i][j] = '#';
                        else
                            grid[i][j] = ' ';
                    }
                }
            }
            break;
        case PIECE_L:
            if (orientation==0)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (i==0 || j==3 || i==3 || (i==2 && j==1) || (i==2 && j==2))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            if (orientation==1)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (j==0 || j==3 || i==3 || (i==2 && j==1) || (i==1 && j==1))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            if (orientation==2)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (i==0 || i==3 || j==3 || (i==1 && j==1) || (i==1 && j==0))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            if (orientation==3)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (i==0 || j==0 || j==3 || (i==1 && j==2) || (i==2 && j==2))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            break;
        case PIECE_J:
            if (orientation==0)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (i==0 || i==3 || j==0 || (i==2 && j==1) || (i==2 && j==2))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            if (orientation==1)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (i==0 || j==0 || j==3 || (i==1 && j==1) || (i==2 && j==1))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            if (orientation==2)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (i==0 || j==0 || i==3 || (i==1 && j==2) || (i==1 && j==3))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            if (orientation==3)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (i==3 || j==0 || j==3 || (i==1 && j==2) || (i==2 && j==2))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            break;
        case PIECE_T:
            if (orientation==0)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (i==2 || i==3 || j==3 || (i==0 && j==0) || (i==0 && j==2))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            if (orientation==1)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (j==0 || i==3 || j==3 || (i==0 && j==2) || (i==2 && j==2))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            if (orientation==2)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (i==0 || i==3 || j==3 || (i==2 && j==0) || (i==2 && j==2))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            if (orientation==3)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (i==3 || j==2 || j==3 || (i==0 && j==0) || (i==2 && j==0))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            break;
        case PIECE_O:
            for (int i = 0; i<4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i==2 || i==3 || j==3 || j==2)
                        grid[i][j] = ' ';
                    else
                        grid[i][j] = '#';
                }
            }
            break;
        case PIECE_S:
            if (orientation==0 || orientation ==2)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (i==0 || i==3 || j==3 || (i==1 && j==0) || (i==2 && j==2))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            if (orientation==1 || orientation ==3)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (i==3 || j==0 || j==3 || (i==0 && j==2) || (i==2 && j==1))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            break;
        case PIECE_Z:
            if (orientation==0 || orientation ==2)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (i==0 || i==3 || j==3 || (i==2 && j==0) || (i==1 && j==2))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            if (orientation==1 || orientation ==3)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (i==3 || j==0 || j==3 || (i==0 && j==1) || (i==2 && j==2))
                            grid[i][j] = ' ';
                        else
                            grid[i][j] = '#';
                    }
                }
            }
            break;
        case PIECE_VAPOR:
            for (int i = 0; i<4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if ((i==0 && j==1) || (i==0 && j==2))
                        grid[i][j] = '#';
                    else
                        grid[i][j] = ' ';
                }
            }
            break;
        case PIECE_FOAM:
            for (int i = 0; i<4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i==1 && j==1)
                        grid[i][j] = '#';
                    else
                        grid[i][j] = ' ';
                }
            }
            break;
        case PIECE_CRAZY:
            if (orientation==0)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if ((i==0 && j==0) || (i==1 && j==1)|| (i==1 && j==2) || (i==0 && j==3))
                            grid[i][j] = '#';
                        else
                            grid[i][j] = ' ';
                    }
                }
            }
            if (orientation==1)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if ((i==0 && j==3) || (i==1 && j==2)|| (i==2 && j==2) || (i==3 && j==3))
                            grid[i][j] = '#';
                        else
                            grid[i][j] = ' ';
                    }
                }
            }
            if (orientation==2)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if ((i==2 && j==1) || (i==2 && j==2)|| (i==3 && j==0) || (i==3 && j==3))
                            grid[i][j] = '#';
                        else
                            grid[i][j] = ' ';
                    }
                }
            }
            if (orientation==3)
            {
                for (int i = 0; i<4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if ((i==0 && j==0) || (i==1 && j==1)|| (i==2 && j==1) || (i==3 && j==0))
                            grid[i][j] = '#';
                        else
                            grid[i][j] = ' ';
                    }
                }
            }
            break;
        default:
            break;
    }
    
}

char Piece::getChar (int x, int y)
{
    return grid[x][y];
}

void Piece::setOrientNum( int num)
{
    orientation = num;
}

void Piece::setGrid(int x, int y, char val)
{
    grid[x][y] = val;
}

void PieceI::setOrientation(int num)
{
    setOrientNum(num);
    if (num == 0 || num == 2)
    {
        for (int i=0; i<4; i++)
        {
            for (int j = 0; j<4; j++)
            {
                if (i == 1)
                    setGrid(i, j, '#');
                else
                    setGrid(i, j, ' ');
            }
        }
    }
    if (num == 1 || num == 3)
    {
        for (int i=0; i<4; i++)
        {
            for (int j = 0; j<4; j++)
            {
                if (j == 1)
                    setGrid(i, j, '#');
                else
                    setGrid(i, j, ' ');
            }
        }
    }
}

void PieceL::setOrientation(int num)
{
    setOrientNum(num);
    if (num==0)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i==0 || j==3 || i==3 || (i==2 && j==1) || (i==2 && j==2))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
    if (num==1)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (j==0 || j==3 || i==3 || (i==2 && j==1) || (i==1 && j==1))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
    if (num==2)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i==0 || i==3 || j==3 || (i==1 && j==1) || (i==1 && j==0))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
    if (num==3)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i==0 || j==0 || j==3 || (i==1 && j==2) || (i==2 && j==2))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
}

void PieceJ::setOrientation(int num)
{
    setOrientNum(num);
    if (num==0)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i==0 || i==3 || j==0 || (i==2 && j==1) || (i==2 && j==2))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
    if (num==1)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i==0 || j==0 || j==3 || (i==1 && j==1) || (i==2 && j==1))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
    if (num==2)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i==0 || j==0 || i==3 || (i==1 && j==2) || (i==1 && j==3))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
    if (num==3)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i==3 || j==0 || j==3 || (i==1 && j==2) || (i==2 && j==2))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
}

void PieceT::setOrientation(int num)
{
    setOrientNum(num);
    if (num==0)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i==2 || i==3 || j==3 || (i==0 && j==0) || (i==0 && j==2))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
    if (num==1)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (j==0 || i==3 || j==3 || (i==0 && j==2) || (i==2 && j==2))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
    if (num==2)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i==0 || i==3 || j==3 || (i==2 && j==0) || (i==2 && j==2))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
    if (num==3)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i==3 || j==2 || j==3 || (i==0 && j==0) || (i==2 && j==0))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
}

void PieceO::setOrientation(int num)
{
    setOrientNum(num);
    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i==2 || i==3 || j==3 || j==2)
                setGrid(i, j, ' ');
            else
                setGrid(i, j, '#');
        }
    }
}

void PieceS::setOrientation(int num)
{
    setOrientNum(num);
    if (num==0 || num ==2)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i==0 || i==3 || j==3 || (i==1 && j==0) || (i==2 && j==2))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
    if (num==1 || num ==3)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i==3 || j==0 || j==3 || (i==0 && j==2) || (i==2 && j==1))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
}

void PieceZ::setOrientation(int num)
{
    setOrientNum(num);
    if (num==0 || num ==2)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i==0 || i==3 || j==3 || (i==2 && j==0) || (i==1 && j==2))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
    if (num==1 || num ==3)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i==3 || j==0 || j==3 || (i==0 && j==1) || (i==2 && j==2))
                    setGrid(i, j, ' ');
                else
                    setGrid(i, j, '#');
            }
        }
    }
}

void PieceVapor::setOrientation(int num)
{
    setOrientNum(num);
    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if ((i==0 && j==1) || (i==0 && j==2))
                setGrid(i, j, '#');
            else
                setGrid(i, j, ' ');
        }
    }
}

void PieceFoam::setOrientation(int num)
{
    setOrientNum(num);
    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i==1 && j==1)
                setGrid(i, j, '#');
            else
                setGrid(i, j, ' ');
        }
    }
}

void PieceCrazy::setOrientation(int num)
{
    setOrientNum(num);
    if (num==0)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if ((i==0 && j==0) || (i==1 && j==1)|| (i==1 && j==2) || (i==0 && j==3))
                    setGrid(i, j, '#');
                else
                    setGrid(i, j, ' ');
            }
        }
    }
    if (num==1)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if ((i==0 && j==3) || (i==1 && j==2)|| (i==2 && j==2) || (i==3 && j==3))
                    setGrid(i, j, '#');
                else
                    setGrid(i, j, ' ');
            }
        }
    }
    if (num==2)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if ((i==2 && j==1) || (i==2 && j==2)|| (i==3 && j==0) || (i==3 && j==3))
                    setGrid(i, j, '#');
                else
                    setGrid(i, j, ' ');
            }
        }
    }
    if (num==3)
    {
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if ((i==0 && j==0) || (i==1 && j==1)|| (i==2 && j==1) || (i==3 && j==0))
                    setGrid(i, j, '#');
                else
                    setGrid(i, j, ' ');
            }
        }
    }
}

int Piece::getOrient()
{
    return orientation;
}

PieceType Piece::chooseRandomPieceType()
{
    static std::random_device aRandomDevice;
    static std::default_random_engine generator(aRandomDevice());
    std::uniform_int_distribution<> distro(0, NUM_PIECE_TYPES-1);
    return static_cast<PieceType>(distro(generator));
}

