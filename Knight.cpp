#include "Knight.h"
#include "Piece.h"
#include <cstdlib>

Knight :: Knight (bool col) : Piece (col)
{
    return;
}

Knight :: ~Knight ()
{
}
char Knight :: getSymbol () const
{
    const char BLACK_KNIGHT = 'n';
    const char WHITE_KNIGHT = 'N';
    char symbol;

    if (getColour())
	symbol = WHITE_KNIGHT;
    else
	symbol = BLACK_KNIGHT;

    return symbol;
}
bool Knight  :: canMove (const Board& b,int fromX, int fromY, int toX, int
			toY) const
{
    bool can_move = false;
    PiecePtr temp;

    if (abs(toX - fromX) == 1 && abs (toY-fromY) == 2)
    {
	if (b.isOccupied (toX,toY))
	{
	    temp = b.getPiece (toX,toY);
	    if (getColour() != temp -> getColour ())
		can_move = true;
	}
	else
	    can_move = true;
    }
    else if (abs (toX - fromX) == 2 && abs(toY - fromY) == 1)
    {
	if (b.isOccupied (toX,toY))
	{
	    temp = b.getPiece (toX,toY);
	    if (getColour () != temp -> getColour ())
	    {
		can_move = true;
	    }
	}
	else
	    can_move = true;
    }
    return can_move;
}
PiecePtr Knight :: clone () const
{
    PiecePtr temp = new Knight (getColour());
    *temp = *this;
    return temp;
}
void Knight :: notifyMoved()
{
}
