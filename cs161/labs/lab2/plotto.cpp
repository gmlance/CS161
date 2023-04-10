#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
	srand(time(NULL));
	int number = rand() % 7;
	int input;

	cout << "Give a guess: ";
	cin >> input;
	
	if(input != number){
		cout << "Guess is incorrect" << endl;
	} else{ cout << "Correct!" << endl; 
}

}
