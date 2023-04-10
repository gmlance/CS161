#include <iostream>

using namespace std;

int main() {
   int x, y;
   cout << "cin x" << endl;
   cin >> x;
   cout << "cin y" << endl;
   cin >> y;

   int X = x;
   int Y = y;
   int k = 0;
   
   int** arr = new int*[y];
   for(int i = 0; i < y; i++) {
      arr[i] = new int [x];
   }

   for(int i = 0; i < y; i++) {
      for(int j = 0; j < x; j++) {
	arr[i][j] = x+j+i;
      }
   }

   for(int i = 0; i < y; i++) {
      for(int j = 0; j < x; j++) {
	 cout << arr[i][j] << " ";
      }
      cout << endl;
}
}
