#ifndef PIECE_H
#define PIECE_H


class Piece;
#include "Board.h"
#include <iostream>
#include <cmath>
using namespace std;

typedef Piece* PiecePtr;
#define WHITE true
#define BLACK false

class Piece
{
public:
  Piece (bool col);
  virtual ~Piece ();
  virtual PiecePtr clone () const = 0;
  
  virtual char getSymbol() const = 0;
  bool getColour() const;

  virtual bool canMove(const Board& b, int fromX, int fromY, int toX
		       , int toY) const= 0;
  virtual void notifyMoved();
private:
  bool colour;
protected:
  bool isVertical (int fromX, int fromY, int toX, int toY) const;
  bool isHorizontal (int fromX, int fromY, int toX, int toY) const;
  bool isDiagonal (int fromX, int fromY, int toX, int toY) const;
  bool isForward (int fromX, int toX) const;
  int vertDistance (int fromX, int toX) const;
  int horizDistance (int fromY, int toY) const;
  bool isPathClear (const Board& b, int fromX, int fromY, int toX
		    , int toY)const;
};


#endif
