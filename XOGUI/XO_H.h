
#pragma once
// used because in GUI you cannot set a text of the cell to be Character.
// So instead we use string.
#define symX "X"        // defines symX to be "X" which will be used in GUI
#define symO "O"        // defines symO to be "O" which will be used in GUI


/*
    Converting from Row & Coloumn [0:2] --> to --> integer button position from 1 to 9
                    Row *3 + Coloumn + 1
    Ex... -->   mainboard[2][1] = ( (2*3) + 1 + 1 )  = 8
*/


#ifndef  XO_HEADER
#define XO_HEADER

#define inf 1000


class tictactoe
{
private:
    char mainboard[3][3];           // the board where computer'll do his operations and algorithm away from the GUI
    // And also checking if game is over and who is the winner is done on it.

    struct Move                     // used to return the row & column
    {
        int col, row;
    };

    int max(int first, int second);             // finds maximum between the two variables.
    int min(int first, int second);             // finds minimum between the two variables.
    int evaluate(char b[3][3]);                 // used to check if the game is over and who is the winner.

    int minimax(char board[3][3], int depth, bool isMax);               // for computer
    // recursive function which's an algorithm that checks for the best move on a different paths.
    // and to be mentioned that ... the computer finishs the game (playing his turn and opponents turn to fins best possible moves).

    Move findBestMove(char board[3][3]);
    // function which calls the  [ minimax() ] that checks for the best on all over the board during this specific turn.

    bool isMovesLeft(char board[3][3]);         // used to check if there's no moves left (tie situation).
    // Very important function as if it's not used ... game will be tie in a neutral play that has been played.

public:

    tictactoe::tictactoe()              // Class constructor. (which sets all values of the mainboard to be empty [ _ ] ).
    {
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                mainboard[r][c] = '_';
    }

    bool turn = true;       // Player 1 Turn.
    char computer;          // Computer's Symbol
    char opponent;          // Player's Symbol

    int Over();             // Used to check if game is over ... depending on the values returned from evaluate function.

    void Empty();                       // To empty the board after restarting.
    void select(char select);           // To select the symbol for Player & Computer (depending on the GUI chosen value).

    int nightmareComputer_turn();       // The nightmare unbeatable mode ... which uses minimax algorithm & find best move.

    void input(int row, int col);           // For against Computer.
    // which makes the computer set his value on the main board.

    void input2(int row, int col);          // For against Player.
    // which makes the other player set his value on the mainboard.

    int easyComputer_turn();                // For the easily beatable mode against computer.

};
#endif