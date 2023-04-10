#include <iostream>
#include <string> 

using namespace std;
void get_string(string* str) {
   cout << "enter a string" << endl;
   getline(cin, *str);
  
}

void set_replace_string(string space, string *str) {
   for (int i = 0; i < space.length(); i++) {
      if (space[i] != ' ') {
	 space[i] = '-';
      }
      *str = space;
   }
}

int main () {
   string str;
   get_string(&str);
   cout << str << endl;
   string dash = str;
   set_replace_string(str, &dash);
   cout << dash << endl;
}

