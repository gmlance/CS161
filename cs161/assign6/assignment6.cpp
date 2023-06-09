// minesweeper

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <cstdio>
#include <stdio.h>
#include <string.h>

using namespace std; 

#define BEGINNER 0 
#define INTERMEDIATE 1 
#define ADVANCED 2 
#define MAXSIDE 25 
#define MAXMINES 99 
#define MOVESIZE 526 // (25 * 25 - 99) 

int SIDE ; // side length of the board 
int MINES ; // number of mines on the board 

bool isValid(int row, int col) 
{ 
	return (row >= 0) && (row < SIDE) && 
		(col >= 0) && (col < SIDE); 
} 

// A Utility Function to check whether given cell (row, col) 
// has a mine or not. 
bool isMine (int row, int col, char board[][MAXSIDE]) 
{ 
	if (board[row][col] == '*') 
		return (true); 
	else
		return (false); 
} 

// A Function to get the user's move 
void makeMove(int *x, int *y) 
{ 
	// Take the input move 
	printf("Enter your move, (row, column) -> "); 
	scanf("%d %d", x, y); 
	return; 
} 

// A Function to print the current gameplay board 
void printBoard(char myBoard[][MAXSIDE]) 
{ 
	int i, j; 

	printf (" "); 

	for (i=0; i<SIDE; i++) 
		printf ("%d ", i); 

	printf ("\n\n"); 

	for (i=0; i<SIDE; i++) 
	{ 
		printf ("%d ", i); 

		for (j=0; j<SIDE; j++) 
			printf ("%c ", myBoard[i][j]); 
		printf ("\n"); 
	} 
	return; 
} 

// A Function to count the number of 
// mines in the adjacent cells 
int countAdjacentMines(int row, int col, int mines[][2], 
					char realBoard[][MAXSIDE]) 
{ 

	int i; 
	int count = 0; 

		if (isValid (row-1, col) == true) 
		{ 
			if (isMine (row-1, col, realBoard) == true) 
			count++; 
		} 

		if (isValid (row+1, col) == true) 
		{ 
			if (isMine (row+1, col, realBoard) == true) 
			count++; 
		} 

		if (isValid (row, col+1) == true) 
		{ 
			if (isMine (row, col+1, realBoard) == true) 
			count++; 
		} 

		if (isValid (row, col-1) == true) 
		{ 
			if (isMine (row, col-1, realBoard) == true) 
			count++; 
		} 

		if (isValid (row-1, col+1) == true) 
		{ 
			if (isMine (row-1, col+1, realBoard) == true) 
			count++; 
		} 

		if (isValid (row-1, col-1) == true) 
		{ 
			if (isMine (row-1, col-1, realBoard) == true) 
			count++; 
		} 

		if (isValid (row+1, col+1) == true) 
		{ 
			if (isMine (row+1, col+1, realBoard) == true) 
			count++; 
		} 

		if (isValid (row+1, col-1) == true) 
		{ 
			if (isMine (row+1, col-1, realBoard) == true) 
			count++; 
		} 

	return (count); 
} 

// A Recursive Fucntion to play the game 
bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE], 
			int mines[][2], int row, int col, int *movesLeft) 
{ 

	// Base Case 
	if (myBoard[row][col] != '-') 
		return (false); 

	int i, j; 

	if (realBoard[row][col] == '*') 
	{ 
		myBoard[row][col]='*'; 

		for (i=0; i<MINES; i++) 
			myBoard[mines[i][0]][mines[i][1]]='*'; 

		printBoard (myBoard); 
		printf ("\nYou lost!\n"); 
		return (true) ; 
	} 

	else
	{ 
		int count = countAdjacentMines(row, col, mines, realBoard); 
		(*movesLeft)--; 

		myBoard[row][col] = count + '0'; 

		if (!count) 
		{ 

			if (isValid (row-1, col) == true) 
			{ 
				if (isMine (row-1, col, realBoard) == false) 
				playMinesweeperUtil(myBoard, realBoard, mines, row-1, col, movesLeft); 
			} 

			if (isValid (row+1, col) == true) 
			{ 
				if (isMine (row+1, col, realBoard) == false) 
					playMinesweeperUtil(myBoard, realBoard, mines, row+1, col, movesLeft); 
			} 

			if (isValid (row, col+1) == true) 
			{ 
				if (isMine (row, col+1, realBoard) == false) 
					playMinesweeperUtil(myBoard, realBoard, mines, row, col+1, movesLeft); 
			} 

			if (isValid (row, col-1) == true) 
			{ 
				if (isMine (row, col-1, realBoard) == false) 
					playMinesweeperUtil(myBoard, realBoard, mines, row, col-1, movesLeft); 
			} 

			if (isValid (row-1, col+1) == true) 
			{ 
				if (isMine (row-1, col+1, realBoard) == false) 
					playMinesweeperUtil(myBoard, realBoard, mines, row-1, col+1, movesLeft); 
			} 

			if (isValid (row-1, col-1) == true) 
			{ 
				if (isMine (row-1, col-1, realBoard) == false) 
					playMinesweeperUtil(myBoard, realBoard, mines, row-1, col-1, movesLeft); 
			} 

			if (isValid (row+1, col+1) == true) 
			{ 
				if (isMine (row+1, col+1, realBoard) == false) 
					playMinesweeperUtil(myBoard, realBoard, mines, row+1, col+1, movesLeft); 
			} 


			if (isValid (row+1, col-1) == true) 
			{ 
				if (isMine (row+1, col-1, realBoard) == false) 
					playMinesweeperUtil(myBoard, realBoard, mines, row+1, col-1, movesLeft); 
			} 
		} 

		return (false); 
	} 
} 

// A Function to place the mines randomly 
void placeMines(int mines[][2], char realBoard[][MAXSIDE]) 
{ 
	bool mark[MAXSIDE*MAXSIDE]; 

	memset (mark, false, sizeof (mark)); 

	for (int i=0; i<MINES; ) 
	{ 
		int random = rand() % (SIDE*SIDE); 
		int x = random / SIDE; 
		int y = random % SIDE; 

		if (mark[random] == false) 
		{ 
			mines[i][0]= x; 
			mines[i][1] = y; 

			realBoard[mines[i][0]][mines[i][1]] = '*'; 
			mark[random] = true; 
			i++; 
		} 
	} 

	return; 
} 

void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE]) 
{ 

	srand(time (NULL)); 

	for (int i=0; i<SIDE; i++) 
	{ 
		for (int j=0; j<SIDE; j++) 
		{ 
			myBoard[i][j] = realBoard[i][j] = '-'; 
		} 
	} 

	return; 
} 

void cheatMinesweeper (char realBoard[][MAXSIDE]) 
{ 
	printf ("The mines locations are-\n"); 
	printBoard (realBoard); 
	return; 
} 

void replaceMine (int row, int col, char board[][MAXSIDE]) 
{ 
	for (int i=0; i<SIDE; i++) 
	{ 
		for (int j=0; j<SIDE; j++) 
			{ 

				if (board[i][j] != '*') 
				{ 
					board[i][j] = '*'; 
					board[row][col] = '-'; 
					return; 
				} 
			} 
	} 
	return; 
} 

void playMinesweeper () 
{ 

	bool gameOver = false; 


	char realBoard[MAXSIDE][MAXSIDE], myBoard[MAXSIDE][MAXSIDE]; 

	int movesLeft = SIDE * SIDE - MINES, x, y; 
	int mines[MAXMINES][2]; 

	initialise (realBoard, myBoard); 


	placeMines (mines, realBoard); 


	int currentMoveIndex = 0; 
	while (gameOver == false) 
	{ 
		printf ("Current Status of Board : \n"); 
		printBoard (myBoard); 
		makeMove (&x, &y); 
 
		if (currentMoveIndex == 0) 
		{ 
			// If the first move itself is a mine 
			// then we remove the mine from that location 
			if (isMine (x, y, realBoard) == true) 
				replaceMine (x, y, realBoard); 
		} 

		currentMoveIndex ++; 

		gameOver = playMinesweeperUtil (myBoard, realBoard, mines, x, y, &movesLeft); 

		if ((gameOver == false) && (movesLeft == 0)) 
		{ 
			printf ("\nYou won !\n"); 
			gameOver = true; 
		} 
	} 
	return; 
} 

// A Function to choose the difficulty level 
// of the game 
void chooseDifficultyLevel () 
{ 
	cout << "how big of a square would you like(entering 9 will result in a 9 by 9 square)?" << endl;
       	cin >> SIDE;	
	cout << "how many mines do you want?" << endl;
	cin >> MINES;
} 

// Driver Program to test above functions 
int main() 
{ 
	chooseDifficultyLevel (); 

	playMinesweeper (); 

	return (0); 
}
