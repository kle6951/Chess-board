#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "ioutil.h"

bool isKingCapture (Board &chess, int toX, int toY);

int main ()
{
    Board board;
    PiecePtr whitePtr = NULL, blackPtr = NULL;
    bool eof = false, game_over = false, can_move = false;
    int rows = 1, cols, fromX,fromY, toX, toY;
    char choice = ' ';
    bool player_turn = WHITE;
// set up white pieces

    PiecePtr whiteRook_01 = new Rook(WHITE);
    PiecePtr whiteRook_02 = new Rook(WHITE);
    PiecePtr whiteKnight_01 = new Knight(WHITE);
    PiecePtr whiteKnight_02 = new Knight(WHITE);
    PiecePtr whiteBishop_01 = new Bishop(WHITE);
    PiecePtr whiteBishop_02 = new Bishop(WHITE);
    PiecePtr whiteQueen = new Queen(WHITE);
    PiecePtr whiteKing = new King(WHITE);

    board.place(whiteRook_01, 7, 0);
    board.place(whiteRook_02, 7, 7);
    board.place(whiteKnight_01, 7, 1);
    board.place(whiteKnight_02, 7, 6);
    board.place(whiteBishop_01, 7, 2);
    board.place(whiteBishop_02, 7, 5);
    board.place(whiteQueen, 7, 3);
    board.place(whiteKing, 7,4);
// set up black pieces
    
    PiecePtr blackRook_01 = new Rook(BLACK);
    PiecePtr blackRook_02 = new Rook(BLACK);
    PiecePtr blackKnight_01 = new Knight(BLACK);
    PiecePtr blackKnight_02 = new Knight(BLACK);
    PiecePtr blackBishop_01 = new Bishop(BLACK);
    PiecePtr blackBishop_02 = new Bishop(BLACK);
    PiecePtr blackQueen = new Queen(BLACK);
    PiecePtr blackKing = new King(BLACK);

    board.place(blackRook_01, 0, 0);
    board.place(blackRook_02, 0, 7);
    board.place(blackKnight_01, 0, 1);
    board.place(blackKnight_02, 0, 6);
    board.place(blackBishop_01, 0, 2);
    board.place(blackBishop_02, 0, 5);
    board.place(blackQueen, 0, 3);
    board.place(blackKing, 0, 4);
    
    for (cols = 0; cols < MAXCOLS; cols++)
    {
	blackPtr = new Pawn (BLACK);
	board.place (blackPtr,rows,cols);
    }
    rows = MAXROWS - 2;
    for (cols = 0; cols < MAXCOLS; cols++)
    {
	whitePtr = new Pawn (WHITE);
	board.place (whitePtr,rows,cols);
    }    
    cout << "Welcome to the Chess Board !" << endl
	     << "The player number one will play white pawn "
	 << "AND the player two will play black pawn" << endl;
    while (choice != 'q')
    {
        cout << "\n\nThe current state of the Chess Board:\n"
             << board;

        if (player_turn == WHITE)
        {
            cout << "\nPlayer 1's Turn (White Piece): \n";
        }
        else
        {
            cout << "\nPlayer 2's Turn (Black Piece): \n";
        }

        cout << endl
	     <<"Enter the row and coloumn of the piece you want to move.\n"
             << "\nThe values of row and coloumn must be between 0-7.\n"
             << "\nTo quit the game, enter -1 -1.\n";
        fromX = readInt("Enter Starting Row's coordinate: ", eof);
        cout << endl;
        fromY = readInt("Enter Starting  Coloumn's coordinate: ", eof);
        cout << endl;

        if ((fromX == -1) || (fromY == -1))
        {
            choice = 'q';
        }

        while (  ((fromX < -1 || fromX > MAXROWS-1) ||
                  (fromY < -1 || fromY > MAXCOLS-1)) && choice != 'q')
        {
            cout << "\n** INVALID COORDINATES ** Must be 0-7 .\n";
            fromX = readInt("Enter Starting Row's coordinate: ", eof);
            cout << endl;
            fromY = readInt("Enter Starting Coloumn's coordinate: ", eof);
            cout << endl;
            if ((fromX == -1) || (fromY == -1))
            {
                choice = 'q';
            }
        }
        if (choice == 'q')
        {
            cout << endl << "PROGRAM IS TERMINATED..." << endl;
        }
        else
        {
            cout << endl
                 <<"Enter the row and coloumn of the piece's destination.\n"
                 << "\nThe values of row and coloumn must be from 0-7.\n"
                 <<"\nTo quit the game, enter -1 -1 .\n";
            toX = readInt("Enter Ending Row's coordinate: ", eof);
            cout << endl;
            toY = readInt("Enter Ending Coloumn's coordinate: ", eof);
            cout << endl;
            if ((toX == -1) || (toY == -1))
            {
                choice = 'q';
            }
            while (  ((toX < -1 || toX > MAXROWS-1) ||
                      (toY < -1 || toY > MAXCOLS-1)) && choice != 'q')
            {
                cout << "\n** INVALID COORDINATE ** Must be 0-7.\n";
                toX = readInt("Enter Ending Row's coordinate: ", eof);
                cout << endl;
                toY = readInt("Enter Ending Coloumn's coordinate: ", eof);
                cout << endl;
                if ((toX == -1) || (toY == -1))
                {
                    choice = 'q';
                }
            }

            if (choice == 'q')
            {
                cout << "\n PROGRAM IS TERMINATED...\n";
            }
            else
            {
                game_over = isKingCapture(board, toX, toY);

                can_move = board.move(player_turn,fromX,fromY, toX, toY);

                if (can_move && !game_over)
                {
                    player_turn = !player_turn;
                }
                else if (game_over && can_move)
                {
                    if (player_turn)
                    {
                        cout << "\n********************\n"
                             << "Player 1 (White) Wins!"
                             << "\n********************\n";
                    }
                    else
                    {
                        cout << "\n********************\n"
                             << "Player 2 (Black) Wins!"
                             << "\n********************\n";
                    }
                    choice = 'q';
                }
                else
                {
                    cout << "\n!!!ILLEGAL MOVE!!! Please try agian\n";
                }
            }
        }
    }
    return 0;
}
bool isKingCapture (Board &chess, int toX, int toY)
{
    bool is_available = false;

    if (chess.isOccupied(toX, toY))
    {
        PiecePtr kingCheck = chess.getPiece(toX, toY);

        if (kingCheck->getSymbol() == 'K'
            || kingCheck->getSymbol() == 'k')
        {
            is_available = true;
        }
        delete kingCheck;
    }
    return is_available;
}
