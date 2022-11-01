#include "Queen.h"
#include "Piece.h"
#include <cstdlib>

Queen :: Queen (bool col) : Piece (col)
{
    return;
}
Queen :: ~Queen ()
{
}
char Queen :: getSymbol () const
{
    const char BLACK_QUEEN = 'q';
    const char WHITE_QUEEN = 'Q';
    char symbol;

    if (getColour())
	symbol = WHITE_QUEEN;
    else
	symbol = BLACK_QUEEN;

    return symbol;
}
bool Queen  :: canMove (const Board& b,int fromX, int fromY, int toX, int
			toY) const
{
    bool can_move = false;

    if (isPathClear (b,fromX,fromY,toX,toY))
	can_move = true;
    return can_move;
}
PiecePtr Queen :: clone () const
{
    PiecePtr temp = new Queen (getColour());
    *temp = *this;
    return temp;
}
void Queen :: notifyMoved()
{
}
