/*
 * Program: Assignment 2 - Game
 * Author: Grant Lance
 * Date: 4/14/2019
 * Description: Make a game with if loops in C++
 * Input: 1 or 2 integer from user
 * Output: Win or Lose
 */
#include <iostream>  //cout & cin
#include <cstdlib> //rand/srand
#include <ctime> //time

using namespace std; // <-- to make things easier

int main(){
	srand(time(NULL));
	int action1; //declaring variables
	int action2;
	int action3;
	int action4;
	int win;
	int path;
	win = rand()%30+1; // <-- Rand helps with deciding if each game is an instant win or not
	path = rand()%20+1; // <-- Rand helps with deciding the boss
	if (path > 10){ //Chance element for fighting each boss
		cout << "you will fight boss1" << endl; //Scene 1
		cout << "boss1 raises to attack" << endl;
		cout << "Will you attack (1)  or block (2)?" << endl;
		cin >> action1;
		if (win < 8) {
			cout << "Lucky Strike! boss1 has been defeated" << endl; //Chance element for instant win
			return 0;
		} else { 
			cout << "Attack Blocked" << endl;
			cout << "boss1 raises to attack" << endl; //Scene 2
			cout << "Will you attack (1) or block (2)?" << endl;
			cin >>  action2;
		 	} if (action2 == 2) {
				cout << "You died" << endl;
				return 0;
			} else {
				cout << "Damage Done" << endl;
				cout << "boss1 raises to attack" << endl; //Scene 3
				cout << "Will you attack (1) or block (2)?" << endl;
				cin >> action2;
				}  if (action3 == 2) { 
					cout << "You died" << endl;
					return 0;
				} else { 
					cout << "Damage Done" << endl;
					cout << "boss1 stumbles after that last attack" << endl; //Scene 4
					cout << "Will you finish him (1) or escape (2)?" << endl; //No escape
					cin >>  action4;
					 } if (action4 == 2) {
						cout << "you died-no escape my dude" << endl;
						
					} else { 
					cout << "you killed boss1" << endl;
					}
	} else { //Second boss option
		cout << "you will fight boss2" << endl;
                cout << "boss2 raises to attack" << endl; //Scene 1
                cout << "Will you attack (1)  or block (2)?" << endl;
                cin >> action1;
                if (win < 8) {
                        cout << "Lucky Strike! boss2 has been defeated" << endl; //Chance for instant win
                        return 0;
                } else {
                        cout << "Attack Blocked" << endl;
                        cout << "boss1 raises to attack" << endl; //Scene 2
                        cout << "Will you attack (1) or block (2)?" << endl;
                        cin >>  action2;
                        } if (action2 == 1) {
                                cout << "You died" << endl;
                                return 0;
                        } else {
                                cout << "Damage Done" << endl;
                                cout << "boss1 raises to attack" << endl;
                                cout << "Will you attack (1) or block (2)?" << endl; //Scene 3
                                cin >> action2;
                                }  if (action3 == 1) {
                                        cout << "You died" << endl;
                                        return 0;
                                } else {
                                        cout << "Damage Done" << endl;
                                        cout << "boss1 stumbles after that last attack" << endl;
                                        cout << "Will you finish him (1) or escape (2)?" << endl; //Scene 4
                                        cin >>  action4;
                                         } if (action4 == 2) {
                                                cout << "you died-no escape my dude" << endl;

                                        } else {
                                        cout << "you killed boss1" << endl;
                                        }
return 0;

}
}
	
