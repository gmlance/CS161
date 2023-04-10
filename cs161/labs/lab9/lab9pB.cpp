#include <iostream>

using namespace std;

int fib_recurs(int x) {

if (x == 0) return 0;
if (x == 1) return 1;

return fib_recurs(x-1) + fib_recurs(x-2);
}

int main() {
   int x;

   cin >> x;
   cout << fib_recurs(x) << endl;

}
