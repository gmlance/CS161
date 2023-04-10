#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int main (){

     int n, a = 5, b = 3;
     char buffer [50];
     n = sprintf(buffer, "%d + %d = %d", a, b, a+b);
     cout << buffer << endl;
	   return 0;
}
