//Michael Chon
//100622
//Tic Tac Toe game between 2 players or player vs computer
#include <stdio.h>

void drawBoard();

int main(void) {
    int check;
    int choice;

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
    //start game loop until win conidtion is met

    //prompt p1 for move, receive input as row, column, then place 'X'

    //display board

    //prompt p2 for move receive input as row, column, then place 'O'
    
    //display board

    //loop until EITHER 3 in a row or no more tiles to fill

    //display either p1 wins or p2 wins

    //if 2 (pvc)
    //start game loop until win conidtion is met

    //prompt p1 for move, receive input as row, column, then place 'X'

    //display board

    //generate random number for row and column, check if existing mark, then place 'O' if nothing

    //display board

    //loop until EITHER 3 in a row or no more tiles to fill

    //display congrats or better luck next time, end program

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
