#include "King.h"
#include "Piece.h"
#include "Board.h"
#include <cstdlib>

King :: King (bool col) : Piece (col)
{
    return;
}
King :: ~King ()
{
}
char King :: getSymbol () const
{
    const char BLACK_KING = 'k';
    const char WHITE_KING = 'K';
    char symbol;

    if (getColour())
	symbol = WHITE_KING;
    else
	symbol = BLACK_KING;

    return symbol;
}
bool King  :: canMove (const Board& b,int fromX, int fromY, int toX, int
			toY) const
{
    int x_distance, y_distance, vert_disc;
    bool can_move = false;
    if (isVertical (fromX,fromY,toX,toY))
    {
	if (isPathClear (b,fromX,fromY,toX,toY))
	{
	    vert_disc = vertDistance (fromX,toX);
	    if (abs (vert_disc) == 1)
		can_move = true;
	}
    }
    else if (isDiagonal (fromX,fromY,toX,toY))
    {

	if (isPathClear (b,fromX,fromY,toX,toY))
	{
	    x_distance = toX - fromX;

	    y_distance = toY - fromY;
	    if (abs(x_distance) == 1 && abs(y_distance) == 1)
		can_move = true;
	}
    }
    else if (isHorizontal (fromX,fromY,toX,toY))
    {
	if (isPathClear (b,fromX,fromY,toX,toY))
	{
	    if (horizDistance (fromY,toY) == 1)
		can_move = true;
	}
    }
    return can_move;
}
PiecePtr King :: clone() const
{
    PiecePtr temp = new King (getColour());
    *temp = *this;
    return temp;
}
void King :: notifyMoved()
{
}
