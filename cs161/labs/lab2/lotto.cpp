#include <iostream>

using namespace std;

int main(){

	int lotto_number = 7;
	int input;

	cout << "Give a guess: ";
	cin >> input;
	
	if(input != lotto_number){
		cout << "Guess is incorrect" << endl;
	} else{ cout << "Correct!" << endl; 
}

}
