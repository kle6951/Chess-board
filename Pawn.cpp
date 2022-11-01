#include "Pawn.h"
#include "Piece.h"
#include <cstdlib>

Pawn :: Pawn (bool col) : Piece (col)
{
    hasMoved = false;
    return;
}
Pawn :: ~Pawn()
{
}
char Pawn :: getSymbol () const
{
    const char BLACK_PAWN = 'p';
    const char WHITE_PAWN = 'P';
    char symbol;

    if (getColour())
	symbol = WHITE_PAWN;
    else
	symbol = BLACK_PAWN;

    return symbol;
}
bool Pawn  :: canMove (const Board& b,int fromX, int fromY, int toX, int
			toY) const
{
    bool can_move = false;
    int vert_distance = -99, x_diagonal_distance = -99,
	y_diagonal_distance = -99;
    PiecePtr tempPiece;
    if (hasMoved)
    {
        if (isPathClear (b,fromX,fromY,toX,toY)
	    && isForward(fromX,toX) && isVertical (fromX,fromY,toX,toY))
	{
	    vert_distance = vertDistance (fromX,toX);
	    if (vert_distance == 1)
		can_move = true;
	}
	else if (isDiagonal(fromX,fromY,toX,toY)
		 && isPathClear(b,fromX,fromY,toX,toY))
	{
            if (getColour())
	    {
		x_diagonal_distance = fromX - toX;
		y_diagonal_distance = fromY - toY;
		if (x_diagonal_distance == 1 && abs(y_diagonal_distance)==1)
		{
		    if (b.isOccupied (toX,toY))
		    {
			tempPiece = b.getPiece (toX,toY);
                        if (tempPiece -> getColour() != getColour())
			    can_move = true;
		    }
		    else
			can_move = false;
		    cout << can_move << endl;
		}
	    }
	    else
	    {
		x_diagonal_distance = toX - fromX;
		y_diagonal_distance = toY - fromY;

		if (x_diagonal_distance == 1 && abs(y_diagonal_distance)==1)
		{
		    if (b.isOccupied (toX,toY))
		    {
			tempPiece = b.getPiece (toX,toY);
                        if (tempPiece -> getColour() != getColour())
			    can_move = true;
		    }
		}
	    }
	}
    }
    else
    {
	if (isPathClear (b,fromX,fromY,toX,toY)
	    && isForward(fromX,toX) && isVertical (fromX,fromY,toX,toY))
	{
	    vert_distance = vertDistance (fromX,toX);
	    if (vert_distance <= 2)
		can_move = true;
	}
	else if (isDiagonal(fromX,fromY,toX,toY)
		 && isPathClear (b,fromX,fromY,toX,toY))
	{
	    if (getColour())
	    {
		x_diagonal_distance = fromX - toX;
		y_diagonal_distance = fromY - toY;
		if (x_diagonal_distance == 1 && abs(y_diagonal_distance)==1)
		{
		    if (b.isOccupied (toX,toY))
		    {
			tempPiece = b.getPiece (toX,toY);
		        if (tempPiece -> getColour() != getColour())
			    can_move = true;
		    }
		}
	    }
	    else
	    {
		x_diagonal_distance = toX - fromX;
		y_diagonal_distance = toY - fromY;

		if (x_diagonal_distance == 1 && abs(y_diagonal_distance)==1)
		{
		    if (b.isOccupied (toX,toY))
		    {
			tempPiece = b.getPiece (toX,toY);
                        if (tempPiece -> getColour() != getColour())
			    can_move = true;
		    }
		}
	    }
	}
    }
    cout << "canMove " << boolalpha << can_move << endl;	
    return can_move;
}
void Pawn :: notifyMoved ()
{
    hasMoved = true;
}
PiecePtr Pawn :: clone () const
{
    PiecePtr temp = new Pawn (getColour());
    *temp = *this;
    return temp;
}
