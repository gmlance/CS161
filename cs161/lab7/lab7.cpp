#include <iostream>

using namespace std;

void airCost(int *x, int *y) {
  cout << "How much did the plane tickets cost?" << endl;
  cin >> *x;
  *y = *x;
  }

int main () {
   int *TC;
   int y;   
   int *AC;
   int x;
   AC = &x;
   TC = &y;
   
   airCost(AC, TC);
   cout << "The tickets cost: " << x << " dollars" << endl;
 
   cout << "You will get back: " << y << " dollars" << endl;
}
