//Michael Chon
//100622
//Tic Tac Toe game between 2 players or player vs computer
#include <stdio.h>
#include <stdlib.h>
#define R 3
#define C 3

int promptUser(int choice);
void drawBoard(char board[R][C]);
int markCheck(char board[R][C], int row, int col);
char winCheck(char board[R][C]);

int main(void) {
    int choice, mark;
    int row, col;
    int turn = 9;
    char game = ' ';
    char board[R][C] = {{' ',' ',' '},
                        {' ',' ',' '},
                        {' ',' ',' '}
    };

    //prompt user for game they wish to play
    choice = promptUser(choice);
    drawBoard(board);

    //if 1 (pvp)
    if(choice == 1)
    {
        //start game loop until win condition is met
        while(game == ' ')
        {
            //prompt p1 for move, receive input as row, column, then place 'X'
            mark = 1;
            while(mark)
            {
                printf("Player 1: Make your move\n");
                scanf("%d %d", &row, &col);
                if(((row >= 1 && row <= 3) && (col >= 1 && col <= 3)))
                {   
                    //check if there's a mark there already
                    if(markCheck(board, row, col) == 1)
                    {
                        mark = 0;
                        printf("Good!\n");
                        //display board
                        board[row-1][col-1] = 'X';
                        drawBoard(board);
                    }
                    else
                    {
                        printf("There is already a mark there. Enter new value\n");
                    }               
                }
            }

            turn--;
            game = winCheck(board);
            if(game != ' ')
            {
                if(game == 'X') 
                    printf("Winner is player 1!\n");
                else
                    printf("Winner is player 2!\n");
                break;
            }
            if(turn == 0)
            {
                printf("Tie!\n");
                break;
            }
            
            //prompt p2 for move receive input as row, column, then place 'O'
            mark = 1;
            while(mark)
            {
                printf("Player 2: Make your move\n");
                scanf("%d %d", &row, &col);
                if(((row >= 1 && row <= 3) && (col >= 1 && col <= 3)))
                {
                    if(markCheck(board, row, col) == 1)
                    {
                        mark = 0;
                        printf("Good!\n");
                        board[row-1][col-1] = 'O';
                        drawBoard(board);
                    }
                    else
                    {
                        printf("There is already a mark there. Enter new value\n");
                    }   
                }
            }

            turn--;
            game = winCheck(board);
            if(game != ' ')
            {
                if(game == 'X')
                    printf("Winner is player 1!\n");
                else
                    printf("Winner is player 2!\n");
                break;
            }
            if(turn == 0)
            {
                 printf("Tie!\n");
                 break;
            }
        }
    }
/*
    //if 2 (pvc)
    else if(choice == 2)
    {
        //start game loop until win conidtion is met

        //prompt p1 for move, receive input as row, column, then place 'X'

        //display board

        //generate random number for row and column, check if existing mark, then place 'O' if nothing

        //display board

        //loop until EITHER 3 in a row or no more tiles to fill

        //display congrats or better luck next time, end program
    }
*/
    return 0;
}

int promptUser(int choice) {
    printf("WELCOME TO TIC TAC TOE!\n");
    printf("1 --- person vs person\n2 --- person vs random computer\n");
    printf("Enter your choice (1 or 2): ");
    //read information from console
    int check = scanf("%d", &choice);
    if((check == 0) || (choice != (1 || 2)))
    {
        printf("Error reading choice...\n");
        exit(0);
    }
    //display back choice and current status of board (blank)
    printf("==========================\n");
    printf("You have entered choice %d\n", choice);
    return choice;
}

void drawBoard(char board[R][C]) {
    printf("The current status is:\n");
    printf("+-----------+\n");
    printf("| %c | %c | %c | \n", board[0][0], board[0][1], board[0][2]);
    printf("+-----------+\n");
    printf("| %c | %c | %c | \n", board[1][0], board[1][1], board[1][2]);
    printf("+-----------+\n");
    printf("| %c | %c | %c | \n", board[2][0], board[2][1], board[2][2]);
    printf("+-----------+\n");
}

int markCheck(char board[R][C], int row, int col) {
    if(board[row-1][col-1] == ' ')
        return 1;
    else
        return 0;
}

char winCheck(char board[R][C]) {
    //top row
    if(board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return board[0][0];
    //middle row
    else if(board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return board[1][0];
    //bottom row
    else if(board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return board[2][0];
    //1st col
    else if(board[0][0] != ' ' && board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return board[0][0];
    //2nd col
    else if(board[0][1] != ' ' && board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return board[0][1];
    //3rd col
    else if(board[0][2] != ' ' && board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return board[0][2];
    //left diag
    else if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    //right diag
    else if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    else
        return ' ';
}
