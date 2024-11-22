#include <stdio.h>
#include <stdbool.h>

// GAME BOARD
char board[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}
};

// PRINT GAME BOARD
void printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

// CHECK VALID MOVE
bool isValidMove(int row, int col)
{
    if ((row >= 0 && row < 3) &&
        (col >= 0 && col < 3) &&
        board[row][col] == '-')
    {
        return true;
    }
    return false;
}

// PLAYER MOVE
void playerMove(char player)
{
    int row, col;
    while (1)
    {
        printf("Player %c Turn: Enter row and column (0-2): ", player);
        // if input other than 2 integers then clear the input buffer and show warning 
        if (scanf("%d %d", &row, &col) != 2) {
            // clear the current char until newline
            while (getchar() != '\n');
            // show warning
            printf("Invalid input. Please enter two numbers for row and column.\n");
            continue;
        }
        if (isValidMove(row, col))
        {
            board[row][col] = player;
            break;
        }
        else
        {
            printf("Invalid Move, Try Again!\n");
        }
    }
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                return false; // empty cell exists
            }
        }
    }
    return true; // no empty cell so draw
}

char checkWin()
{
    // Check rows
    for (int row = 0; row < 3; row++)
    {
        if (board[row][0] != '-' && board[row][0] == board[row][1] && board[row][1] == board[row][2])
        {
            return board[row][0];
        }
    }
    // Check columns
    for (int col = 0; col < 3; col++)
    {
        if (board[0][col] != '-' && board[0][col] == board[1][col] && board[1][col] == board[2][col])
        {
            return board[0][col];
        }
    }
    // Check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][2];
    }
    return '-';
}
int main()
{

    // INITIAL MESSAGE
    
    printf("Tic-Tac-Toe\n");
    printBoard();

    // MAIN GAME LOOP
    while (1)
    {
        playerMove('X');
        printBoard();
        if (checkWin() != '-')
        {
            printf("Player %c Won!\n", checkWin());
            break;
        }
        if (checkDraw())
        {
            printf("It's a Draw!\n");
            break;
        }
        playerMove('O');
        printBoard();
        if (checkWin() != '-')
        {
            printf("Player %c Won!\n", checkWin());
            break;
        }
        if (checkDraw())
        {
            printf("It's a Draw!\n");
            break;
        }
    }
    return 0;
}
