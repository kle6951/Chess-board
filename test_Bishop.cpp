#include "Board.h"
#include "Piece.h"
#include "Bishop.h"
#include <gtest/gtest.h>
class test_bishop : public testing :: Test
{
protected:
    virtual void SetUp ()
    {
    }
    virtual void TearDown()
    {
    }
};
TEST_F (test_bishop, constructor_Testing)
{
    PiecePtr w_piece = new Bishop (WHITE);
    bool same_col = false;

    if (w_piece -> getColour () == WHITE)
	same_col = true;
    ASSERT_EQ (same_col, true);
}
TEST_F (test_bishop, getSymbol_white_piece)
{
    PiecePtr w_piece = new Bishop (WHITE);
    char symbol;

    symbol = w_piece -> getSymbol ();
    ASSERT_EQ(symbol,'B');
}
TEST_F (test_bishop, getSymbol_black_piece)
{
    PiecePtr b_piece = new Bishop (BLACK);
    char symbol;

    symbol = b_piece -> getSymbol ();
    ASSERT_EQ(symbol,'b');
}
TEST_F (test_bishop, canMove_black_cannot_move_vertically_multiple_steps)
{
    bool can_move = false, found = false;
    PiecePtr b_piece = new Bishop (BLACK), tempPiece;
    Board board;

    board.place (b_piece,0,0);
    can_move = b_piece -> canMove (board,0,0,5,0);
    if (can_move)
	board.move (BLACK,0,0,5,0);

    tempPiece = board.getPiece (5,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found, false);
}
TEST_F (test_bishop, canMove_black_cannot_move_vertically_1_step)
{
    bool can_move = false, found = false;
    PiecePtr b_piece = new Bishop (BLACK), tempPiece;
    Board board;

    board.place (b_piece,0,0);
    can_move = b_piece -> canMove (board,0,0,1,0);
    if (can_move)
	board.move (BLACK,0,0,1,0);

    tempPiece = board.getPiece (1,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found, false);
}
TEST_F (test_bishop, canMove_black_cannot_move_horizontally_multiple_steps)
{
    bool can_move = false, found = false;
    PiecePtr b_piece = new Bishop (BLACK), tempPiece;
    Board board;

    board.place (b_piece,0,0);
    can_move = b_piece -> canMove (board,0,0,0,6);
    if (can_move)
	board.move (BLACK,0,0,0,6);

    tempPiece = board.getPiece (0,6);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found, false);
}
TEST_F (test_bishop, canMove_black_cannot_move_horizontally_1_step)
{
    bool can_move = false, found = false;
    PiecePtr b_piece = new Bishop (BLACK), tempPiece;
    Board board;

    board.place (b_piece,0,0);
    can_move = b_piece -> canMove (board,0,0,0,1);
    if (can_move)
	board.move (BLACK,0,0,0,1);

    tempPiece = board.getPiece (0,1);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found, false);
}
TEST_F (test_bishop, canMove_white_cannot_move_vertically_1_step)
{
    bool can_move = false, found = false;
    PiecePtr w_piece = new Bishop (WHITE), tempPiece;
    Board board;

    board.place (w_piece,7,0);
    can_move = w_piece -> canMove (board,7,0,3,0);
    if (can_move)
	board.move (WHITE,7,0,3,0);

    tempPiece = board.getPiece (3,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found, false);
}
TEST_F (test_bishop, canMove_white_cannot_move_vertically_multiple_steps)
{
    bool can_move = false, found = false;
    PiecePtr w_piece = new Bishop (WHITE), tempPiece;
    Board board;

    board.place (w_piece,7,0);
    can_move = w_piece -> canMove (board,7,0,6,0);
    if (can_move)
	board.move (WHITE,7,0,6,0);

    tempPiece = board.getPiece (6,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found, false);
}
TEST_F (test_bishop, canMove_white_cannot_move_horizontal_multiple_steps)
{
    bool can_move = false, found = false;
    PiecePtr w_piece = new Bishop (WHITE), tempPiece;
    Board board;

    board.place (w_piece,7,1);
    can_move = w_piece -> canMove (board,7,1,7,5);
    if (can_move)
	board.move (WHITE,7,1,7,5);

    tempPiece = board.getPiece (7,5);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found, false);
}
TEST_F (test_bishop, canMove_white_cannot_move_horizontally_1_step)
{
    bool can_move = false, found = false;
    PiecePtr w_piece = new Bishop (WHITE), tempPiece;
    Board board;

    board.place (w_piece,7,1);
    can_move = w_piece -> canMove (board,7,1,7,2);
    if (can_move)
	board.move (WHITE,7,1,7,2);

    tempPiece = board.getPiece (7,2);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found, false);
}
TEST_F (test_bishop, canMove_white_move_diagonally_1_step)
{
    bool can_move = false, found = false;
    PiecePtr w_piece = new Bishop (WHITE), tempPiece;
    Board board;

    board.place (w_piece,7,1);
    can_move = w_piece -> canMove (board,7,1,6,2);
    if (can_move)
	board.move (WHITE,7,1,6,2);

    tempPiece = board.getPiece (6,2);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found, true);
}
TEST_F (test_bishop, canMove_white_move_diagonally_multiple_steps)
{
    bool can_move = false, found = false;
    PiecePtr w_piece = new Bishop (WHITE), tempPiece;
    Board board;

    board.place (w_piece,7,1);
    can_move = w_piece -> canMove (board,7,1,5,3);
    if (can_move)
	board.move (WHITE,7,1,5,3);

    tempPiece = board.getPiece (5,3);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found, true);
}
TEST_F (test_bishop, canMove_white_cannot_move_occupied_path)
{
    bool can_move = false, found = false,move_succ =false;
    PiecePtr w_piece = new Bishop (WHITE), tempPiece;
    Board board;

    board.place (w_piece,7,1);
    w_piece = new Bishop (WHITE);
    board.place (w_piece,6,2);
    can_move = w_piece -> canMove (board,7,1,5,3);
    if (can_move)
	move_succ = board.move (WHITE,7,1,5,3);

    tempPiece = board.getPiece (5,3);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (move_succ,false);
    ASSERT_EQ (found, false);
}
TEST_F (test_bishop, canMove_move_opponent_different_colour)
{
    bool can_move = false, found = false,move_succ =false;
    PiecePtr w_piece = new Bishop (WHITE), tempPiece;
    Board board;

    board.place (w_piece,7,1);
    w_piece = new Bishop (BLACK);
    board.place (w_piece,5,3);
    can_move = w_piece -> canMove (board,7,1,5,3);
    if (can_move)
	move_succ = board.move (WHITE,7,1,5,3);

    tempPiece = board.getPiece (5,3);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,true);
    ASSERT_EQ (move_succ,true);
    ASSERT_EQ (found, true);
}
TEST_F (test_bishop, canMove_black_move_diagonally_1_step)
{
    bool can_move = false, found = false;
    PiecePtr b_piece = new Bishop (BLACK), tempPiece;
    Board board;

    board.place (b_piece,7,1);
    can_move = b_piece -> canMove (board,7,1,6,2);
    if (can_move)
	board.move (BLACK,7,1,6,2);

    tempPiece = board.getPiece (6,2);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found, true);
}
TEST_F (test_bishop, canMove_black_move_diagonally_multiple_steps)
{
    bool can_move = false, found = false;
    PiecePtr b_piece = new Bishop (BLACK), tempPiece;
    Board board;

    board.place (b_piece,7,1);
    can_move = b_piece -> canMove (board,7,1,5,3);
    if (can_move)
	board.move (BLACK,7,1,5,3);
    tempPiece = board.getPiece (5,3);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found, true);
}
