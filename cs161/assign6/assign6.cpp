/*Program: Minesweeper
 * Author: Grant Lance
 * Date: 6/9/2019
 * Desc: Miesweeper Game
 */

#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;

/* Func: input check
 * desc: check input
 * in: string
 * out: integer
 */
void input (int *x) {
   string str;
   getline(cin, str);
   for(int i = 0; i < str.length(); i++) {
   }
}
/* Func: Main
 * desc: Runs game using other funciton
 * in: rows, columns, mines
 * out: prints game board
 */

int main() {
   int row;
   int col;
   cout << "How many Rows?" << endl;
   cin >> row;
   cout << "How many Columns" << endl;
   cin >> col;

     char** ary = new char*[row]; //create an array
     for(int i = 0; i < row; ++i){
       	ary[i] = new char[col];
       }
     for(int i = 0; i < row; i++){ //fill it
       	for(int j = 0; j < col; j++){
	  ary[i][j] = i + 1;
	}
     }

     //rand placement of mines

     int randr;
     int randc;
     int mines;

     cout << "How many mines?" << endl;
     cin >> mines;
     for(int c = 0; c < mines; c++) {

       	srand (time(NULL));
       	randr = rand() % row + 0;
	randc = rand() % col + 0;
	ary[randr][randc] = 0;

     }
     
     for(int i = 0; i < row; i++) { //print it
	for(int j = 0; j < col; j++){
	  cout << ary[i][j] << " ";
	}
	cout << endl;
	}
}
