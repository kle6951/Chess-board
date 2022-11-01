#ifndef BOARD_H
#define BOARD_H

class Board;
#include "Piece.h"
#include <iostream>
using namespace std;

#define MAXROWS 8
#define MAXCOLS 8

typedef Piece* PiecePtr;

class Board
{
public:
   Board();
   Board (const Board& other);
   ~Board();

// uncomment when testing
   PiecePtr getPiece (int x, int y) const;

   bool move (bool col,int fromX, int fromY, int toX, int toY);
   bool isOccupied (int x, int y) const;
   bool place (const PiecePtr& p, int x, int y);
   bool remove (int x, int y);
 
   void write (ostream& out) const;

   Board& operator= (const Board& other);

private:
   PiecePtr grid[MAXROWS][MAXCOLS];

   void initBoard();
   void clearBoard();
   void copyBoard(const Board& other);
    //  bool canMove (int fromX, int fromY, int toX, int toY) const;
};

ostream& operator<< (ostream& out, const Board& b);

#endif
