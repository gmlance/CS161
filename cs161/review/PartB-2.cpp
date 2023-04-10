/******************************************************
 * ** Program: PartB.cpp
 * ** Author: Shuhuai Wang
 * ** Date: 05/12/2019
 * ** Description: Homework 4
 * ******************************************************/

#include<iostream>
#include<cstring>

using namespace std;

bool is_int(string num){
	for(int i=0; i<num.length(); i++){
		if(num[i] >=48 && num[i] <= 57){
		}
		else{
			return 0;
		}
		}
	return 1;
}//Indicates if a given string is an integer

bool is_float(string num1){
	int counter = 0;
	for ( int i = 0; i<num1.length(); i++){
		if(num1[i] >= 48 && num1[i] <= 57){
		}
		else if ( num1[i] == 46){
			counter++;
		}
		else{
			return 0;
		}
	}
	if (counter <= 1){
		return 1;
	}
}//Indicates if a given string is a float

bool is_uppercase(char letter){
	if(letter >= 65 && letter <= 90){
	}
	else {
		return 0;
	}
	return 1;
	
}//Indicates if a given character is a capital letter

bool letter_present(string input){
	for(int i=0; i< input.length(); i++){
		if (input[i] >= 65 && input[i] <= 90 || input[i] >= 97 && input[i] <= 122){
		}
		else{
			return 0;
		}
	}
	return 1;
}//Indicates if the given string contains any letters.

bool numbers_present(string input1){
	for (int i=0; i<input1.length(); i++){
		if (input1[i] >= 48 && input1[i] <= 57){
		}
		else{
			return 0;
		}
		return 1;
	}
}//Indicates if the given string contains any numbers.

string to_upper(string c){
	for (int i=0; i <c.length(); i++){
		char p=c.at(i);
		int o=p;
		if (97 <= o && o <= 122){
			p = p-32;
			c[i] = p;
		}

	}
	return c;	
	
}

int main(){
	cout << "Example is bigban" << endl;
	int num = is_int("bigban");
	int num1 = is_float("bigban");
	int letter = is_uppercase('a');
	int input = letter_present("bigban");
	int input1 = numbers_present("bigban");
	string c = "bigban";


	

	if (num == 0){
		cout << "int is NO" << endl;
	}
	else if (num == 1){
		cout << "int is Yes" << endl;
	}
	if(num1 == 0){
		cout << "float is NO" << endl;
	}
	else if (num1 == 1){
		cout << "float is Yes" << endl;
	}
	if(letter == 0){
		cout << "uppercase is NO" << endl;
	}
	else if (letter == 1){
		cout << "uppercase is Yes" << endl;
	}
	if (input == 0){
		cout << "letter_present is NO" << endl;
	}
	else if (input == 1){
		cout << "letter_present is Yes" << endl;
	}
	if (input1 == 0){
		cout << "numbers_present is NO" << endl;
	}
	else if (input1 = 1){
		cout << "numbers_present is Yes" << endl;
	}
	cout << "Change uppercase: " << to_upper(c) << endl;
	return 0;
}
