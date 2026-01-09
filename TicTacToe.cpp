/*
Tic-Tac-Toe
Caitlin Ochuwa 
Started on: 12/16/25
Completed: 12/18/25
*/
#include <iostream>
#include <string>
using namespace std; 

const int ROWS = 3, COLS = 3;

void printBoard(char (&)[ROWS][COLS]);
void occupyASpace(char (&)[ROWS][COLS], int, int, char);
void checkForWinner(char (&)[ROWS][COLS], bool &);
//void checkForFullBoard(char (&)[ROWS][COLS], bool &); redundant tbh

int main()
{
    //Create game board
    char board[ROWS][COLS] = {{'-', '-', '-'},
                            {'-', '-', '-'},
                            {'-', '-', '-'} };
    string player1, player2; //Allows players to provide names
    char move; //The 'X' or the 'O'
    bool hasWon = false; //To determine if a player won (3 in a row)
    int x, y; //Used for the row and col position of the board when the players pick spaces on the board
    int turnCount = 0; //Increases after every turn. Can't exceed number of spaces on the board (9)

    //Game Introduction
    cout << "Welcome to Tic-Tac-Toe!!" << endl;
    cout << "The first player to get 3 in a row wins!" << endl;

    cout << endl;

    //Store players' names
    cout << "Player 1 enter your name: ";
    getline(cin, player1);
    cout << "Player 2 enter your name: ";
    getline(cin, player2);
    cout << endl;

    //Tells the players who has which marker
    cout << player1 << " is X's" << endl;
    cout << player2 << " is O's" << endl;

    cout << endl;

    printBoard(board); //Show players the empty board

    while(hasWon == false && turnCount <= 9){
        cout << endl; 

        //Player 1's turn
        move = 'X';
        cout << player1 << "'s turn." << endl;
        cout << "Pick a row (1, 2, or 3): ";
        cin >> x; //Stores row value
        cout << "Pick a column (1, 2, or 3): ";
        cin >> y; //Stores column value

        cout << endl;

        occupyASpace(board, x, y, move); //Adds player 1's move on the board
        turnCount++; //Increments the number of turns
        printBoard(board); //Displays player 1's move on the board
        checkForWinner(board, hasWon);

        cout << endl;

        if(hasWon == true){
            break;
        }
        if(turnCount == 9){
            cout << "It's a draw. Play again to try to win!" << endl; 
            break;
        }
        
        //Player 2's turn
        move = 'O';
        cout << player2 << "'s turn." << endl;
        cout << "Pick a row (1, 2, or 3): ";
        cin >> x; 
        cout << "Pick a column (1, 2, or 3): ";
        cin >> y;

        cout << endl;

        occupyASpace(board, x, y, move); //Adds player 2's move on the board
        turnCount++; //Increments the number of turns
        printBoard(board); //Displays player 2's move on the board
        checkForWinner(board, hasWon);
    }

    //Prints which player won depending on which move it was and if the code exited the loop because of a win
    if(hasWon == true){
        if(move == 'X'){
        cout << player1 << " wins!!" << endl;
        }
        if(move == 'O'){
        cout << player2 << " wins!!" << endl;
        }
    }
    return 0;
}

//Prints the 3x3 Tic-Tac-Toe board with every turn
void printBoard(char (&board)[ROWS][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void occupyASpace(char (&board)[ROWS][COLS], int a, int b, char c){
    bool isTaken = false;
    if(a > 0 && a < 4 && b > 0 && b < 4){ //Checks entered row and column values to make sure they will be in bounds 
        if(board[a - 1][b - 1] == '-'){
        board[a - 1][b - 1] = c; //Adds either an 'X' or 'O' if the space isnt occupied
        }
        else{
        cout << "Space already taken. Try again." << endl; //Tells player the space has been played in already
        isTaken = true; //Determines if the game must ask the user to enter new row and column values
        }
    }
    else{
        cout << "Invalid row or column value. Try again." << endl;
    }
    //Runs until the player enters valid row and column values or uses their turn in a space that isn't occupied
    while(isTaken == true || a < 0 || a > 3 || b < 0 || b > 3){
        cout << "Pick a row (1, 2, or 3): ";
        cin >> a; 
        cout << "Pick a column (1, 2, or 3): ";
        cin >> b;
        //Mini occupyASpace like statement to break out of the loop and document the player's turn
        if(a > 0 && a < 4 && b > 0 && b < 4){
            if(board[a - 1][b - 1] == '-'){
                isTaken = false;
                board[a - 1][b - 1] = c; 
            }
        }
        cout << "Try again" << endl; //To prompt the user to enter new values again
    }
}

void checkForWinner(char (&board)[ROWS][COLS], bool &hasWon){
    //Checks for a winning combinations when the board isn't blank

        /*Winning combinations (check after every turn)
        [0][0], [0][1], [0][2] top across
        [0][0], [1][0], [2][0] left down
        [0][0], [1][1], [2][2] diagonal from top left
        [1][0], [1][1], [1][2] middle across
        [2][0], [2][1], [2][2] bottom across
        [0][1], [1][1], [2][1] middle down
        [0][2], [1][2], [2][2] right down
        [0][2], [1][1], [2][0] diagonal from bottom left
        */

    if(board[0][0] != '-' && board[0][0] == board[0][1] && board[0][1] == board[0][2]){
        hasWon = true;
    }
    else if(board[0][0] != '-' && board[0][0] == board[1][0] && board[1][0] == board[2][0]){
        hasWon = true;
    }
    else if(board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        hasWon = true;
    }
    else if(board[1][0] != '-' && board[1][0] == board[1][1] && board[1][1] == board[1][2]){
        hasWon = true;
    }
    else if(board[2][0] != '-' && board[2][0] == board[2][1] && board[2][1] == board[2][2]){
        hasWon = true;
    }
    else if(board[0][1] != '-' && board[0][1] == board[1][1] && board[1][1] == board[2][1]){
        hasWon = true;
    }
    else if(board[0][2] != '-' && board[0][2] == board[1][2] && board[1][2] == board[2][2]){
        hasWon = true;
    }
    else if(board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        hasWon = true;
    }
}
