#include "Bishop.h"
#include "Piece.h"
#include <cstdlib>

Bishop :: Bishop (bool col) : Piece (col)
{
    return;
}
Bishop :: ~Bishop ()
{
}
char Bishop :: getSymbol () const
{
    const char BLACK_BISHOP = 'b';
    const char WHITE_BISHOP = 'B';
    char symbol;

    if (getColour())
	symbol = WHITE_BISHOP;
    else
	symbol = BLACK_BISHOP;

    return symbol;
}
bool Bishop  :: canMove (const Board& b,int fromX, int fromY, int toX, int
			toY) const
{
    bool can_move = false;

    if (isDiagonal (fromX,fromY,toX,toY))
    {
	if (isPathClear (b,fromX,fromY,toX,toY))
	    can_move = true;
    }
    return can_move;
}
PiecePtr Bishop :: clone () const
{
    PiecePtr temp = new Bishop (getColour());
    *temp = *this;
    return temp;
}
void Bishop :: notifyMoved()
{
}
