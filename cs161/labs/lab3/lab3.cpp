#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){

	srand(time(NULL));
	int number = rand() % 10;
	int input;
	int guess = 0;
	
	while(guess < 5) {
		cout << "Give a guess" << "\n";
		cin >> input;
		++guess;
	
		if(input != number) {
			cout << "incorrect" << endl;
	
		} else {
			cout << "correct" << endl;
			
		}
	}
return 0;
}
	
