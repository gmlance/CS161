/* Program Filename: Assignment 3 Code - Nim
 * Author: Grant Lance
 * Date: 4/29/19
 * Description: Nim - the game
 */
#include <iostream> //cin &cout
#include <ctime> //time for rand
#include <cmath> // for math
#include <cstdlib> // for rand
#include <stdio.h> //atoi
#include <stdlib.h> //atoi

using namespace std;

char score(char a, int b) { //print the current score
	cout << "pile " << a << " has " << b << " counters left" << endl << endl;
}

int pullfrom(int h, int j) { //handle the player choices and math
	int npile;
	npile = h - j;
	return npile;
}

int main() { //the game
	srand(time(NULL)); //start rand
	cout << "Welome to Nim - the game!" << endl; //explain the game
	cout << "Three piles will be made." << endl;
	cout << "Each pile will have a random number of counters in it" << endl;
	cout << "Take turns (2 players) removing 1-3 counters from each pile" << endl;
	cout << "Whichever player removes the last counter loses!" << endl;

	string pl1;
	string pl2;

	cout << "Player 1 enter your name" << endl; //player names
	getline(cin, pl1);
	cout << "Player 2 enter your name" << endl;
	getline(cin, pl2);

	int a; //pile values
	int b;
	int c;
	int choice;
	char buffer[256];
	int sub = 0;
	char A = 'A'; //pile names
	char B = 'B';
	char C = 'C';
	int x;
	int y;
	int playsa = 0; //to keep track for who wins
	int playsb = 0;

	a = rand() % 10 + 3;
	b = rand() % 10 + 3;
	c = rand() % 10 + 3;
	score(A, a);
	score(B, b);
	score(C, c);
	
	while (a + b + c  >=  1 ) { //main play
		cout << pl1 << " pick your pile" << endl; //player 1 pick and pull
		cout << "Enter 1, 2, or 3" <<endl;
		cin >> choice;
		cout << "Take 1, 2, or 3 counters from pile " << choice << " ?"  << endl;
		cin >> sub;
		playsa = playsa + 1;
		if( sub > 3 || sub < 1)	{
			cout << "bad input restart" << endl;
			return 0;	
		}
		if(choice = 'a') {
			a = pullfrom(a, sub); 
		}
		else if (choice == 1) { //if pile 1 or A
			a = pullfrom(a, sub);
		}
		else if(choice = 'b') {
			b = pullfrom(b, sub);
		}
		else if(choice == 2) { //if pile 2 or B
			b = pullfrom(b, sub);
		}
		else if(choice = 'c') {
			c = pullfrom(c, sub);
		}
		else if(choice == 3) { //if pile 3 or C
			c = pullfrom(c, sub);
		}
		else {
			cout << "You got skipped for bad input!" << endl;
			cout << "You can enter 1, 2, 3, a, b, or c for a pile" << endl;
			cout << "You can pull 1, 2, or 3 counters from a pile" << endl << endl; 
		}
		score(A, a); //post the score for player 2
		score(B, b);
		score(C, c);

		if ((a + b + c) == 1) {
			cout << pl1 << " Wins!" << endl;
			return 0;
		
		}

		cout <<	pl2 << " pick your pile" << endl; //player 2 pick and pull
		cout << "Enter 1, 2, or 3" << endl;
		cin >> choice;
		cout << "Take 1, 2, or 3 counters from pile " << choice << " ?" << endl;
		cin >> sub;
		playsb = playsb + 1;
		
		if(sub > 3 || sub < 1) {
			cout << "bad input restart" << endl;
		}
		if(choice = 'a') {
			a = pullfrom(a, sub);
		}
		else if(choice == 1) {
			a = pullfrom(a, sub);
		}
		else if(choice = 'b') {
			b = pullfrom(b, sub);
		}
		else if(choice == 2) {
			b = pullfrom(b, sub);
		} 
		else if(choice = 'c') {
			c = pullfrom(c, sub);
		}
		else if(choice == 3) {
			c = pullfrom(c, sub);
		  
		} else {
			cout << "You got skipped for bad input!" << endl;
			cout << "You can enter 1, 2, 3, a, b, or c for a pile" << endl;
			cout << "You can pull 1, 2, or 3 counters from a pile" << endl << endl;
		}
		score(A, a); //show score again
		score(B, b);
		score(C, c);
		
		if ((a + b + c) == 1) {
			cout << pl2 << " Wins!" <<  endl;
			return 0;
		}

	}

	if( playsa > playsb ) {
		cout << pl1 << " Wins!" << endl;
	}
	else if( playsb = playsa ) {
		cout << pl2 << " Wins!" << endl;
	}
	else {
		cout << "Game Over" << endl;
	}
return 0;
}
