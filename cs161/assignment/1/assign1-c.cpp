/*
 * Program Filename: Assignment 1 Part C
 * Author: Grant Lance
 * Date: 4/7/2019
 * Description:Using a Library Function: Square root
 * Input: Positive Numerical Value
 * Output: Positive Numerical Value
 */
//including libraries needed
#include <iostream> //cout//
#include <math.h> //sqrt//
using namespace std;
int main ()
{
double num, answer; //declare variables//
num = 25;
answer = sqrt(num); 
cout << "the square root of " << num << " is: " << answer << endl;
return 0;
}
