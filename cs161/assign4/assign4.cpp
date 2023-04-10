/*Program: Hangman
 * Author: Grant Lance
 * Date: 5/10/18
 * Description: Assignment 4
 */

#include <iostream>
#include <string>

using namespace std;

int wordlength(string str) { //returns string length
   int x = str.length();
   return x;
}

int main() { //game start

   cout << "Welcome to Hangman" << endl; 
   cout << "Try and guess the word" << endl;
   cout << "give your first guess" << endl; 
   string str;
   string wrd = "_____";
   getline (cin, str);
   
 
   int A[2] = {1,0} ;
   int i;
   int b;

   for (i = A[0]; i <= wordlength(wrd); i++) { //pulls each letter individually from the word

  	 for (b = A[1] ; b < str.length() ; b++) { //checks each letter to see if it matches
      	 
     	 char z = str[b]; 

	 if(z == 'H') {
	    wrd[0] = 'H';
	 }
	 if(z == 'h') {
	    wrd[0] = 'h';
	 }
	 if(z == 'e'|| z == 'E') {
	    wrd[1] = 'e';
	 }
	 if(z == 'l'|| z == 'L') {
	    wrd[2] = 'l';
	    wrd[3] = 'l';
	 }
	 if(z == 'O'|| z == 'o') {
	    wrd[4] = 'o';
	 }
	 if(z=='H'||z=='h'||z=='e'||z=='l'||z=='L'||z=='O'||z=='o') { //correct guess message
	    cout << "Correct guess" << endl;
	 }
	 }
	 if(wrd == "hello" || wrd == "Hello") { //if word is correct in less than 6 guesses
	    cout << "You Win! the word was Hello" << endl;
	    return 0;
	 }
	 cout << "Give a guess" << endl;
	 cout << wrd << endl;
	 getline (cin, str) ; 
   }
   cout << "You ran out of tries" << endl; //if the player runs out of guesses
   return 0;
}
