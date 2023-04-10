#include <iostream>
#include <string>

using namespace std;

int main() {
   int x;
   int y;
   cout << "# of Col?" << endl;
   cin >> x;
   int ** arr = new int*[x];
   for (int i = 0; i < 2; i++) {
      arr[i] = new int[x];
   }
   for(int i = 0; i < 2; i++) {
      for(int j = 0; j < x; j++) {

       arr[i][j] = j + 65;
    }
   }
   for (int i = 0; i < 2; i++) {
      for(int j = 0; j < x; j++) {
	 if(i ==0) {
	    cout << char(arr[i][j]) << " ";
	 }
	 cout << endl;
	 if(i ==1) {
	    cout << arr[i][j] << " ";
	 }

      }
   }


   for(int i = 0; i < x; i++) {
      delete[] arr [i];
   }
   delete[] arr;
}
