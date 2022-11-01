#include "King.h"
#include "Board.h"
#include "Piece.h"
#include <gtest/gtest.h>

class test_king : public testing :: Test
{
protected:
    virtual void SetUp ()
    {
    }
    virtual void TearDown ()
    {
    }
};
TEST_F (test_king, constructor_testing)
{
    PiecePtr w_piece = new King (WHITE);
    bool same_col = false;

    if (w_piece -> getColour () == WHITE)
	same_col = true;
    ASSERT_EQ (same_col,true);
}
TEST_F (test_king, getSymbol_white_king)
{
    PiecePtr w_piece = new King (WHITE);
    char symbol;

    symbol = w_piece -> getSymbol ();
    ASSERT_EQ (symbol, 'K');
}
TEST_F (test_king, getSymbol_black_king)
{
    PiecePtr b_piece = new King (BLACK);
    char symbol;
    symbol = b_piece -> getSymbol ();
    ASSERT_EQ (symbol,'k');
}
TEST_F (test_king, canMove_Black_move_vertically_1_step)
{
    PiecePtr b_piece = new King (BLACK), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,0,0);
    can_move = b_piece -> canMove (board,0,0,1,0);
    if (can_move)
	board.move (BLACK,0,0,1,0);
    tempPiece = board.getPiece (1,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
    
}
TEST_F (test_king, canMove_Black_cannot_move_vertically_multiple_steps)
{
    PiecePtr b_piece = new King (BLACK), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,0,0);
    can_move = b_piece -> canMove (board,0,0,2,0);
    if (can_move)
	board.move (BLACK,0,0,2,0);
    tempPiece = board.getPiece (2,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
}
TEST_F (test_king, canMove_Black_move_horizontally_1_step)
{
    PiecePtr b_piece = new King (BLACK), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,1,0);
    can_move = b_piece -> canMove (board,1,0,1,1);
    if (can_move)
	board.move (BLACK,1,0,1,1);
    tempPiece = board.getPiece (1,1);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
    
}
TEST_F (test_king, canMove_Black_move_horizontally_multiple_steps)
{
    PiecePtr b_piece = new King (BLACK), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,1,0);
    can_move = b_piece -> canMove (board,1,0,1,2);
    if (can_move)
	board.move (BLACK,1,0,1,2);
    tempPiece = board.getPiece (1,2);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    
}
TEST_F (test_king, canMove_Black_move_backward_1_step)
{
    PiecePtr b_piece = new King (BLACK), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,1,0);
    can_move = b_piece -> canMove (board,1,0,0,0);
    if (can_move)
	board.move (BLACK,1,0,0,0);
    tempPiece = board.getPiece (0,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
}
TEST_F (test_king, canMove_Black_move_backward_multiple_steps)
{
    PiecePtr b_piece = new King (BLACK), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,2,0);
    can_move = b_piece -> canMove (board,2,0,0,0);
    if (can_move)
	board.move (BLACK,2,0,0,0);
    tempPiece = board.getPiece (0,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    
}
TEST_F (test_king, canMove_Black_move_diagonally_1_step)
{
    PiecePtr b_piece = new King (BLACK), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,3,2);
    can_move = b_piece -> canMove (board,3,2,4,1);
    if (can_move)
	board.move (BLACK,3,2,4,1);
    tempPiece = board.getPiece (4,1);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
    
}
TEST_F (test_king, canMove_Black_cannotmove_diagonally_1_step)
{
    PiecePtr b_piece = new King (BLACK), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,3,2);
    can_move = b_piece -> canMove (board,3,2,5,0);
    if (can_move)
	board.move (BLACK,3,2,5,0);
    tempPiece = board.getPiece (5,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    
}
TEST_F (test_king, canMove_White_move_vertically_1_step)
{
    PiecePtr b_piece = new King (WHITE), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,7,0);
    can_move = b_piece -> canMove (board,7,0,6,0);
    if (can_move)
	board.move (WHITE,7,0,6,0);
    tempPiece = board.getPiece (6,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
    
}
TEST_F (test_king, canMove_White_cannot_move_vertically_multiple_steps)
{
    PiecePtr b_piece = new King (WHITE), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,7,0);
    can_move = b_piece -> canMove (board,7,0,5,0);
    if (can_move)
	board.move (WHITE,7,0,5,0);
    tempPiece = board.getPiece (5,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
}
TEST_F (test_king, canMove_White_move_horizontally_1_step)
{
    PiecePtr b_piece = new King (WHITE), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,5,1);
    can_move = b_piece -> canMove (board,5,1,5,2);
    if (can_move)
	board.move (WHITE,5,1,5,2);
    tempPiece = board.getPiece (5,2);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
    
}
TEST_F (test_king, canMove_White_move_horizontally_multiple_steps)
{
    PiecePtr b_piece = new King (WHITE), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,5,1);
    can_move = b_piece -> canMove (board,5,1,5,4);
    if (can_move)
	board.move (WHITE,5,1,5,4);
    tempPiece = board.getPiece (5,4);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    
}
TEST_F (test_king, canMove_White_move_backward_1_step)
{
    PiecePtr b_piece = new King (WHITE), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,5,0);
    can_move = b_piece -> canMove (board,5,0,4,0);
    if (can_move)
	board.move (WHITE,5,0,4,0);
    tempPiece = board.getPiece (4,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
}
TEST_F (test_king, canMove_White_move_backward_multiple_steps)
{
    PiecePtr b_piece = new King (WHITE), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,5,0);
    can_move = b_piece -> canMove (board,5,0,1,0);
    if (can_move)
	board.move (WHITE,5,0,1,0);
    tempPiece = board.getPiece (1,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    
}
TEST_F (test_king, canMove_White_move_diagonally_1_step)
{
    PiecePtr b_piece = new King (WHITE), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,3,2);
    can_move = b_piece -> canMove (board,3,2,2,1);
    if (can_move)
	board.move (WHITE,3,2,2,1);
    tempPiece = board.getPiece (2,1);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
    
}
TEST_F (test_king, canMove_White_move_diagonally_multiple_steps)
{
    PiecePtr b_piece = new King (WHITE), tempPiece;
    Board board;
    bool can_move = false, found = false;
    board.place (b_piece,3,2);
    can_move = b_piece -> canMove (board,3,2,1,0);
    if (can_move)
	board.move (WHITE,3,2,1,0);
    tempPiece = board.getPiece (1,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    
}


