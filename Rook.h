#ifndef ROOK_H
#define ROOK_H


class Rook;
#include "Piece.h"
#include "Board.h"
#include <iostream>
#include <cmath>
using namespace std;

class Rook : public Piece
{
public:
    Rook (bool col);
    ~Rook ();
    PiecePtr clone () const;
    char getSymbol() const;
    bool canMove(const Board& b, int fromX, int fromY, int toX
		 , int toY) const;
    void notifyMoved();
};


#endif
