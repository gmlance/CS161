#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){

	srand(time(NULL));
	int number = 30;
	int input;
	int guess = 1;
	int diff = 5;	
	
	while(diff < 10)
	{
		cout << "Give a guess" << "\n";
		cin >> input;
		diff = number - input;
		int diff = abs(number-input);
	}
	if(diff >= 10 || diff > number)
		{
			cout << "incorrect" << endl;
			return 0;
	
	} else	{
		cout << "try again" << endl;
			
		}
	return 0;
}
	
