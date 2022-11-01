#include "Piece.h"
#include <cstdlib>

Piece :: ~Piece ()
{
    return;
}
Piece :: Piece (bool col)
{
    colour = col;
    return;
}
void Piece :: notifyMoved ()
{
    return;
}
bool Piece :: getColour () const
{
    return colour;
}
bool Piece :: isVertical (int fromX, int fromY, int toX, int toY) const
{
    bool is_vertical = false;

    if ((fromY == toY) && (fromX != toX))
	is_vertical = true;

    return is_vertical;
}
bool Piece :: isHorizontal (int fromX, int fromY, int toX, int toY) const
{
    bool is_horizontal = false;

    if ((fromX == toX) && (fromY != toY))
	is_horizontal = true;

    return is_horizontal;
}
bool Piece  :: isDiagonal (int fromX, int fromY, int toX, int toY) const
{
    bool is_diagonal = false;

    if ((toX - fromX != 0) && (toY - fromY != 0))
	is_diagonal = true;

    return is_diagonal;
}
bool Piece  :: isForward (int fromX, int toX) const
{
    bool is_forward = false;

    if (colour)
    {
	if (toX - fromX <= 0)
	    is_forward = true;
    }
    else
    {
	if (toX - fromX >= 0)
	    is_forward = true;
    }

    return is_forward;
}
int Piece :: vertDistance (int fromX, int toX) const
{
    int vert_distance = -1;;

  
    if (colour)
	vert_distance = fromX - toX;
    else
	vert_distance = toX - fromX;

    return vert_distance;
}
int Piece  :: horizDistance (int fromY, int toY) const
{
    int horiz_distance = -1;

    if (toY > fromY)
	horiz_distance = toY - fromY;
    else
	horiz_distance = fromY - toY;

    return horiz_distance;
}
bool Piece :: isPathClear (const Board& b, int fromX, int fromY, int toX
			   , int toY) const
{
    bool is_path_clear = true;
    int x_coor,y_coor;

    if (isVertical (fromX,fromY,toX,toY))
    {
	if (fromX > toX)
	{
	    for (x_coor = fromX - 1; x_coor > toX; x_coor--)
	    {
		if (b.isOccupied (x_coor,fromY))
		    is_path_clear = false;
	    }
	}
	else if (fromX < toX)
	{
	    for (x_coor = fromX + 1; x_coor < toX; x_coor++)
	    {
		if (b.isOccupied (x_coor,fromY))
		    is_path_clear = false;
	    }
	}
    }
    else if (isHorizontal (fromX,fromY,toX,toY))
    {
	if (fromY > toY)
	{
	    for (y_coor = fromY - 1;y_coor > toY;y_coor--)
	    {
		if (b.isOccupied (fromX,y_coor))
		    is_path_clear = false;
	    }
	}
	else if (fromY < toY)
	{
	    for (y_coor = fromY + 1; y_coor < toY; y_coor++)
	    {
		if (b.isOccupied (fromX,y_coor))
		    is_path_clear = false;
	    }
	}
    }
    else if (isDiagonal (fromX,fromY,toX,toY))
    {
	if (fromY > toY && fromX < toX)
	{
	    for (x_coor = fromX + 1, y_coor = fromY - 1; x_coor != toX 
		  && y_coor != toY; x_coor++,y_coor--)
	    {
		if (b.isOccupied (x_coor,y_coor))
		    is_path_clear = false;
	    }
	}
	else if (fromY < toY && fromX > toX)
	{
	    for (x_coor = fromX -1, y_coor = fromY + 1; x_coor != toX
		     && y_coor != toY; x_coor--, y_coor++)
	    {
		if (b.isOccupied (x_coor,y_coor))
		    is_path_clear = false;
	    }	     
	}
	else if (fromY > toY && fromX > toX)
	{
	    for (x_coor = fromX -1,y_coor  = fromY -1; x_coor != toX
		    && y_coor != toY; x_coor--, y_coor--)
	    {
		if (b.isOccupied (x_coor,y_coor))
		    is_path_clear = false;
	    }
	}
	else if (fromY < toY && fromX < toX)
	{
	    for (x_coor = fromX+1, y_coor = fromY + 1; x_coor != toX
		    && y_coor != toY; x_coor++,y_coor++)
	    {
		if (b.isOccupied (x_coor,y_coor))
		    is_path_clear = false;
	    }
	}
    }
    return is_path_clear;
}
