/*********************************************************************
 ** Program Filename: Hangman4.cpp
 ** Author: Brynn DeVaan
 ** Date: 05/12/19
 ** Description: Plays the game of hangman, where user gets 7 attempts
		 to guess the word 'Beaver'. Whether right or wrong,
		 each guess counts as an attempt. Program also looks
		 for invalid input.
 ** Input: Letters that the user guesses
 ** Output: Updated layouts of the word, how many attempts are left, 
	    which words were incorrect, and if the user won or lost.
*********************************************************************/

#include <iostream> //Library for printing and accepting input
#include <string> //Library to interpret strings
#include <limits> //Used to prevent loops when detecting invalid input

using namespace std; //Allows cout, cin, and other identifiers to function



/*********************************************************************
 ** Function: InvalidInput
 ** Description: Detects if user's choice is only one letter. If not, 
		 it reprompts the user until they enter in something
		 valid.
 ** Parameters: User can input anything - computer will check it
 ** Pre-Conditions: User should input a value
 ** Post-Conditions: Computer will output a correct answer via string
*********************************************************************/
string InvalidInput(string UserChoice)
{
	cin >> UserChoice; 

	for(int i = 0; i < UserChoice.length(); i++) //For loop to run through all symbols in the string
	{
		//If user input length is greater than 1 OR not a letter, enter while loop and keep on asking user for a correct input
		if((UserChoice[i] <= 64 || (UserChoice[i] >= 91 && UserChoice[i] <= 96) || UserChoice[i] >= 123) || UserChoice.length() > 1)
		{
			while((UserChoice[i] <= 64 || (UserChoice[i] >= 91 && UserChoice[i] <= 96) || UserChoice[i] >= 123) || UserChoice.length() > 1)
			{
				cout << "Invalid Input. You can only enter one letter. Please try again: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> UserChoice;
			}
		}
	}
	cout << "You have chosen the letter " << UserChoice << "." << endl;

return UserChoice;
}



/*********************************************************************
 ** Function: CorrectLetter
 ** Description: Computer detects if user's guess is the correct
		 letter. If it is, it changes the '-' to the letter. 
		 If incorrect, the computer returns that letter.
 ** Parameters: User enters in one letter
 ** Pre-Conditions: User guesses a letter
 ** Post-Conditions: Computer detects whether letter is correct or
		     not, and updates accordingly.
*********************************************************************/
string CorrectLetter(char CharUserChoice, string Word, string Hyphen)
{
	//If user choice (now a character because we know it's one letter due to invalid input) is either B, E, A, V, or R (uppercase or lowercase)
	if(CharUserChoice == 65 || CharUserChoice == 66 || CharUserChoice == 69 || CharUserChoice == 82 || CharUserChoice == 86 || CharUserChoice == 97 || 
	CharUserChoice == 98 || CharUserChoice == 101 || CharUserChoice == 114 || CharUserChoice == 118)
	{
		CharUserChoice = tolower(CharUserChoice); //Change any uppercase input into lowercase

		cout << "\nThat is one of the letters!" << endl;

		for(int i = 0; i < Word.length(); i++) //For loop to run through the word 'Beaver'
		{
			if(Word[i] == CharUserChoice)
			{
				Hyphen[i] = Word[i]; //Change '-' to whichever letter user chose (b, e, a, v, or r)		
			}
		}
		cout << "\n " << Hyphen << "\n" << endl; //Print out updated hyphens/words
	}
return Hyphen;
}



/*********************************************************************
 ** Function: IncorrectLetter
 ** Description: Computer detects if user's guess is incorrect. If it
		 is, computer puts incorrect letter into the 'Missed'
		 pile - a string.
 ** Parameters: User enters in one letter
 ** Pre-Conditions: User guesses a letter
 ** Post-Conditions: Computer detects whether letter is correct or
		     not, and updates accordingly.
*********************************************************************/
string IncorrectLetter(char CharUserChoice, string Hyphen, int Attempts, string Misses)
{
	//If user choice is not B, E, A, V, or R (uppercase or lowercase), indicate that that isn't a correct letter
	if(CharUserChoice != 65 && CharUserChoice != 66 && CharUserChoice != 69 && CharUserChoice != 82 && CharUserChoice != 86 && CharUserChoice != 97 && 
	CharUserChoice != 98 && CharUserChoice != 101 && CharUserChoice != 114 && CharUserChoice != 118)
	{
		cout << "\nSorry, that wasn't one of the letters." << endl;	
		
		if(Misses[0] == ' ') //Put first incorrect attempt into array 0
		{
			Misses[0] = CharUserChoice;
		}
		else if(Misses[0] != ' ' && Misses[2] == ' ') //Put second incorrect attempt into array 2 
		{
			Misses[2] = CharUserChoice;
		}
		else if(Misses[2] != ' ' && Misses[4] == ' ') //Put third incorrect attempt into array 4
		{
			Misses[4] = CharUserChoice;
		}
		else if(Misses[4] != ' ' && Misses[6] == ' ') //Put fourth incorrect attempt into array 6
		{
			Misses[6] = CharUserChoice;
		}
		else if(Misses[6] != ' ' && Misses[8] == ' ') //Put fifth incorrect attempt into array 8
		{
			Misses[8] = CharUserChoice;
		}
		else if(Misses[8] != ' ' && Misses[10] == ' ') //Put sixth incorrect attempt into array 10
		{
			Misses[10] = CharUserChoice;
		}
		else if(Misses[10] != ' ' && Misses[12] == ' ') //Put seventh incorrect attempt into array 12
		{
			Misses[12] = CharUserChoice;
		}
		
		cout << "Misses: " << Misses << endl; //Print out string Misses
		cout << "\n " << Hyphen << endl; //Print out hyphens/words
	}
return Misses;
}



/*********************************************************************
 ** Function: main
 ** Description: Prints out instructions, loops through called
		 functions, indicates how many attempts the user has
		 left, and indicates if the user was a winner or loser.
 ** Parameters: Data types used in other functions have to be declared
		here
 ** Pre-Conditions: Data types need to be declared
 ** Post-Conditions: Game is run through, ultimately printing out
		     whether user has lost or won.
*********************************************************************/
int main()
{
	string Word = "beaver";
	string Hyphen = string(Word.size(), '-'); //Number of hyphens are equal to the amount of letters in 'beaver'
	int Attempts = Word.size() + 1;	//Number of attempts are equal to amount of letter in 'beaver' plus 1
	string UserChoice;
	string Misses = string((Word.size() + 7), ' ');	//String misses has 13 spots (arrays from 0-12) initially printed with spaces

	//Instructions
	cout << "\nWelcome to Hangman! \n\n###############\nInstructions: A hidden word has been chosen. You have " << Attempts << " attempts to guess this \n" 
	<< Word.size() << " letter long word. You may only enter in one letter at a time. Each guess, \nwhether right or wrong, will be interpreted as one attempt." 
	<< "\n###############" << endl;
	cout << "\n ------" << endl;

	while(Attempts > 0) //Loop until all attempts are used
	{
		//If all letters are found before all attempts are used up, indicate user won and end game
		if(Hyphen[0] == 'b' && Hyphen[1] == 'e' && Hyphen[2] == 'a' && Hyphen[3] == 'v' && Hyphen[4] == 'e' && Hyphen[5] == 'r')	
		{
			cout << "Congratulations! You figured out the word!" << endl;
			return 0;
		}

		
		cout << "\nWhat is your guess? ";

		UserChoice = InvalidInput(UserChoice); //Call invalid input
		char CharUserChoice = UserChoice[0]; //After valid input, switch user's string input to a char input, since we know it's only one letter

		Hyphen = CorrectLetter(CharUserChoice, Word, Hyphen); //Call CorrectLetter function
		Misses = IncorrectLetter(CharUserChoice, Hyphen, Attempts, Misses); //Call IncorrectLetter function

		Attempts = Attempts - 1; //Take away an attempt every loop
		cout << "\nAttempts Left: " << Attempts << endl;
	}
	
	for(int i = 0; i < Hyphen.length(); i++) //If all attempts are gone, and word hasn't been solved, indicate user has lost
	{
		if(Hyphen[i] == '-')
		{
			cout << "Bummer, you ran out of attempts. The word was 'Beaver'." << endl;
			break;
		}
	}
 
	//If all attempts are gone, but user has solved the word, indicate user has won
	if(Attempts == 0 && (Hyphen[0] == 'b' && Hyphen[1] == 'e' && Hyphen[2] == 'a' && Hyphen[3] == 'v' && Hyphen[4] == 'e' && Hyphen[5] == 'r'))
	{
		cout << "Congratulations! You figured out the word!" << endl;
	}
return 0;
}
