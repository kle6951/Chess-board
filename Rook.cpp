#include "Rook.h"
#include "Piece.h"
#include <cstdlib>

Rook :: Rook (bool col) : Piece (col)
{
    return;
}
Rook :: ~Rook ()
{
}
char Rook :: getSymbol () const
{
    const char BLACK_ROOK = 'r';
    const char WHITE_ROOK = 'R';
    char symbol;

    if (getColour())
	symbol = WHITE_ROOK;
    else
	symbol = BLACK_ROOK;

    return symbol;
}
bool Rook  :: canMove (const Board& b,int fromX, int fromY, int toX, int
			toY) const
{
    bool can_move = false;

    if (isHorizontal (fromX,fromY,toX,toY)||isVertical (fromX,fromY,toX,toY))
    {
	if (isPathClear (b,fromX,fromY,toX,toY))
	    can_move = true;
    }
    return can_move;
}
PiecePtr Rook :: clone () const
{
    PiecePtr temp = new Rook (getColour());
    *temp = *this;
    return temp;
}
void Rook :: notifyMoved ()
{
}
