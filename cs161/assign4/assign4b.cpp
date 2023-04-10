/* Program: Function Library for Input Validation
 * Author: Grant Lance
 * Date: 5/10/19
 * Desc: Assignment 4 Part B
 */

#include <iostream>
#include <string>

using namespace std;
int isint(string str) { //checks to see if a given string is an integer
   int i;
   int y = 0;
   int z = 0;
   for(i=0; i < str.length(); i++) {
      char x;
      x = str[i];
      int b;
      b = int(x);
      if(b>=48 && b<=57) {
	 y = y + 1;
      }
      else {
	 z = z + 1;
      }
   }
   if (z == 0) { //if it is a string
      return 1;
   }
   else {
      return 0; //if it isn't a string
   }
}

int isfloat(string str) { //checks to see if a given string is only numbers and one decimal point
   int i;
   int y = 0;
   int z = 0;
   for(i=0; i < str.length(); i++) {
     
      char x = str[i];
      int b = int(x);

      if (b == 46) {
	 y = y + 1;
      }
      if (b < 48 && b > 57)
	 z = z + 1;
   }
   if (y == 1 && z == 0) { //if the string is a float
      return 1;
   }
   else {
      return 0; //if its not a float
   }
}

int isupper(char x) { //tells if a given character is uppercase or not
 
      int b = int(x);

      if (b < 65 && b > 90) { //if lowercase
	return 0;
      }
      if (b >= 65 && b <=90) { //if uppercase
   	return 1;
      }
      else { //if input isnt a letter
   	return 0;
      }
}      
int letterspresent(string str) { //checks for letters in a string
   int i;
   int y = 0;
   int z = 0;
   for(i =0; i < str.length(); i++) {
      char x = str[i];
      int b = int(x);
      if (b >= 65 && b <= 90) {
	 y = y + 1;
      }
      if (b >= 97 && b <= 122) {
	 y = y + 1;
      }
      else { 
	 z = z + 1;
      }
   }
   if (y > 0) { //if there are letters
      return 1;
   }
   else { //if there are no letters
      return 0;
   }
}

int numberspresent(string str) { //checks for numbers in a given string
   int i;
   int y = 0;
   int z = 0;
   for(i =0; i < str.length(); i++) {
      char x = str[i];
      int b = int(x);
      if (b >= 48 && b <= 57) {
	 y = y + 1;
      }
      else {
	 z = z + 1;
      }
   }
   if (y > 0) { //if there are numbers in the string
      return 1;
   }
   else { //if there are no numbers
      return 0;
   }
}
string toupper(string str) { //changes all lowercase letters to uppercase letters
   int i;
   for(i=0; i < str.length(); i++) { //pulls out each letter character
      char x = str[i];
      int b = (int)x;
      if(b>= 97 && b <= 122) { //if a character is a lowercase letter it changes it to uppercase
	 b = b - 32;
	 char ch = (char)b;
	 str[i] = ch;
      }
   }
   return str; //returns string with capital letters
}

int main () {
   string wrd = "as123df";
   string num = "123";
   cout << "isint (1 yes 0 no)" << endl;
   cout << wrd << " " << isint(wrd) << endl;
   cout << num << " " << isint(num) << endl;

   string flt = "1.234";
   string nflt = "1.2.34";
   cout << "isfloat (1 yes 0 no)" << endl;
   cout << flt << " " << isfloat(flt) << endl;
   cout << nflt << " " << isfloat(nflt) << endl;
   cout << wrd << " " << isfloat(wrd) << endl;

   char x = 'a';
   char y = 'A';
   char z = '!';
   cout << "isupper (1 yes 0 no)" << endl;
   cout << x << " " << isupper(x) << endl;
   cout << y << " " << isupper(y) << endl;
   cout << z << " " << isupper(z) << endl;

   string numlet = "13/!@3";
   string capnum = "ABD32D";
   cout << "letterspresent (1 yes 0 no)" << endl;
   cout << wrd << " " << letterspresent(wrd) << endl;
   cout << numlet << " " << letterspresent(numlet) << endl;
   cout << capnum << " " << letterspresent(capnum) << endl;

   string let = "abcd";
   cout << "numberspresent (1 yes 0 no)" << endl;
   cout << wrd << " " << numberspresent(wrd) << endl;
   cout << let << " " << numberspresent(let) << endl;
   cout << numlet << " " << numberspresent(numlet) << endl;

   cout << "toupper (changes lowercase to uppercase)" << endl; 
   cout << let << " " << toupper(let) << endl;
   cout << numlet << " " << toupper(numlet) << endl;
   cout << wrd << " " << toupper(wrd) << endl;

}
