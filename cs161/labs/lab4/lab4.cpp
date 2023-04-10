#include <iostream>
#include <cmath>
using namespace std;

float kmtomi(float in) { //math for converting units
	in = in / 1.6;
	return in;
}

float kgtolb(float a) {
	a = a / 2.2;
	return a;

}

float mitokm(float b) {
	b = b * 1.6;
	return b;
}

float lbtokg(float c) {
	c = c * 2.2;
	return c;
}

int main() {
	
	cout << "what unit would you like to convert" << "\n"; //pick a unit to convert
	cout << " 1(km) 2(kg) 3(mi) 4(lb) 5(end)" << "\n";
	int choice;
	cin >> choice;
	
	while (choice >= 0 ) {
		
		if (choice == 1) { //km to mi
			float mi, s;
			cout << "how many km?" << "\n";
			cin >> s;
			mi = kmtomi(s);
			cout << mi << " miles" << "\n";
		}
		if (choice == 2) { //kg to lb
			float lb, d;
			cout << "how many kg?" << "\n";
			cin >> d;
			lb = kgtolb(d);
			cout << lb << " pounds" << "\n";
		}
		if (choice == 3) { //mi to km
			float km, f;
			cout << "how many mi?" << "\n";
			cin >> f;
			km = mitokm(f);
			cout << km << " kilometers" << "\n";
		}
		if (choice == 4) { //lb to kg
			float kg, g;
			cout << "how many lb?" << "\n";
			cin >> g;
			kg = lbtokg(g);
			cout << kg << " kilograms" << "\n";
		} 
		if (choice == 5) { //quit program
			break;
		}
		else { //bad input
			cout << "bad input try again" << "\n";	
			cout << "what unit would you like to convert" << "\n";
			cout << " 1(km) 2(kg) 3(mi) 4(lb) " << "\n";
			cin >> choice;
		}
	}
	return 0;
}
