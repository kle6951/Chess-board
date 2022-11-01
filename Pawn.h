#ifndef PAWN_H
#define PAWN_H


class Pawn;
#include "Piece.h"
#include "Board.h"
#include <iostream>
#include <cmath>
using namespace std;

class Pawn : public Piece
{
public:
    Pawn (bool col);
    ~Pawn ();
    PiecePtr clone () const;  
    char getSymbol() const;
    bool canMove(const Board& b, int fromX, int fromY, int toX
		 , int toY) const;
    void notifyMoved();
private:
    bool hasMoved;
};


#endif
