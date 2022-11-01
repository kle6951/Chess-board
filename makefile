CPPFLAGS=-ansi -pedantic -errors -Wall -Wconversion
GCOVFLAGS=-fprofile-arcs -ftest-coverage
GTFLAGS=-lgtest -lgtest_main -lpthread

TARGET= game
MODULES= game.o Board.o Piece.o Pawn.o King.o Queen.o Bishop.o Knight.o Rook.o ioutil.o

$(TARGET): $(MODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(GCOVFLAGS) $(MODULES) -o $(TARGET)

BOARD_TEST= test_Board
BOARD_TEST_MODULES= test_Board.o Board.o Piece.o Pawn.o

PAWN_TEST= test_Pawn
PAWN_TEST_MODULES= test_Pawn.o Pawn.o Piece.o Board.o

$(PAWN_TEST): $(PAWN_TEST_MODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(PAWN_TEST_MODULES) -o $(PAWN_TEST)
	./test_Pawn
	gcov Pawn.cpp 2> /dev/null | grep -A 1 Pawn.cpp

KING_TEST=test_King
KING_TEST_MODULES= test_King.o King.o Piece.o Board.o

$(KING_TEST): $(KING_TEST_MODULES)
	g++ $(GTFLAGS) $(GCOVFLAGS) $(KING_TEST_MODULES) -o $(KING_TEST)
	./test_King
	gcov King.cpp 2> /dev/null | grep -A 1 King.cpp

QUEEN_TEST=test_Queen
QUEEN_TEST_MODULES= test_Queen.o Queen.o Piece.o Board.o

$(QUEEN_TEST): $(QUEEN_TEST_MODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(QUEEN_TEST_MODULES) -o $(QUEEN_TEST)
	./test_Queen
	gcov Queen.cpp 2> /dev/null | grep -A 1 Queen.cpp

BISHOP_TEST=test_Bishop
BISHOP_TEST_MODULES= test_Bishop.o Piece.o Board.o Bishop.o

$(BISHOP_TEST): $(BISHOP_TEST_MODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(BISHOP_TEST_MODULES) -o $(BISHOP_TEST)
	./test_Bishop
	gcov Bishop.cpp 2> /dev/null | grep -A 1 Bishop.cpp

ROOK_TEST=test_Rook
ROOK_TEST_MODULES= test_Rook.o Piece.o Board.o Rook.o

$(ROOK_TEST): $(ROOK_TEST_MODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(ROOK_TEST_MODULES) -o $(ROOK_TEST)
	./test_Rook
	gcov Rook.cpp 2> /dev/null | grep -A 1 Rook.cpp

KNIGHT_TEST=test_Knight
KNIGHT_TEST_MODULES= test_Knight.o Piece.o Board.o Knight.o

$(KNIGHT_TEST): $(KNIGHT_TEST_MODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(KNIGHT_TEST_MODULES) -o $(KNIGHT_TEST)
	./test_Knight
	gcov Knight.cpp 2> /dev/null | grep -A 1 Knight.cpp


clean:
	/bin/rm -f *.~ ~.o $(BISHOP_TEST) $(PAWN_TEST) $(KING_TEST) $(QUEEN_TEST) *.gcda *.gcov *.gcno final_board.txt

test: clean $(BISHOP_TEST) $(PAWN_TEST) $(KING_TEST) $(QUEEN_TEST) $(ROOK_TEST)

test_Knight.o: test_Knight.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_Knight.cpp
test_Rook.o: test_Rook.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_Rook.cpp
test_Bishop.o: test_Bishop.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_Bishop.cpp
test_Queen.o: test_Queen.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_Queen.cpp
test_King.o: test_King.cpp Board.h King.h Piece.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_King.cpp
test_Pawn.o: test_Pawn.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_Pawn.cpp
test_Board.o: test_Board.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_Board.cpp
Board.o: Board.cpp Board.h Pawn.h Piece.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Board.cpp
game.o: game.cpp Piece.h Pawn.h Board.h King.h Queen.h Bishop.h Knight.h Rook.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c game.cpp
Piece.o: Piece.cpp Piece.h Board.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Piece.cpp
Pawn.o: Pawn.cpp Pawn.h Piece.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Pawn.cpp
King.o: King.cpp King.h Piece.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c King.cpp
Queen.o: Queen.cpp Queen.h Piece.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Queen.cpp
Bishop.o: Bishop.cpp Bishop.h Piece.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Bishop.cpp
Knight.o: Knight.cpp Knight.h Piece.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Knight.cpp
Rook.o: Rook.cpp Rook.h Piece.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Rook.cpp
ioutil.o: ioutil.cpp ioutil.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c ioutil.cpp

