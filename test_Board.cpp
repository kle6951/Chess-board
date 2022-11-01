#include "Board.h"
#include <sstream>
#include <gtest/gtest.h>

class test_board : public testing ::Test
{
protected:
    virtual void SetUp ()
    {
    }
    virtual void TearDown ()
    {
    }
};
TEST_F (test_board, constructor_all_PiecePtr_should_return_NULL)
{
    Board b;
    PiecePtr p;
    int counter, counter_02;
    bool empty = false;

    for (counter = 0; counter < MAXROWS; counter++)
    {
	for (counter_02 = 0; counter_02 < MAXCOLS; counter_02++)
	{
	    p = b.getPiece (counter,counter_02);
	    if (p == NULL)
		empty = true;
	    ASSERT_EQ (empty,true);
	}
    }
}

TEST_F (test_board, place_function_one_item_is_added)
{
    Board b;
    Piece fake_pawn(WHITE);
    PiecePtr p = &fake_pawn, tempPiece;
    bool found = false, can_add = false;

    can_add = b.place (p,4,5);
    tempPiece = b.getPiece (4,5);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (found,true);
    ASSERT_EQ (can_add,true);
}

TEST_F (test_board, place_function_multiple_items_are_added)
{
    Board b;
    Piece fake_pawn(WHITE);
    PiecePtr p = &fake_pawn,tempPiece;
    bool found = false, can_add = false;

    can_add = b.place (p,1,1);
    tempPiece = b.getPiece (1,1);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ (found,true);
    ASSERT_EQ (can_add,true);

    can_add = b.place (p,2,2);
    tempPiece = b.getPiece (2,2);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ (found,true);
    ASSERT_EQ (can_add,true);

    can_add = b.place (p,3,7);
    tempPiece = b.getPiece (3,7);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ (found,true);
    ASSERT_EQ (can_add,true);
     
    can_add = b.place (p,5,4);
    tempPiece = b.getPiece (5,4);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ (found,true);
    ASSERT_EQ (can_add,true);
}

TEST_F (test_board, place_function_unable_to_add_nonEmpty_position)
{
    Board b;
    Piece fake_pawn(WHITE);
    PiecePtr p = &fake_pawn, tempPiece;
    bool found = false, can_add = false;

    can_add = b.place (p,4,5);
    can_add = b.place (p,4,5);
    tempPiece = b.getPiece (4,5);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (found,true);
    ASSERT_EQ (can_add,false);
}

TEST_F (test_board, assignment_constructor)
{
    Board b1,b2;
    Piece fake_pawn (WHITE);
    PiecePtr p = &fake_pawn, tempPiece;
    bool found = false;
    b1.place(p,1,1);
    b2.place (p,2,2);
    b2 = b1;

    tempPiece = b2.getPiece (1,1);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (found,true);
}

TEST_F (test_board, copy_constructor)
{
    Board b1;
    Piece fake_pawn (WHITE);
    PiecePtr p = &fake_pawn,tempPiece;
    bool found = false;
    b1.place (p,1,1);
    Board b2 = b1;

    tempPiece = b2.getPiece (1,1);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (found,true);
}

TEST_F (test_board, remove_function_remove_one_item)
{
    Board b;
    Piece fake_pawn (WHITE);
    PiecePtr p = &fake_pawn, tempPiece;
    bool found = false, can_remove = false;

    b.place (p,4,5);
    can_remove = b.remove (4,5);
    tempPiece = b.getPiece (4,5);
    if (tempPiece != NULL)
	found = true;

    ASSERT_EQ (found,false);
    ASSERT_EQ (can_remove,true);
}
TEST_F (test_board, remove_function_remove_multiple_items)
{
    Board b;
    Piece fake_pawn (WHITE);
    PiecePtr p = &fake_pawn, tempPiece;
    bool found = false, can_remove = false;

    b.place (p,4,5);
    b.place (p,1,2);
    b.place (p,3,6);

    can_remove = b.remove (3,6);
    tempPiece = b.getPiece (3,6);
    if (tempPiece != NULL)
	found = true;
     ASSERT_EQ (found,false);
    ASSERT_EQ (can_remove,true);

    can_remove = b.remove (1,2);
    tempPiece = b.getPiece (1,2);
    if (tempPiece != NULL)
	found = true;
     ASSERT_EQ (found,false);
    ASSERT_EQ (can_remove,true);

    can_remove = b.remove (4,5);
    tempPiece = b.getPiece (4,5);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ (found,false);
    ASSERT_EQ (can_remove,true);
}

TEST_F (test_board, remove_functioin_unable_to_remove_empty_position)
{
    Board b;
    PiecePtr tempPiece;
    bool found = false, can_remove = false;

    can_remove = b.remove (1,1);
    tempPiece = b.getPiece (1,1);
    if (tempPiece != NULL)
	found = true;
    ASSERT_EQ (found,false);
    ASSERT_EQ (can_remove,false);
}

TEST_F (test_board, move_function_able_to_move)
{
    Board b;
    Piece fake_pawn (WHITE);
    PiecePtr p = &fake_pawn, tempPiece,tempPiece_02;
    bool found = false, can_move = false, found_02 = false;

    b.place (p,7,1);
    can_move = b.move (WHITE,7,1,5,1);
    tempPiece = b.getPiece(5,1);
    tempPiece_02 = b.getPiece (7,1);
    if (tempPiece != NULL)
	found = true;
    if (tempPiece_02 != NULL)
	found_02 = true;
    ASSERT_EQ (found_02,false);
    ASSERT_EQ (found,true);
    ASSERT_EQ (can_move,true);
    
}

TEST_F (test_board, move_function_unable_to_move_empty_beginning_position)
{
    Board b;
    PiecePtr tempPiece,tempPiece_02;
    bool found = false, can_move = false, found_02 = false;

    can_move = b.move (WHITE,1,1,3,4);
    tempPiece = b.getPiece(3,4);
    tempPiece_02 = b.getPiece (1,1);
    if (tempPiece != NULL)
	found = true;
    if (tempPiece_02 != NULL)
	found_02 = true;
    ASSERT_EQ (found_02,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (can_move,false);
    
}

TEST_F (test_board, move_function_unable_to_move_nonEmpty_destination)
{
    Board b;
    Piece fake_pawn (WHITE);
    PiecePtr p = &fake_pawn, tempPiece,tempPiece_02;
    bool found = false, can_move = false, found_02 = false;

    b.place (p,1,1);
    b.place (p,3,4);
    can_move = b.move (WHITE,1,1,3,4);
    tempPiece = b.getPiece(3,4);
    tempPiece_02 = b.getPiece (1,1);
    if (tempPiece != NULL)
	found = true;
    if (tempPiece_02 != NULL)
	found_02 = true;
    ASSERT_EQ (found_02,true);
    ASSERT_EQ (found,true);
    ASSERT_EQ (can_move,false);
    
}

TEST_F (test_board, move_function_unable_to_move_Empty_destination_and_start)
{
    Board b;
    PiecePtr tempPiece,tempPiece_02;
    bool found = false, can_move = false, found_02 = false;

    can_move = b.move (WHITE,1,1,3,4);
    tempPiece = b.getPiece(3,4);
    tempPiece_02 = b.getPiece (1,1);
    if (tempPiece != NULL)
	found = true;
    if (tempPiece_02 != NULL)
	found_02 = true;
    ASSERT_EQ (found_02,false);
    ASSERT_EQ (found,false);
    ASSERT_EQ (can_move,false);
    
}
