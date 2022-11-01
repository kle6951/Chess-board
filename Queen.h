#ifndef QUEEN_H
#define QUEEN_H


class Queen;
#include "Piece.h"
#include "Board.h"
#include <iostream>
#include <cmath>
using namespace std;

class Queen : public Piece
{
public:
    Queen (bool col);
    ~Queen ();
    PiecePtr clone () const;
    char getSymbol() const;
    bool canMove(const Board& b, int fromX, int fromY, int toX
		 , int toY) const;
    void notifyMoved();
};


#endif
