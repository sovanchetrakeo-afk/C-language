#include<stdio.h>
#include<stdbool.h>
#define PLAYER_1_WON 1
#define PLAYER_2_WON 2
#define DRAW_GAME 3
#define WIN_COUNT 5 // Number of symbols needed to win
#define GAME_SIZE 5 // Game row and columns
#define PLAYER_1_SYMBOL 'X'
#define PLAYER_2_SYMBOL 'O'
bool isValidMove(int row, int col) {
   if(row < 0 || row >= GAME_SIZE || col < 0 || col >= GAME_SIZE) {
    return false; // Move is out of bounds
    }
    return true; // Move is valid
    
}
void makeMove(int row,int col,bool isPlayer1) {
    if(isValidMove(row,col)){
      bool isPlayer1 = true;
    }else {
    bool isPlayer1 = false;
    };
  
}
// Display the board
void displayBoard(char board[GAME_SIZE][GAME_SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < GAME_SIZE; i++) {
        for (int j = 0; j < GAME_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
// Player 1 move
void EnterPlayer1Move(char board[GAME_SIZE][GAME_SIZE]) {
    int row, col;
    printf("Player 1 (X) turn. \n");
    printf("Enter row(0-4): ");
    scanf("%d", & row);
    printf("Enter column(0-4):");
    scanf("%d", &col);
    // Validate move
    if (row >= 0 && row < GAME_SIZE && col >= 0 && col < GAME_SIZE && board[row][col] == '.') {
        board[row][col] = PLAYER_1_SYMBOL;
    } 
}

// Player 2 move
void EnterPlayer2Move(char board[GAME_SIZE][GAME_SIZE]) {
    int row, col;
    printf("Player 2 (O) turn.\n");
     printf("Enter row(0-4):");
    scanf("%d", & row);
    printf("Enter column(0-4):");
    scanf("%d", &col);
    

    // Validate move
    if (row >= 0 && row < GAME_SIZE && col >= 0 && col < GAME_SIZE && board[row][col] == '.') {
        board[row][col] = PLAYER_2_SYMBOL;
    } 
}
int  checkGame(char board[GAME_SIZE][GAME_SIZE]) {
    // Check rows
    for (int i = 0; i < GAME_SIZE; i++) {
        int countX = 0, countO = 0;
        for (int j = 0; j < GAME_SIZE; j++) {
            if (board[i][j] == PLAYER_1_SYMBOL){ 
                countX++;
            }    
            if (board[i][j] == PLAYER_2_SYMBOL){
                countO++;
            }    
        }
        if (countX == WIN_COUNT){
             return PLAYER_1_WON;
        }     
        if (countO == WIN_COUNT){
             return PLAYER_2_WON;
        }    
    }

    // Check columns
    for (int j = 0; j < GAME_SIZE; j++) {
        int countX = 0, countO = 0;
        for (int i = 0; i < GAME_SIZE; i++) {
            if (board[i][j] == PLAYER_1_SYMBOL){
                 countX++;
            }    
            if (board[i][j] == PLAYER_2_SYMBOL){
                 countO++;
            }    
        }
        if (countX == WIN_COUNT){
             return PLAYER_1_WON;
        }     
    if (countO == WIN_COUNT){
        return PLAYER_2_WON;
    }    
}

    // Check diagonals
    int countX = 0, countO = 0;
    for (int i = 0; i < GAME_SIZE; i++) {
        if (board[i][i] == PLAYER_1_SYMBOL){
             countX++;
        }     
        if (board[i][i] == PLAYER_2_SYMBOL){
             countO++;
        }    
    }
    if (countX == WIN_COUNT){
         return PLAYER_1_WON;
    }    
    if (countO == WIN_COUNT){
         return PLAYER_2_WON;
    }
    countX = 0, countO = 0;
    for (int i = 0; i < GAME_SIZE; i++) {
        if (board[i][GAME_SIZE - 1 - i] == PLAYER_1_SYMBOL){
             countX++;
        }    
        if (board[i][GAME_SIZE - 1 - i] == PLAYER_2_SYMBOL){
         countO++;
        } 
    }
    if (countX == WIN_COUNT){
         return PLAYER_1_WON;
    }    
    if (countO == WIN_COUNT){
         return PLAYER_2_WON;
    }     

    // If no winner, it's a draw
    return DRAW_GAME;
}


int main() {
    char board[GAME_SIZE][GAME_SIZE];

    // Initialize the board with dots
    for (int i = 0; i < GAME_SIZE; i++) {
        for (int j = 0; j < GAME_SIZE; j++) {
            board[i][j] = '.';
        }
    }
    displayBoard(board); // Show initial board
    for(int i = 0; i < GAME_SIZE; i++) {
        for (int j = 0; j < GAME_SIZE; j++) {
             makeMove(i, j, 1); 
             EnterPlayer1Move(board);
             if(isValidMove) {
                printf("Player move Invalid and Player2 has the right to draw first\n");
            }else {
                printf("Player move valid");
            }   
             displayBoard(board); // Show updated board
            if (checkGame(board) == PLAYER_1_WON) {
                    printf("Player 1 (X) wins!\n");
                    return 0;
            }
             EnterPlayer2Move(board);
             if(isValidMove) {
                printf("Player move Invalid and Player1 has the right to draw first\n");
            }else {
                printf("Player move valid");
            }   
             displayBoard(board); // Show updated board
            if (checkGame(board) == PLAYER_2_WON) {
                    printf("Player 2 (O) wins!\n");
                    return 0;
        }
    }

}  


    return 0;
}
