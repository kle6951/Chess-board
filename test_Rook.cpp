#include "Piece.h"
#include "Board.h"
#include "Rook.h"
#include <gtest/gtest.h>

class test_rook : public testing :: Test
{
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};
TEST_F (test_rook, constructor_testing)
{
    PiecePtr w_piece = new Rook (WHITE);
    bool same_col = false;

    if (WHITE == w_piece -> getColour())
	same_col = true;
    ASSERT_EQ(same_col,true);
}
TEST_F (test_rook, getSymbol_white_piece)
{
    PiecePtr w_piece = new Rook (WHITE);
    char symbol;

    symbol = w_piece -> getSymbol();
    ASSERT_EQ(symbol,'R');
}
TEST_F (test_rook, getSymbol_black_piece)
{
    PiecePtr b_piece = new Rook (BLACK);
    char symbol;

    symbol = b_piece -> getSymbol();
    ASSERT_EQ(symbol,'r');
}
TEST_F (test_rook, canMove_black_move_horizontally_multiple_steps)
{
    PiecePtr b_piece = new Rook (BLACK), tempPiece;
    bool can_move = false, found = false;
    Board board;

    board.place (b_piece,0,0);
    can_move = b_piece -> canMove (board,0,0,0,5);
    if (can_move)
	board.move (BLACK,0,0,0,5);
    tempPiece = board.getPiece (0,5);
    if (tempPiece!= NULL)
	found = true;
    ASSERT_EQ (can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_rook, canMove_black_move_horizontally_1_step)
{
    PiecePtr b_piece = new Rook (BLACK), tempPiece;
    bool can_move = false, found = false;
    Board board;

    board.place (b_piece,0,0);
    can_move = b_piece -> canMove (board,0,0,0,1);
    if (can_move)
	board.move (BLACK,0,0,0,1);
    tempPiece = board.getPiece (0,1);
    if (tempPiece!= NULL)
	found = true;
    ASSERT_EQ (can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_rook, canMove_black_move_vertically_multiple_steps)
{
    PiecePtr b_piece = new Rook (BLACK), tempPiece;
    bool can_move = false, found = false;
    Board board;

    board.place (b_piece,0,0);
    can_move = b_piece -> canMove (board,0,0,3,0);
    if (can_move)
	board.move (BLACK,0,0,3,0);
    tempPiece = board.getPiece (3,0);
    if (tempPiece!= NULL)
	found = true;
    ASSERT_EQ (can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_rook, canMove_black_move_vertically_1_step)
{
    PiecePtr b_piece = new Rook (BLACK), tempPiece;
    bool can_move = false, found = false;
    Board board;

    board.place (b_piece,0,0);
    can_move = b_piece -> canMove (board,0,0,1,0);
    if (can_move)
	board.move (BLACK,0,0,1,0);
    tempPiece = board.getPiece (1,0);
    if (tempPiece!= NULL)
	found = true;
    ASSERT_EQ (can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_rook, canMove_white_move_horizontally_multiple_steps)
{
    PiecePtr w_piece = new Rook (WHITE), tempPiece;
    bool can_move = false, found = false;
    Board board;

    board.place (w_piece,0,0);
    can_move = w_piece -> canMove (board,0,0,0,5);
    if (can_move)
	board.move (WHITE,0,0,0,5);
    tempPiece = board.getPiece (0,5);
    if (tempPiece!= NULL)
	found = true;
    ASSERT_EQ (can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_rook, canMove_white_move_horizontally_1_step)
{
    PiecePtr w_piece = new Rook (WHITE), tempPiece;
    bool can_move = false, found = false;
    Board board;

    board.place (w_piece,0,0);
    can_move = w_piece -> canMove (board,0,0,0,1);
    if (can_move)
	board.move (WHITE,0,0,0,1);
    tempPiece = board.getPiece (0,1);
    if (tempPiece!= NULL)
	found = true;
    ASSERT_EQ (can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_rook, canMove_White_move_vertically_multiple_steps)
{
    PiecePtr w_piece = new Rook (WHITE), tempPiece;
    bool can_move = false, found = false;
    Board board;

    board.place (w_piece,0,0);
    can_move = w_piece -> canMove (board,0,0,3,0);
    if (can_move)
	board.move (WHITE,0,0,3,0);
    tempPiece = board.getPiece (3,0);
    if (tempPiece!= NULL)
	found = true;
    ASSERT_EQ (can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_rook, canMove_white_move_vertically_1_step)
{
    PiecePtr w_piece = new Rook (WHITE), tempPiece;
    bool can_move = false, found = false;
    Board board;

    board.place (w_piece,0,0);
    can_move = w_piece -> canMove (board,0,0,1,0);
    if (can_move)
	board.move (WHITE,0,0,1,0);
    tempPiece = board.getPiece (1,0);
    if (tempPiece!= NULL)
	found = true;
    ASSERT_EQ (can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_rook, canMove_cannot_move_occupied_horizontal_path)
{
    PiecePtr w_piece = new Rook (WHITE), tempPiece;
    bool can_move = false, found = false;
    Board board;

    board.place (w_piece,0,1);
    w_piece = new Rook (WHITE);
    board.place (w_piece,0,3);
    can_move = w_piece -> canMove (board,0,3,0,0);
    if (can_move)
	board.move (WHITE,0,3,0,0);
    tempPiece = board.getPiece (0,0);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ(can_move,false);
    ASSERT_EQ(found,false);
}
TEST_F (test_rook, canMove_cannot_move_occupied_vertical_path)
{
    PiecePtr w_piece = new Rook (WHITE), tempPiece;
    bool can_move = false, found = false;
    Board board;

    board.place (w_piece,1,0);
    w_piece = new Rook (WHITE);
    board.place (w_piece,3,0);
    can_move = w_piece -> canMove (board,3,0,0,0);
    if (can_move)
	board.move (WHITE,3,0,0,0);
    tempPiece = board.getPiece (0,0);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ(can_move,false);
    ASSERT_EQ(found,false);
}
TEST_F (test_rook, canMove_move_the_opponent_vertically)
{
    PiecePtr w_piece = new Rook (WHITE), tempPiece;
    bool move_succ = false;
    bool can_move = false, found = false;
    Board board;

    board.place (w_piece,1,0);
    w_piece = new Rook (BLACK);
    board.place (w_piece,3,0);
    can_move = w_piece -> canMove (board,3,0,1,0);
    if (can_move)
	move_succ = board.move (BLACK,3,0,1,0);
    tempPiece = board.getPiece (1,0);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ(can_move,true);
    ASSERT_EQ(move_succ,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_rook, canMove_move_the_opponent_horizontally)
{
    PiecePtr w_piece = new Rook (WHITE), tempPiece;
    bool move_succ = false;
    bool can_move = false, found = false;
    Board board;

    board.place (w_piece,0,0);
    w_piece = new Rook (BLACK);
    board.place (w_piece,0,3);
    can_move = w_piece -> canMove (board,0,3,0,0);
    if (can_move)
	move_succ = board.move (BLACK,0,3,0,0);
    tempPiece = board.getPiece (0,0);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ(can_move,true);
    ASSERT_EQ(move_succ,true);
    ASSERT_EQ(found,true);
}


