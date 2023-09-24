/***************************************************************************/
/*	Project : TicTacToe     											   */
/*	Details : XO game playable versus computer on 2-mode (easy-nightmare)  */
/*            and versus another player                                    */
/***************************************************************************/

#include "XO_H.h"
#include <stdlib.h>



void tictactoe::select(char select)
{
    // Choosing the Player's (opponent) X or O to bet set on the mainboard.
    // note that: on player vs player mode ... Player 2 will be the computer.
    if (select == 'X' || select == 'x') {       // Player 1 goes with [ X ]
        computer = 'O';
        opponent = 'X';
    }
    else if (select == 'O' || select == 'o')    // Player 1 goes with [ O ]
    {
        computer = 'X';
        opponent = 'O';
    }
}

// returns the maximum variable & used in Maximizer turn
int tictactoe::max(int first, int second)
{
    if (first > second)
        return first;
    return second;
}
// returns the minimum variable & used in Minimizer turn
int tictactoe::min(int first, int second)
{
    if (first < second)
        return first;
    return second;
}

// Checks endgame after current play of this turn 
// (and Specfically important for the last move which could be tie)
int tictactoe::Over() {
    if (!isMovesLeft(mainboard) && evaluate(mainboard) == 0)        // for the last move = tie.
        return inf;
    return evaluate(mainboard);                                     // is there is a winner?
}

// return the play of the computer & modify array with computer's play
// and use the row & column equation to be converted into the correct cell on the GUI.
int tictactoe::nightmareComputer_turn() {
    Move bestMove = findBestMove(mainboard);
    mainboard[bestMove.row][bestMove.col] = computer;
    return bestMove.row * 3 + bestMove.col + 1;
}

// return the best play for the computer all over the board.
tictactoe::Move tictactoe::findBestMove(char board[3][3])
{
    int bestVal = -inf;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal value.

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            // Check if cell is empty
            if (board[row][col] == '_')
            {
                // Make the move
                board[row][col] = computer;

                // compute evaluation function for this move.
                int moveVal = minimax(board, 0, false);

                // Undo the move
                board[row][col] = '_';

                // If the value of the current move is
                // more than the best value, then update best value.
                // with the optimal value to be played.
                if (moveVal > bestVal)
                {
                    bestMove.row = row;
                    bestMove.col = col;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

// evaluating game state (win or lose or tie)
int tictactoe::evaluate(char b[3][3])
{
    // Checking for Rows for X or O victory.
    for (int row = 0; row < 3; row++)
    {
        if (b[row][0] == b[row][1] &&
            b[row][1] == b[row][2])
        {
            if (b[row][0] == computer)
                return +10;
            else if (b[row][0] == opponent)
                return -10;
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col < 3; col++)
    {
        if (b[0][col] == b[1][col] &&
            b[1][col] == b[2][col])
        {
            if (b[0][col] == computer)
                return +10;

            else if (b[0][col] == opponent)
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
    {
        if (b[0][0] == computer)
            return +10;
        else if (b[0][0] == opponent)
            return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
    {
        if (b[0][2] == computer)
            return +10;
        else if (b[0][2] == opponent)
            return -10;
    }

    // Else if none of them have won then return 0
    // which to be converted to infinity when it's a tie.
    return 0;
}

// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board & it is used by findBestMove function to evaluate each available move
int tictactoe::minimax(char board[3][3], int depth, bool isMax)
{
    int score = evaluate(board);

    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score - depth;    // use depth to determine the shortest win for maximizer

    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score + depth;   // use depth to determine the shortest win for minimizer

    // If there are no more moves and no winner then
    // it is a tie
    if (isMovesLeft(board) == false)
        return 0;

    // If this maximizer's move
    if (isMax)
    {
        int best = -inf;

        // Traverse all cells
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // Check if cell is empty
                if (board[i][j] == '_')
                {
                    // Make the move
                    board[i][j] = computer;

                    // Call minimax recursively and choose
                    // the maximum value
                    best = max(best, minimax(board, depth + 1, !isMax));

                    // Undo the move
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }

    // If this minimizer's move
    else
    {
        int best = inf;

        // Traverse all cells
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // Check if cell is empty
                if (board[i][j] == '_')
                {
                    // Make the move
                    board[i][j] = opponent;

                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best, minimax(board, depth + 1, !isMax));

                    // Undo the move
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}

// This function returns true if there are moves
// remaining on the board. and it returns false if
// there are no moves left to play.
bool tictactoe::isMovesLeft(char board[3][3])
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (board[row][col] == '_')
                return true;
    return false;
}

// used to input the play of Player 1 (Only against computer).
void tictactoe::input(int row, int col)
{
    mainboard[row][col] = opponent;                 // Opponent plays            
}

// used to input the play of Player 2 (Player vs Player).
void tictactoe::input2(int row, int col)
{
    mainboard[row][col] = computer;
}

// Empties the whole mainboard when game is over and restarted.
void tictactoe::Empty()
{
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            mainboard[r][c] = '_';
}

// The easy mode computer mode.
// doesn't really use complicated algorithm
// just plays on these specific locations.
// depending if they're empty on the board.
int tictactoe::easyComputer_turn()
{
    int x = 0, y = 0, i = 1;
    while (y < 3)
    {
        while (x < 3)
        {
            if (mainboard[x][y] == '_')
            {
                mainboard[x][y] = computer;
                return x * 3 + y + 1;
            }
            x += 1 + i;
        }
        y++; i = 0;
        x = 0;
    }
}
