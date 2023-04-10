#include <iostream>

using namespace std;

int main() {
   int rows, cols;
   rows = 0;
   cols = 0;
   cout << "Rows?" << endl;
   cin >> rows;
   cout << "Columns?" << endl;
   cin >> cols;

   int** arr = new int*[rows]; 
      for(int i = 0; i < rows; i++) {
	 arr[i] = new int[cols];
      }
     for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
	 arr[i][j] = rows+i+j;
      }
   }
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
	 cout << arr[i][j] << " ";
      }
      cout << endl;
   }
   for(int i = 0; i < rows; i++) { 
      delete [] arr[i];
   }
   delete [] arr;

   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
	 cout << arr[i][j] << " ";
      }
      cout << endl;
   }
}

