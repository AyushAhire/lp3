#include <bits/stdc++.h>
using namespace std;
bool solutionFound = false; // Flag to indicate if a solution has been found

// A function to print a solution
void print(int board[][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(board[i][j]) cout<<"Q"<<" ";
            else cout<<"."<<" ";
        }
        cout << endl;
    }
    cout << "-----------------\n";
}

// Function to check whether a position is valid or not
bool isValid(int board[][8], int row, int col) {
    // Loop to check horizontal positions
    for (int i = col; i >= 0; i--) {
        if (board[row][i])
            return false;
    }
    int i = row, j = col;

    // Loop to check the upper left diagonal
    while (i >= 0 && j >= 0) {
        if (board[i][j])
            return false;
        i--;
        j--;
    }
    i = row;
    j = col;

    // Loop to check the lower left diagonal
    while (i < 8 && j >= 0) {
        if (board[i][j])
            return false;
        i++;
        j--;
    }
    return true;
}

// Function to check all possible solutions
void ninjaQueens(int board[][8], int currentColumn) {
    if (currentColumn >= 8 || solutionFound) // Stop if solution is found
        return;

    // Loop to cover all rows in the current column
    for (int i = 0; i < 8; i++) {
        if (isValid(board, i, currentColumn)) {
            board[i][currentColumn] = 1;
            if (currentColumn == 7) { // Found a solution
                print(board);
                solutionFound = true; // Set the flag to true
                return;
            }
            // Recursively calling the function
            ninjaQueens(board, currentColumn + 1);
            // Backtracking
            board[i][currentColumn] = 0;
        }
    }
}

int main() {
    // Initial board situation
    int row, column;
    int board[8][8] = {0};
                       
    cout<<"Enter rows and columns to place queen first: ";
    cin>>row>>column;
    board[row][column] = 1;
                       
    ninjaQueens(board, 0);

    return 0;
}
