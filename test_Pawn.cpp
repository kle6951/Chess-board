#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include <gtest/gtest.h>
class test_pawn : public testing :: Test
{
protected:
    virtual void SetUp ()
    {
    }
    virtual void TearDown ()
    {
    }
};
TEST_F (test_pawn, constructor_white_piece)
{
    Board board;
    Pawn w_pawn (WHITE);
    bool colour = false;

    colour = w_pawn.getColour();

    ASSERT_EQ(colour,WHITE);
}
TEST_F (test_pawn, constructor_black_piece)
{
    Board board;
    Pawn b_pawn (BLACK);
    bool colour = false;

    colour = b_pawn.getColour();

    ASSERT_EQ(colour, BLACK);
}
TEST_F (test_pawn, getSymbol_white_pawn_symbol)
{
    Board b;
    Pawn w_pawn (WHITE);
    char symbol;

    symbol = w_pawn.getSymbol();

    ASSERT_EQ (symbol,'P');
}
TEST_F (test_pawn, getSymbol_black_pawn_symbol)
{
    Board b;
    Pawn b_pawn (BLACK);
    char symbol;

    symbol = b_pawn.getSymbol();

    ASSERT_EQ (symbol,'p');
}
TEST_F (test_pawn, canMove_black_move_vertically_2_steps)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (BLACK);
    bool found = false, can_move = false, good = false;

    board.place (pointer,0,0);
    can_move = pointer -> canMove (board,0,0,2,0);
    if (can_move)
	board.move (BLACK,0,0,2,0);
    tempPiece = board.getPiece (2,0);
    if (tempPiece != NULL)
    {
	found = true;
	if (BLACK == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
    ASSERT_EQ (good,true);
}
TEST_F (test_pawn, notifyMove_black_cannot_move_vertically_2_steps)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (BLACK);
    bool found = false, can_move = false, good = false;

    board.place (pointer,0,0);
    can_move = pointer -> canMove (board,0,0,2,0);

    if (can_move)
    {
	board.move (BLACK,0,0,2,0);
    }
    can_move = pointer -> canMove (board,2,0,4,0);
    tempPiece = board.getPiece (4,0);
    if (tempPiece != NULL)
    {
	found = true;
	if (BLACK == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_black_move_vertically_1_step_after_1st_move)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (BLACK);
    bool found = false, can_move = false, good = false;

    board.place (pointer,0,0);
    can_move = pointer -> canMove (board,0,0,2,0);
    if (can_move)
    {
	board.move (BLACK,0,0,2,0);
	pointer -> notifyMoved();
    }
    can_move = pointer -> canMove (board,2,0,3,0);
    if (can_move)
    {
	board.move (BLACK,2,0,3,0);
    }
    tempPiece = board.getPiece (3,0);
    if (tempPiece != NULL)
    {
	found = true;
	if (BLACK == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
    ASSERT_EQ (good,true);
}
TEST_F (test_pawn, canMove_black_cannot_move_vertically_multiple_steps)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (BLACK);
    bool found = false, can_move = false, good = false;

    board.place (pointer,0,0);
    can_move = pointer -> canMove (board,0,0,2,0);
    if (can_move)
    {
	board.move (BLACK,0,0,2,0);
	pointer -> notifyMoved();
    }
    can_move = pointer -> canMove (board,2,0,5,0);
    tempPiece = board.getPiece (5,0);
    if (tempPiece != NULL)
    {
	found = true;
	if (BLACK == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_white_move_vertically_2_steps)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,7,1);
    can_move = pointer -> canMove (board,7,1,5,1);
    if (can_move)
	board.move (WHITE,7,1,5,1);
    tempPiece = board.getPiece (5,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (WHITE == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
    ASSERT_EQ (good,true);
}
TEST_F (test_pawn, notifyMove_white_cannot_move_vertically_2_steps)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,7,1);
    can_move = pointer -> canMove (board,7,1,5,1);
    if (can_move)
    {
	board.move (WHITE,7,1,5,1);
	pointer -> notifyMoved();
    }
    can_move = pointer -> canMove (board,5,1,3,1);
    tempPiece = board.getPiece (3,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (WHITE == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_white_move_vertically_1_step_after_1st_move)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,7,1);
    can_move = pointer -> canMove (board,7,1,5,1);
    if (can_move)
    {
	board.move (WHITE,7,1,5,1);
	pointer -> notifyMoved();
    }
    can_move = pointer -> canMove (board,5,1,4,1);
    if (can_move)
    {
	pointer = new Pawn (WHITE);
	board.move (WHITE,5,1,4,1);
    }
    tempPiece = board.getPiece (4,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (WHITE == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
    ASSERT_EQ (good,true);
}
TEST_F (test_pawn, canMove_white_cannot_move_vertically_multiple_steps)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,7,1);
    can_move = pointer -> canMove (board,7,1,5,1);
    if (can_move)
    {
	board.move (WHITE,7,1,5,1);
	pointer -> notifyMoved();
    }
    can_move = pointer -> canMove (board,5,1,2,1);
    tempPiece = board.getPiece (2,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (WHITE == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_black_cannot_move_backward_1_steps)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (BLACK);
    bool found = false, can_move = false, good = false;

    board.place (pointer,5,0);
    can_move = pointer -> canMove (board,5,0,3,0);
    if (can_move)
	board.move (BLACK,5,0,3,0);
    tempPiece = board.getPiece (3,0);
    if (tempPiece != NULL)
    {
	found = true;
	if (BLACK == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_black_cannot_move_horizontally)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (BLACK);
    bool found = false, can_move = false, good = false;

    board.place (pointer,2,0);
    can_move = pointer -> canMove (board,2,0,2,1);
    if (can_move)
	board.move (BLACK,2,0,2,1);
    tempPiece = board.getPiece (2,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (BLACK == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_black_cannot_move_backward_multiple_steps)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (BLACK);
    bool found = false, can_move = false, good = false;

    board.place (pointer,5,0);
    can_move = pointer -> canMove (board,5,0,2,0);
    if (can_move)
	board.move (BLACK,5,0,2,0);
    tempPiece = board.getPiece (2,0);
    if (tempPiece != NULL)
    {
	found = true;
	if (BLACK == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_white_cannot_move_backward_1_steps)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,2,6);
    can_move = pointer -> canMove (board,2,6,3,6);
    if (can_move)
	board.move (WHITE,2,6,3,6);
    tempPiece = board.getPiece (3,6);
    if (tempPiece != NULL)
    {
	found = true;
	if (WHITE == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_white_cannot_move_backward_multiple_steps)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,2,6);
    can_move = pointer -> canMove (board,2,6,5,6);
    if (can_move)
	board.move (WHITE,2,6,5,6);
    tempPiece = board.getPiece (5,6);
    if (tempPiece != NULL)
    {
	found = true;
	if (WHITE == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_white_cannot_move_horizontally)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,5,1);
    can_move = pointer -> canMove (board,5,1,5,2);
    if (can_move)
	board.move (WHITE,5,1,5,2);
    tempPiece = board.getPiece (5,2);
    if (tempPiece != NULL)
    {
	found = true;
	if (WHITE == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_black_can_move_diagonally_1_step)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (BLACK);
    bool found = false, can_move = false, good = false;

    board.place (pointer,3,2);
    can_move = pointer -> canMove (board,3,2,4,1);

    if (can_move)
	board.move (BLACK,3,2,4,1);

    tempPiece = board.getPiece (4,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (BLACK == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_black_cannot_move_diagonally_multiple_steps)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (BLACK);
    bool found = false, can_move = false, good = false;

    board.place (pointer,3,2);
    can_move = pointer -> canMove (board,3,2,5,0);

    if (can_move)
	board.move (BLACK,3,2,5,0);

    tempPiece = board.getPiece (5,0);
    if (tempPiece != NULL)
    {
	found = true;
	if (BLACK == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_black_cannot_move_diagonally_after_1st_move)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (BLACK);
    bool found = false, can_move = false, good = false;

    board.place (pointer,0,0);
    can_move = pointer -> canMove (board,0,0,2,0);
    if (can_move)
    {
	board.move (BLACK,0,0,2,0);
	pointer -> notifyMoved();
    }
    can_move = pointer -> canMove (board,2,0,3,1);
    tempPiece = board.getPiece (3,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (BLACK == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_black_cannot_move_diagonally_backward)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (BLACK);
    bool found = false, can_move = false, good = false;

    board.place (pointer,3,2);
    can_move = pointer -> canMove (board,3,2,2,1);
    if (can_move)
    {
	board.move (BLACK,3,2,2,1);
	pointer -> notifyMoved();
    }
    tempPiece = board.getPiece (2,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (BLACK == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_black_cannot_move_diagonally_same_color)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (BLACK);
    bool found = false, can_move = false, good = false;

    board.place (pointer,3,2);
    pointer = new Pawn (BLACK);
    board.place (pointer,4,1);
    can_move = pointer -> canMove (board,3,2,4,1);
    if (can_move)
    {
	board.move (BLACK,3,2,4,1);
	pointer -> notifyMoved();
    }
    tempPiece = board.getPiece (4,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (BLACK == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,true);
    ASSERT_EQ (good,true);
}
TEST_F (test_pawn, canMove_black_move_diagonally_different_color)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (BLACK),
	pointer_02 = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,3,2);
    board.place (pointer_02,4,1);
    can_move = pointer -> canMove (board,3,2,4,1);
    if (can_move)
    {
	board.move (BLACK,3,2,4,1);
	pointer -> notifyMoved();
    }
    tempPiece = board.getPiece (4,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (BLACK == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
    ASSERT_EQ (good,true);
}
TEST_F(test_pawn,
       canMove_black_move_diagonally_different_color_after_1st_move)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (BLACK)
	,pointer_02 = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,0,0);
    board.place (pointer_02,3,1);
    can_move = pointer -> canMove (board,0,0,2,0);
    if (can_move)
    {
	board.move (BLACK,0,0,2,0);
	pointer -> notifyMoved();
    }
    can_move = pointer -> canMove (board,2,0,3,1);
    if (can_move)
	board.move (BLACK,2,0,3,1);

    tempPiece = board.getPiece (3,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (BLACK == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
    ASSERT_EQ (good,true);
}
TEST_F (test_pawn, canMove_white_cannot_move_diagonally_1_step)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,5,1);
    can_move = pointer -> canMove (board,5,1,4,2);

    if (can_move)
	board.move (WHITE,3,2,4,2);

    tempPiece = board.getPiece (4,2);
    if (tempPiece != NULL)
    {
	found = true;
	if (WHITE == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_white_cannot_move_diagonally_multiple_steps)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,5,1);
    can_move = pointer -> canMove (board,5,1,3,3);

    if (can_move)
	board.move (WHITE,5,1,3,3);

    tempPiece = board.getPiece (3,3);
    if (tempPiece != NULL)
    {
	found = true;
	if (WHITE == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_white_cannot_move_diagonally_after_1st_move)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,7,0);
    can_move = pointer -> canMove (board,7,0,5,0);
    if (can_move)
    {
	board.move (WHITE,7,0,5,0);
	pointer -> notifyMoved();
    }
    can_move = pointer -> canMove (board,5,0,4,1);
    tempPiece = board.getPiece (4,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (WHITE == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_white_cannot_move_diagonally_backward)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,3,0);
    can_move = pointer -> canMove (board,3,0,4,1);
    if (can_move)
    {
	board.move (WHITE,3,0,4,1);
	pointer -> notifyMoved();
    }
    tempPiece = board.getPiece (4,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (WHITE == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (good,false);
}
TEST_F (test_pawn, canMove_white_cannot_move_diagonally_same_color)
{
    Board board;
    PiecePtr tempPiece, pointer = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,3,2);
    pointer = new Pawn (WHITE);
    board.place (pointer,2,1);
    can_move = pointer -> canMove (board,3,2,2,1);
    if (can_move)
    {
	board.move (WHITE,3,2,2,1);
	pointer -> notifyMoved();
    }
    tempPiece = board.getPiece (2,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (WHITE == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,true);
    ASSERT_EQ (good,true);
}
TEST_F (test_pawn, canMove_white_move_diagonally_different_color)
{
    Board board;
    PiecePtr tempPiece, pointer_02 = new Pawn (BLACK)
	,pointer = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,3,2);
    board.place (pointer_02,2,1);
    can_move = pointer -> canMove (board,3,2,2,1);
    if (can_move)
    {
	board.move (WHITE,3,2,2,1);
	pointer -> notifyMoved();
    }
    tempPiece = board.getPiece (2,1);
    if (tempPiece != NULL)
    {
	found = true;
	if (WHITE == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
    ASSERT_EQ (good,true);
}
TEST_F(test_pawn,
       canMove_white_move_diagonally_different_color_after_1st_move)
{
    Board board;
    PiecePtr tempPiece, pointer_02 = new Pawn (BLACK)
	,pointer = new Pawn (WHITE);
    bool found = false, can_move = false, good = false;

    board.place (pointer,7,1);
    board.place (pointer_02,4,2);
    can_move = pointer -> canMove (board,7,1,5,1);
    if (can_move)
    {
	board.move (WHITE,7,1,5,1);
	pointer -> notifyMoved();
    }
    can_move = pointer -> canMove (board,5,1,4,2);
    if (can_move)
	board.move (WHITE,5,1,4,2);

    tempPiece = board.getPiece (4,2);
    if (tempPiece != NULL)
    {
	found = true;
	if (WHITE == tempPiece -> getColour())
	    good = true;
    }
    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,true);
    ASSERT_EQ (good,true);
}
