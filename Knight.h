#ifndef KNIGHT_H
#define KNIGHT_H


class Knight;
#include "Piece.h"
#include "Board.h"
#include <iostream>
#include <cmath>
using namespace std;

class Knight : public Piece
{
public:
    Knight (bool col);
    ~Knight ();
    PiecePtr clone () const;
    char getSymbol() const;
    bool canMove(const Board& b, int fromX, int fromY, int toX
		 , int toY) const;
    void notifyMoved();
};


#endif
