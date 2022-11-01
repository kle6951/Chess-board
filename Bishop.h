#ifndef BISHOP_H
#define BISHOP_H


class Bishop;
#include "Piece.h"
#include "Board.h"
#include <iostream>
#include <cmath>
using namespace std;

class Bishop : public Piece
{
public:
    Bishop (bool col);
    ~Bishop();
    PiecePtr clone () const;
    char getSymbol() const;
    bool canMove(const Board& b, int fromX, int fromY, int toX
		 , int toY) const;
    void notifyMoved();
};


#endif
