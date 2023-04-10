/*********************************************************************
 ** Program Filename: FunctionLibrary.cpp
 ** Author: Brynn DeVaan
 ** Date: 05/12/19
 ** Description: 6 different functions that detect whether or not the
		 user's input is valid.
 ** Input: strings (letters and numbers), char, int, float
 ** Output: boolean - either 1 or 0, or returning a string
*********************************************************************/

#include <iostream> //Library for printing and accepting input
#include <string> //Library to interpret strings

using namespace std; //Allows cout, cin, and other identifiers to function



/*********************************************************************
 ** Function: is_int
 ** Description: Tests to see if user input is a number. If it is,
		 return true (1). If not, return false (0).
 ** Parameters: The user input has to be a string
 ** Pre-Conditions: The user enters a string 
 ** Post-Conditions: The computer outputs the boolean return type
*********************************************************************/
bool is_int(string num)
{	
	bool input;

	cout << "[is_int] If input is a number, return true (1). Please enter in a string: ";
	cin >> num;

	for(int i = 0; i < num.length(); i++) //For loop to run through all symbols in the string
	{
		if(num[i] >= 48 && num[i] <= 57) //If any part contains numbers 0-9, input is true
		{	
			input = true;	
		}
		else //If there is anything other than a number occuring at any time, input is false
		{
			input = false;
			return false;
		}
	}
	return true;
}



/*********************************************************************
 ** Function: is_float
 ** Description: Tests to see if user input is a float. If it is,
		 return true (1). If not, return false (0).
 ** Parameters: The user input has to be a string
 ** Pre-Conditions: The user enters a string
 ** Post-Conditions: The computer outputs the boolean return type
*********************************************************************/
bool is_float(string num)
{
	int NumOfTimes = 0;

	cout << "[is_float] If input contains a period, return true (1). Please enter in a string: ";
	cin >> num;
	
	for(int i = 0; i < num.length(); i++) //For loop to run through all symbols in the string
	{
		if(num[i] >= 48 && num[i] <= 57) //If any part contains numbers 0-9, add 1 to the value of NumOfTimes
		{
			NumOfTimes = NumOfTimes + 1; 	
		}
		else if(num[i] == '.') //If any part contains a period, add 100 to the value of NumOfTimes
		{
			NumOfTimes = NumOfTimes + 100;	
		}
		else if(num[i] != '.' || (num[i] < 48 || num[i] > 57)) //If there are no numbers or periods, return false
		{
			return false;
		}
	}
	
	if(NumOfTimes > 100 && NumOfTimes < 200) //If there is at least one number and no more than one period, return true
	{
		return true;
	}
	else
	{
		return false;
	}
}



/*********************************************************************
 ** Function: is_uppercase
 ** Description: Tests to see if user input is an uppercase char. If
		 it is, return true (1). If not, return false (0).
 ** Parameters: The user input has to be one char
 ** Pre-Conditions: The user enters a char
 ** Post-Conditions: The computer outputs the boolean return type
*********************************************************************/
bool is_uppercase(char letter)
{
	cout << "[is_uppercase] If input is uppercase, return true (1). Please enter in a char: ";
	cin >> letter;
	
	if(letter >= 65 && letter <= 90) //If char is an uppercase letter, return true
	{
		return true;
	}
	else
	{
		return false;
	}
}



/*********************************************************************
 ** Function: letters_present
 ** Description: Tests to see if user input contains any letters -
		 uppercase or lowercase. If it does, return true (1).
		 If not, return false (0).
 ** Parameters: The user input has to be a string
 ** Pre-Conditions: The user enters a string
 ** Post-Conditions: The computer outputs the boolean return type
*********************************************************************/
bool letters_present(string input)
{
	cout << "[letters_present] If input contains letters, return true (1). Please enter in a string: ";
	cin >> input;
	
	for(int i = 0; i < input.length(); i++) //For loop to run through all symbols in the string
	{
		if((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122)) //if there are letters, return true
		{
			return true;
		}
	}
	return false;
}



/*********************************************************************
 ** Function: numbers_present
 ** Description: Tests to see if user input contains any numbers in a 
		 string. If it does, return true (1). If not, return
		 false (0). 
 ** Parameters: The user input has to be a string
 ** Pre-Conditions: The user enters a string
 ** Post-Conditions: The computer outpits the boolean return type
*********************************************************************/
bool numbers_present(string input)
{
	cout << "[numbers_present] If input contains numbers, return true (1). Please enter in a string: ";
	cin >> input;

	for(int i = 0; i < input.length(); i++) //For loop to run through all symbols in the string
	{
		if(input[i] >= 48 && input[i] <= 57) //If there are numbers in the string at any time, return true
		{
			return true;
		}
	}
	return false;
}



/*********************************************************************
 ** Function: to_upper
 ** Description: Tests to see if user input contains any lowercase
		 letters in a string. If true, convert those into
		 uppercase letters and print out updated string. If 
		 false, do nothing, but still print out the user's 
		 initial string.
 ** Parameters: The user input has to be a string
 ** Pre-Conditions: The user enters a string
 ** Post-Conditions: The computer outputs an updated string
*********************************************************************/
string to_upper(string input)
{
	cout << "[to_upper] Capatilizes all lowercase letters. Please enter in a string: ";
	cin >> input;
	
	for(int i = 0; i < input.length(); i++) //For loop to run through all symbols in the string
	{
		if(input[i] >= 97 && input[i] <= 122) //If there are lowercase letters
		{
			input[i] = input[i] - 32; //Switch them to uppercase letters
		}
	}
	return input;
}

/*********************************************************************
 ** Function: main
 ** Description: Prints out possible functions user can choose from as
		 well as calls those specified functions.
 ** Parameters: User has to enter in a number between 1-6
 ** Pre-Conditions: User enters in number
 ** Post-Conditions: Specific function gets called
*********************************************************************/
int main()
{
	//Data types, varies for each function
	int choice;
	char letter;
	string num;
	string input;

	cout << "\n\n[is_int] Indicates if a given string is an integer = 1"
	     << "\n[is_float] Indicates if a given string is a float = 2"
      	     << "\n[is_uppercase] Indicates if a given character is a capital letter = 3"
	     << "\n[letters_present] Indicates if the given string contains any letters = 4"
	     << "\n[numbers_present] Indicates if the given string contains any numbers = 5"	
	     << "\n[to_upper] Capitalizes all letters in a given string and leave all non-letter characters unchanged = 6" << endl;
	cout << "\nPlease enter the number corresponding to the function in which you'd like to test: ";
	cin >> choice; //Let's user choose a function they want to test

	if(choice == 1)
	{
		cout << is_int(num) << endl; //Function call
	}
	else if(choice == 2)
	{
		cout << is_float(num) << endl; //Function call
	}
	else if(choice == 3)
	{
		cout << is_uppercase(letter) << endl; //Function call
	}
	else if(choice == 4)
	{
		cout << letters_present(input) << endl; //Function call
	}
	else if(choice == 5)
	{
		cout << numbers_present(input) << endl; //Function call
	}
	else if(choice == 6)
	{	
		cout << to_upper(input) << endl; //Function call
	}
	
}
