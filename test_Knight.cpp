#include "Knight.h"
#include "Piece.h"
#include "Board.h"
#include <gtest/gtest.h>

class test_knight : public testing :: Test
{
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};
TEST_F(test_knight, constructor_testing)
{
    PiecePtr piece = new Knight(WHITE);
    bool same_col = false;
    if (WHITE == piece -> getColour())
	same_col=true;
    ASSERT_EQ (same_col,true);
}
TEST_F(test_knight, getSymbol_white_piece)
{
    PiecePtr piece = new Knight (WHITE);
    char symbol;

    symbol = piece -> getSymbol ();
    ASSERT_EQ(symbol,'N');
}
TEST_F(test_knight, getSymbol_Black_piece)
{
    PiecePtr piece = new Knight (BLACK);
    char symbol;

    symbol = piece -> getSymbol();
    ASSERT_EQ(symbol,'n');
}
TEST_F (test_knight, canMove_white_cannot_move_vertically)
{
    PiecePtr piece = new Knight(WHITE), tempPiece;
    bool found = false, can_move = false;
    Board board;

    board.place (piece,7,0);
    can_move = piece -> canMove (board,7,0,5,0);
    if (can_move)
	board.move (WHITE,7,0,5,0);
    tempPiece = board.getPiece (5,0);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ(can_move,false);
    ASSERT_EQ(found,false);
}
TEST_F (test_knight, canMove_white_cannot_move_horizontally)
{
    PiecePtr piece = new Knight(WHITE), tempPiece;
    bool found = false, can_move = false;
    Board board;

    board.place (piece,7,0);
    can_move = piece -> canMove (board,7,0,7,2);
    if (can_move)
	board.move (WHITE,7,0,7,2);
    tempPiece = board.getPiece (7,2);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ(can_move,false);
    ASSERT_EQ(found,false);
}
TEST_F (test_knight, canMove_white_cannot_move_diagonally)
{
    PiecePtr piece = new Knight(WHITE), tempPiece;
    bool found = false, can_move = false;
    Board board;

    board.place (piece,7,0);
    can_move = piece -> canMove (board,7,0,5,2);
    if (can_move)
	board.move (WHITE,7,0,5,2);
    tempPiece = board.getPiece (5,2);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ(can_move,false);
    ASSERT_EQ(found,false);
}
TEST_F (test_knight, canMove_white_legal_move_2_vert_1horiz)
{
    PiecePtr piece = new Knight(WHITE), tempPiece;
    bool found = false, can_move = false;
    Board board;
    board.place (piece,3,0);
    piece = new Knight (WHITE);

    board.place (piece,1,0);
    can_move = piece -> canMove (board,1,0,3,1);
    if (can_move)
	board.move (WHITE,1,0,3,1);
    tempPiece = board.getPiece (3,1);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ(can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_knight, canMove_white_legal_move_1_vert_2horiz)
{
    PiecePtr piece = new Knight(WHITE), tempPiece;
    bool found = false, can_move = false;
    Board board;
    board.place (piece,1,2);
    piece = new Knight (WHITE);

    board.place (piece,1,0);
    can_move = piece -> canMove (board,1,0,2,2);
    if (can_move)
	board.move (WHITE,1,0,2,2);
    tempPiece = board.getPiece (2,2);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ(can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_knight
	, canMove_white_legal_move_1_vert_2horiz_remove_opponent)
{
    PiecePtr piece = new Knight(BLACK), tempPiece;
    bool found = false, can_move = false;
    Board board;
    board.place (piece,2,2);
    piece = new Knight (WHITE);

    board.place (piece,1,0);
    can_move = piece -> canMove (board,1,0,2,2);
    if (can_move)
	board.move (WHITE,1,0,2,2);
    tempPiece = board.getPiece (2,2);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ(can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_knight
	, canMove_white_legal_move_2_vert_1horiz_remove_opponetn)
{
    PiecePtr piece = new Knight(BLACK), tempPiece;
    bool found = false, can_move = false;
    Board board;
    board.place (piece,3,1);
    piece = new Knight (WHITE);

    board.place (piece,1,0);
    can_move = piece -> canMove (board,1,0,3,1);
    if (can_move)
	board.move (WHITE,1,0,3,1);
    tempPiece = board.getPiece (3,1);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ(can_move,true);
    ASSERT_EQ(found,true);
}
