/*
 * Program Filename: Printing Macro Ranges
 * Author: Grant Lance
 * Date: 4/7/2019
 * Description: prints values of different types of int macros
 */
//pulling the libraries needed
#include <iostream> //command library
#include <limits.h> //limit library
using namespace std;
int main() {
//displaying value ranges
cout << "Min Value for Short int: " << SHRT_MIN << endl;
cout << "Max Value for Short int: " << SHRT_MAX << endl;
cout << "Max Value for unsigned short int: " << USHRT_MAX << endl;
cout << "Min Value for int: " << INT_MIN << endl;
cout << "Max Value for int: " << INT_MAX << endl;
cout << "Max Value for unsigned int: " << UINT_MAX << endl;
cout << "Max Value for long int: " << LONG_MAX << endl;
cout << "Min Value for long int: " << LONG_MIN << endl;
cout << "Max Value for unsigned long int: " << ULONG_MAX << endl;
cout << "Min Value for long long int: " << LLONG_MIN << endl;
cout << "Max Value for long long int: " << LLONG_MAX << endl;
cout << "Max Value for unsigned long long int: " << ULLONG_MAX << endl;
return 0;
}
