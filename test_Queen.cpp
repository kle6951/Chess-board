#include "Board.h"
#include "Piece.h"
#include "Queen.h"
#include <gtest/gtest.h>
class test_queen : public testing :: Test
{
protected:
    virtual void SetUp ()
    {
    }
    virtual void TearDown ()
    {
    }
};
TEST_F (test_queen, constructor_testin)
{
    PiecePtr w_piece = new Queen (WHITE);
    bool same_col = false;
    if (w_piece -> getColour () == WHITE)
	same_col = true;
    ASSERT_EQ (same_col,true);
}
TEST_F (test_queen,getSymbol_white_queen)
{
    PiecePtr w_piece = new Queen (WHITE);
    char symbol;

    symbol = w_piece -> getSymbol();
    ASSERT_EQ (symbol,'Q');
}
TEST_F (test_queen,getSymbol_black_queen)
{
    PiecePtr b_piece = new Queen (BLACK);
    char symbol;

    symbol = b_piece -> getSymbol();
    ASSERT_EQ (symbol,'q');
}
TEST_F (test_queen, canMove_white_move_vertically_multiple_steps)
{
    Board board;
    bool can_move = false, found = false;
    PiecePtr w_queen = new Queen (WHITE), tempPiece;

    board.place (w_queen,7,0);
    can_move = w_queen -> canMove(board,7,0,4,0);
    if(can_move)
	board.move (WHITE,7,0,4,0);
    tempPiece = board.getPiece (4,0);
    if (tempPiece != NULL)
	found = true;
    
    ASSERT_EQ(can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_queen, canMove_white_move_horizontally_multiple_steps)
{
    Board board;
    bool can_move = false, found = false;
    PiecePtr w_queen = new Queen (WHITE), tempPiece;

    board.place (w_queen,5,1);
    can_move = w_queen -> canMove(board,5,1,5,7);
    if(can_move)
	board.move (WHITE,5,1,5,7);
    tempPiece = board.getPiece (5,7);
    if (tempPiece != NULL)
	found = true;
    
    ASSERT_EQ(can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_queen, canMove_white_move_diagonally_multiple_steps)
{
    Board board;
    bool can_move = false, found = false;
    PiecePtr w_queen = new Queen (WHITE), tempPiece;

    board.place (w_queen,3,2);
    can_move = w_queen -> canMove(board,3,2,5,0);
    if(can_move)
	board.move (WHITE,3,2,5,0);
    tempPiece = board.getPiece (5,0);
    if (tempPiece != NULL)
	found = true;
    
    ASSERT_EQ(can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_queen, canMove_black_move_vertically_multiple_steps)
{
    Board board;
    bool can_move = false, found = false;
    PiecePtr b_queen = new Queen (BLACK), tempPiece;

    board.place (b_queen,7,0);
    can_move = b_queen -> canMove(board,7,0,4,0);
    if(can_move)
	board.move (BLACK,7,0,4,0);
    tempPiece = board.getPiece (4,0);
    if (tempPiece != NULL)
	found = true;
    
    ASSERT_EQ(can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_queen, canMove_black_move_horizontally_multiple_steps)
{
    Board board;
    bool can_move = false, found = false;
    PiecePtr b_queen = new Queen (BLACK), tempPiece;

    board.place (b_queen,5,1);
    can_move = b_queen -> canMove(board,5,1,5,7);

    can_move = 	board.move (BLACK,5,1,5,7);
    tempPiece = board.getPiece (5,7);
    if (tempPiece != NULL)
	found = true;
    
    ASSERT_EQ(can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_queen, canMove_black_move_diagonally_multiple_steps)
{
    Board board;
    bool can_move = false, found = false;
    PiecePtr b_queen = new Queen (BLACK), tempPiece;

    board.place (b_queen,3,2);
    can_move = b_queen -> canMove(board,3,2,5,0);
    if(can_move)
	board.move (BLACK,3,2,5,0);
    tempPiece = board.getPiece (5,0);
    if (tempPiece != NULL)
	found = true;
    
    ASSERT_EQ(can_move,true);
    ASSERT_EQ(found,true);
}
TEST_F (test_queen, canMove_cannotMove_isPathClear_is_false)
{
    Board board;
    bool can_move = false,found = false;
    PiecePtr queen = new Queen (BLACK), tempPiece;

    board.place (queen,5,1);
    queen = new Queen (WHITE);
    board.place (queen,5,3);
    can_move = queen -> canMove (board,5,3,5,0);
    if (can_move)
	board.move (WHITE,5,3,5,0);
    tempPiece = board.getPiece (5,0);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (can_move,false);
}
TEST_F (test_queen, canMove_move_different_color)
{
    Board board;
    bool can_move = false,found = false;
    PiecePtr queen = new Queen (BLACK), tempPiece;

    board.place (queen,5,1);
    queen = new Queen (WHITE);
    board.place (queen,5,3);
    can_move = queen -> canMove (board,5,3,5,1);
    
    if (can_move)
	can_move = board.move (WHITE,5,3,5,1);
    
    tempPiece = board.getPiece (5,3);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,true);
    ASSERT_EQ (found,false);
}
TEST_F (test_queen, canMove_cannotmove_same_color)
{
    Board board;
    bool can_move = false,found = false;
    PiecePtr queen = new Queen (BLACK), tempPiece;

    board.place (queen,5,1);
    queen = new Queen (BLACK);
    board.place (queen,5,3);
    can_move = queen -> canMove (board,5,3,5,1);
    
    if (can_move)
	can_move = board.move (WHITE,5,3,5,1);
    
    tempPiece = board.getPiece (5,1);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (can_move,false);
    ASSERT_EQ (found,true);
}
