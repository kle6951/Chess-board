#include "Board.h"
#include "Piece.h"
#include <fstream>
Board :: Board()
{
    initBoard();
    return;
}
Board :: Board (const Board &other)
{
    initBoard();
    copyBoard(other);
    return;
}
Board :: ~Board ()
{
    int counter, counter_02;
    ofstream outfile;

    outfile.open ("final_board.txt");

    for (counter = 0; counter < MAXROWS; counter++)
    {
	for (counter_02 = 0; counter_02 < MAXCOLS; counter_02++)
	{
	    if (grid[counter][counter_02] != NULL)
	    {
		outfile << grid[counter][counter_02] -> getSymbol() << ' '
			<< counter_02
			<< ' '<< counter << endl;
	    }
	}
    }
    outfile.close ();
    clearBoard();
    return;
}
bool Board :: move (bool col,int fromX,int fromY, int toX, int toY)
{
    bool can_move = false;
    PiecePtr temp;
    if (isOccupied (fromX,fromY))
    {
	if ( grid[fromY][fromX] -> canMove (*this,fromX,fromY,toX,toY))
	{
	    if (col == grid[fromY][fromX] -> getColour())
	    {
		if (isOccupied (toX,toY))
		{
		    temp = getPiece (toX,toY);
		    if (col != temp -> getColour ())
		    {
		 	grid[toY][toX] = grid[fromY][fromX];
        	        grid[fromY][fromX] = NULL;
                 
			can_move = true;
		      	
		        grid[toY][toX] -> notifyMoved();
		    }
		}
	    
		else
		{
		    grid[toY][toX] = grid[fromY][fromX];
		    grid[fromY][fromX] = NULL;
		    can_move = true;
		    grid[toY][toX] -> notifyMoved();
		}
	    }
	}
    }
    
    return can_move;
}
bool Board :: place (const PiecePtr& p, int x, int y)
{
    bool can_place = false;

    if (grid[y][x] == NULL)
    {
	can_place = true;
	grid[y][x] = p;
    }
    return can_place;
}
bool Board :: remove (int x, int y)
{
    bool can_remove = false;

    if (grid[y][x] != NULL)
    {
	can_remove = true;
	delete grid[y][x];
	grid[y][x] = NULL;
    }
    return can_remove;
}
Board& Board :: operator = (const Board& other)
{
    int counter, counter_01;
    
    if (this != &other)
    {
	for (counter = 0; counter < MAXROWS; counter++)
	{
	    for (counter_01 = 0; counter_01 < MAXCOLS; counter_01++)
	    {
		if (grid[counter][counter_01] != NULL)
		{
		    delete grid[counter][counter_01];
		    grid[counter][counter_01] = NULL;
		}
	    }
	}
	copyBoard (other);
    }
    return (*this);
}
void Board :: write (ostream& out) const
{
    int counter_01,
	counter_02,
	counter_03,
	counter_04,
	counter_05;
    
    out << "      ";
    for (counter_01 = 0; counter_01 < MAXROWS; counter_01++)
	out << counter_01 << "   ";
    out << endl;
    for (counter_02 = 0; counter_02 < MAXCOLS; counter_02++)
    {
	out << "    ";
	for (counter_03 = 0; counter_03 < MAXROWS; counter_03++)
	    out << "+---";
	out << '+' << endl;
	out << counter_02 << "   ";
	for (counter_04 = 0;counter_04 < MAXCOLS; counter_04++)
	{
	    if (grid[counter_04][counter_02] != NULL)
	    {
		out << '|' << ' '
		    << grid[counter_04][counter_02] -> getSymbol ()<< ' ';
	    }
	    else
		out << '|' <<"   ";
	    
	}
	out << '|' << endl;
    }
    out << "    ";
    for (counter_05 = 0; counter_05 < MAXROWS; counter_05++)
    {
	out << "+---";
    }
    out << "+" << endl;
    return;
}
void Board :: initBoard ()
{
    int counter,counter_02;
    for (counter = 0; counter < MAXROWS ; counter++)
    {
	for (counter_02 = 0; counter_02 < MAXCOLS; counter_02++)
	    grid[counter][counter_02] = NULL;
    }
    return;
}
void Board :: clearBoard ()
{
    int counter,counter_02;
    for (counter = 0;counter < MAXROWS; counter++)
    {
	for (counter_02 = 0; counter_02 < MAXCOLS; counter_02++)
	{
	    if (grid[counter][counter_02] != NULL)
	    {
		delete grid[counter][counter_02];
		grid[counter][counter_02] = NULL;
	    }
	}
    }
    return;
}
/* bool Board :: canMove (int fromX, int fromY, int toX, int toY) const
{
    bool can_move = true;

    if (grid[fromY][fromX] == NULL)
	can_move = false;
    if (grid[toY][toX] != NULL)
	can_move = false;
    return can_move;
}
*/
void Board :: copyBoard (const Board& other)
{
    PiecePtr tempGrid [MAXROWS][MAXCOLS];
    int row, col;
    for ( row = 0; row < MAXROWS; row++)
    {
	for (col = 0;col <MAXCOLS; col++)
	{
	    if (other.grid[row][col] != NULL)
	    {
		tempGrid[row][col] = other.grid[row][col] -> clone();
		grid[row][col]=tempGrid [row][col];
	    }
	}
    }
    return;
}
ostream& operator << (ostream&out, const Board& b)
{
    b.write(out);
    return out;
}
// uncomenting when testing
PiecePtr Board :: getPiece (int x, int y) const
{
    PiecePtr temp = NULL;
    if (grid[y][x] != NULL)
    {
	temp = grid [y][x]-> clone();
    }
    return temp;
}
bool Board :: isOccupied (int x, int y) const
{
    bool is_occupied = false;
   
    if (grid[y][x] != NULL)
	is_occupied = true;

    return is_occupied;
}
