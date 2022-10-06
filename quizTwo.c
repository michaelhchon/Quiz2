//Michael Chon
//100622
//Tic Tac Toe game between 2 players or player vs computer
#include <stdio.h>

void drawBoard();
bool winCheck();

int main(void) {
    int check;
    int choice;
    int row, col;
    bool game = true;

    //prompt user for game they wish to play
    printf("WELCOME TO TIC TAC TOE!\n");
    printf("1 --- person vs person\n2 --- person vs random computer\n");
    printf("Enter your choice (1 or 2): ");
    //read information from console
    check = scanf("%d", &choice);
    if(check == 0)
    {
        printf("Error reading choice...\n");
        return 0;
    }
    //display back choice and current status of board (blank)
    printf("==========================\n");
    printf("You have entered choice %d\n", choice);
    drawBoard();
 
    //if 1 (pvp)
    if(choice == 1)
    {
        //start game loop until win conidtion is met
        while(game)
        {
            //prompt p1 for move, receive input as row, column, then place 'X'
            printf("Player 1: Make your move\n");
            scanf("%d %d", &row, &col);
            if(((row >= 1 && row <= 3) && (col >= 1 && col <= 3)))
            {
                printf("Good!\n");
                //display board
                drawBoard();
            }

            //prompt p2 for move receive input as row, column, then place 'O'
            printf("Player 2: Make your move\n");
            scanf("%d %d", &row, &col);
            if(((row >= 1 && row <= 3) && (col >= 1 && col <= 3)))
            {
                printf("Good!\n");
                //display board
                drawBoard();
            }

            //loop until EITHER 3 in a row or no more tiles to fill
            game = winCheck();
        }
    
        //display either p1 wins or p2 wins

    }

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

    return 0;
}

void drawBoard() {
    printf("The current status is:\n");
    for(int i = 0; i < 4; i++) 
    {
        printf("+-----------+\n");
        if(i < 3)
        {
            printf("|   |   |   | \n");
        }
    }
}

bool winCheck() {

}
