#ifndef KING_H
#define KING_H


class King;
#include "Pawn.h"
#include "Piece.h"
#include "Board.h"
#include <iostream>
#include <cmath>
using namespace std;

class King : public Piece
{
public:
    King (bool col);
    PiecePtr clone () const;
    ~King ();
  
    char getSymbol() const;
    bool canMove(const Board& b, int fromX, int fromY, int toX
		 , int toY) const;
    void notifyMoved();
};


#endif
