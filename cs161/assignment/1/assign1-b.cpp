/*
 * Program Filename: Assignment 1 Part B
 * Author: Grant Lance
 * Date: 4/7/2019
 * Description: Printing the size of data types using an in-built function
 */
//including libraries needed
#include <iostream> //cout and sizeof//
#include <limits.h>
#include <float.h>
//printing the values
using namespace std;
int main () {
cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
cout << "Size of signed int: " << sizeof(int) << endl;
cout << "Size of unsigned short int: " << sizeof(unsigned short int) << endl;
cout << "Size of signed short int: " << sizeof(short int) << endl;
cout << "Size of unsigned long int: " << sizeof(unsigned long int) << endl;
cout << "Size of signed long int: " << sizeof(long int) << endl;
cout << "Size of signed char: " << sizeof(char) << endl;
cout << "Size of unsigned char: " << sizeof(unsigned char) << endl;
cout << "Size of floating point: " << sizeof(float) << endl;
cout << "Size of double floating point: " << sizeof(double) << endl;
cout << "Size of boolean: " << sizeof(bool) << endl;
return 0;
} 
