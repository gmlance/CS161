#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdio>

using namespace std;

bool iscell (int row, int col, int r, int c) {
   return (row >= 0) && (row < r) && (col >= 0) && (col < c);
}

bool ismine (int row, int col, char board[][50]) {
   if (board[row][col] == 'X')
      return (true);
   else
      return (false);
}

void choice(int *x, int *y) {
   printf("enter row, col to select");
   scanf("%d %d" , x, y);
}

void printb(char gameb[][50], int r, int c) {
   for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
	 cout << gameb[i][j] ;
      }
      cout << endl;
   }
}
int countaround(int row, int col, int mines[][2],int r, int c, char realb[][50]){ 
   int i;
   int count = 0;
   if (iscell (row-1, col, r, c) == true) {
      if (ismine(row-1,col, realb) == true)
	 count++;
   }
   if(iscell (row+1, col, r, c) == true) {
      if(ismine(row+1, col, realb) == true)
   	count++;
   }
   if(iscell(row, col+1, r, c) == true) {
      if (ismine(row, col+1, realb) == true)
	 count++;
   }
   if(iscell(row, col-1, r ,c) == true) {
      if(ismine(row, col-1, realb) == true)
	 count++;
   }
   if(iscell(row-1, col+1, r, c) == true) {
      if (ismine(row+1, col+1, realb) == true)
	 count++;
   }
   if(iscell(row-1,col-1, r, c) == true) {
      if (ismine(row-1, col-1, realb) == true)
     	count++;
   }
   if(iscell(row+1,col+1, r , c) == true) {
      if(ismine(row+1,col+1, realb) == true) 
         count++;
   }
   if(iscell(row+1, col-1, r , c) == true) {
      if(ismine(row+1, col-1, realb) == true)
         count++;
   }
   return count;
   }
bool playgamer(char gameb[][50], char realb[][50], int mines[][2], int row, int col,int r, int c, int *mvlft, int m) {
   int i, j;

   if(gameb[row][col] != '-') {
      return false;
   }
   if(realb[row][col] == 'X') {
      gameb[row][col] = 'X';
      for(i = 0; i < m; i++) {
         gameb[mines[i][0]][mines[i][1]]= '*';
	 }
      printb(gameb, r, c);
      printf("you lose");
      return true;
   }
   else {
	int count = countaround(row, col, mines, r, c, realb);
       (*mvlft)--;
	gameb[row][col] = count + '0';
 	if (!count) {	
   if (iscell (row-1, col, r, c) == true) {
      if (ismine(row-1,col, realb) == false)
	 playgamer(gameb, realb, mines, row-1, col ,&mvlft);
   }
   if(iscell (row+1, col, r, c) == true) {
      if(ismine(row+1, col, realb) == false
   	 playgamer(gameb, realb, mines, row+1, col ,&mvlft);
   }
   if(iscell(row, col+1, r, c) == true) {
      if (ismine(row, col+1, realb) == false)
	  playgamer(gameb, realb, mines, row, col+1 ,&mvlft);
   }
   if(iscell(row, col-1, r ,c) == true) {
      if(ismine(row, col-1, realb) == false
	  playgamer(gameb, realb, mines, row, col-1 ,&mvlft);
   }
   if(iscell(row-1, col+1, r, c) == true) {
      if (ismine(row+1, col+1, realb) == false)
	  playgamer(gameb, realb, mines, row-1, col+1 ,&mvlft);
   }
   if(iscell(row-1,col-1, r, c) == true) {
      if (ismine(row-1, col-1, realb) == true)
     	playgamer(gameb, realb, mines, row-1, col-1 ,&mvlft);
   }
   if(iscell(row+1,col+1, r , c) {
      if(ismine(row+1,col+1, realb) == false) 
          playgamer(gameb, realb, mines, row+1, col+1 ,&mvlft);
   }
   if(iscell(row+1, col-1, r , c) == true) {
      if(ismine(row+1, col-1, realb) == false)
         playgamer(gameb, realb, mines, row+1, col-1 ,&mvlft);
   }
   
   }
   return false;
   }
   }
void putmine(int mines[][2], char realb[][50], int r, int c, int m) {
   bool mark[r*c];
   memset(mark, false, sizeof(mark));
   for(int i = 0; i < m; ) {
      int random = rand() % (r*c);
      int x = random/c;
      int y = random/r;

      if(mark[random] == false) {
         mines[i][0] = x;
	 mines[i][1] = y;
	 realb[mines[i][0]][mines[i][1]] = 'X';
	 mark[random] = true;
	 i++;
      }
   }
}

void initial (char realb[][50], char gameb[][50], int r, int c) {
   srand(time(NULL));
   for(int i=0; i < r; i++) {
      for(int j=0; j < c; j++) {
	 gameb[i][j[] = realb[i][j] = '-';
      }
   }
}

void playgame(int r, int c, int m) {
   int max = 15;
   bool gameO = false;
   char realb[r][c], gameb[r][c];

   int mvlft= (r * c) - m, x, y;
   int mines[15][2];

   initial(realb, gameb, r, c);

   int currentmv = 0;
   while(gameO == flase) {
      printf("board looks like this : \n");
      printb(gameb, r, c);
      choice(&x, &y);
      currentmv++;
      gameO = playgamer(gameb, realb, mines, x, y, &mvlft, m);
      if((gameO == flase) && (mvlft == 0)) {
	 printf("\n you win \n");
	 gameO = true;
      }
   }
}

int main() {
   cout << "How many rows?" << endl;
   int r;
   int c;
   int m;
   int row;
   int col;
   int *y;
   int *x;
   row = *x;
   col = *y;
   cin >> r;
   cout << "how many columns?" << endl;
   cin >> c;
   cout << "how many mines?" << endl;
   cin >> m;
   playgame(r, c, m);

   return 0;
}
