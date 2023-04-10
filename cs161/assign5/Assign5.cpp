
/* Program: Assignment 5 - Code
 Author: Grant Lance
 Date: 5/26/19
 Desc: Cost/Reimbursement for Business Trip
 Inputs: Days, Nights, Arrival Time, Depature Time, amount spent on food, hotels and transport
 Outputs: Total Cost, Reimbursement, Out of Pocket Cost
 */

#include <iostream>
#include <string>
using namespace std;

/*Function: Input Check - is money
 Description: Tells if input is a number with two decimal places and one decimal point
 Parameters: string
 Pre-Conditions: none
 Post-Conditions: returns float
 */


float isfloat(std::string str) { //checks to see if a given string is an integer
    int i;
    float z = 0;
    float c = 0;
    float d = 0;
    for(i=0; i < str.length(); i++) {
        char x;
        x = str[i];
        int b;
        b = int(x);
        if (b == 46) {
            z = z + 1;
            
            if (b <= 47) {
                d = d + 1;
            }
            if (b >= 58) {
                d = d + 1;
            }
        }
    }
    if (d > 0) {
        return 0;
    }
    if (z == 0 && d == 0) {
       return c;
    }
    if (z == 1 && d == 0) { //if it is an integer
      // c = stof (str);
        return c;
    }
    else {
        cout << "Bad Input!" << endl;
        return 0; //if it isn't an integer
    }
}
/*Function: Input Check - is integer
 Description: Tells if input is an integer
 Parameters: string
 Pre-Conditions: none
 Post-Conditions: returns integer
 */
int getint(std::string str) { //checks to see if a given string is an integer
    int i;
    int y = 0;
    int z = 0;
    int c = 0;
    for(i=0; i < str.length(); i++) {
        char x;
        x = str[i];
        int b;
        b = int(x);
        if(b>=48 && b<=57) {
            y = y + 1;
            c = c + b - 48;
        }
        else {
            z = z + 1;
        }
    }
    if (z == 0) { //if it is an integer
        return c;
    }
    else {
        cout << "Bad Input!" << endl;
        return 0; //if it isn't an integer
    }
}


/*Function: Airfare Cost
 Description: Void that updates Reimbursement based on airfare
 Parameters: Reimbursement
 Pre-Conditions: Must go on a trip
 Post-Conditions: Update Reimbursement
 */
void airfare(float *x) {
    float z = 0;
    int t = 0;
    string str;
    cout << "How much were your plane tickets?" << endl;
    while (t == 0) {
        cin >> z;
        if (z >= 1) {
            t = t + 1;
        }
    }
    *x = z + *x;
}

/*Function: Registration Cost
 Description: Void that updates Reimbursement based on registration fees
 Parameters: Reimbursement
 Pre-Conditions: Must go on a trip
 Post-Conditions: Update Reimbursement
 */
void regisration(float *x) {
    float z;
    cout << "How much were registration/seminar fees?" << endl;
    cin >> z;
    *x = z + *x;
}
/*Function: Car Rental
 Description: Void that updates Reimbursement/Out of Pocket Cost based on car rental
 Parameters: Reimbursement, Out of Pocket cost
 Pre-Conditions: Must rent a car
 Post-Conditions: Update Reimbursement
 */
void carrent(float *x, int ds) { // longer than 20 lines so it can check for correct inputs
    int r = 0;
    int s = 0;
    int t = 0;
    int choice = 0;
    string ch;
    int miles = 0;
    string mi;
    while (r == 0) {
        while (t == 0) {
            cout << "What Type of car (1 Sedan, 2 SUV, 3 Van, 4 Convertable)" << endl;
            getline(cin, ch);
            choice = getint(ch);
            int h = choice;
            if (h >= 1){
                t = t + 1;
            }
        }
        while (s == 0) {
            cout << "How many miles did you drive? (round up from any number that is not whole)" << endl;
            getline(cin, mi);
            miles = getint(mi);
            int h = miles;
            if (h >= 1){
                s = s + 1;
            }
        }
        if (choice == 1) {
            *x = (20 * ds) + (0.24 * miles);
            r = r + 1;
        }
        if (choice == 2) {
            *x = (25 * ds) + (0.27 * miles);
            r = r + 1;
        }
        if (choice == 3) {
            *x = (30 * ds) + (0.32 * miles);
            r = r + 1;
        }
        if (choice == 4) {
            *x = (50 * ds) + (0.45 * miles);
            r = r + 1;
        }
    }
    
}
/*Function: Parking Cost
 Description: Void that updates Reimbursement/Out of Pocket based on parking
 Parameters: Reimbursement, Out of Pocket Cost, Days
 Pre-Conditions: Must rent a car
 Post-Conditions: Update Reimbursement and/or Out of Pocket Cost
 */
void parking(float *x, float *y, int ds) {
    float spent = 0;
    float tot;
    int t = 0;
    float bud = 6 * ds;
    string str;
    
    cout << "Your parking allowance was: " << bud << " dollars for " << ds << "  days" << endl;
    cout << "How much did you spend on parking?" << endl;
    while (t == 0) {
        cin >> spent;
        if (spent >= 1) {
            t = t + 1;
        }
    }
    
    tot = bud - spent;
    if (tot >= 0) {
        *x = (bud - spent) + *x;
    }
    if (tot == 0) {
        *x = bud + *x;
    }
    if (tot <= 0) {
        float d;
        d = spent - bud;
        *y = d + *y;
        *x = bud + *x;
    }
}

/*Function: Taxi Use
 Description: Void that updates Reimbursement/Out of Pocktet based on parking
 Parameters: Reimbursement, Out of Pocket Cost, Days
 Pre-Conditions: Must pay for a taxi
 Post-Conditions: Update Reimbursement and/or Out of Pocket Cost
 */
void taxi(float *x, float *y, int ds) {
    float total = 0;
    float z;
    float h;
    int t = 0;
    float bud = 10 * ds;
    string str;
    
    cout << "Your budget for taxis was: $" << bud << endl;
    cout << "How much did you spend on Taxis?" << endl;
    
    while (t == 0) {
        cin >> total;
        if (total >= 1) {
            t = t + 1;
        }
    }
    z = bud - total;
    if (z == 0) {
        *x = *x + bud;
    }
    if (z > 0) {
        *x = *x + z;
    }
    if (z < 0) {
        float d;
        d = total - bud;
        *y = d + *y;
        *x = bud + *x;
    }
}
/*Function: Hotel Cost
 Description: Void that updates Reimbursement/Out of Pocktet based on Hotel Cost
 Parameters: Reimbursement, Out of Pocket Cost, Days
 Pre-Conditions: Must pay for a Hotel
 Post-Conditions: Update Reimbursement and/or Out of Pocket Cost
 */
void hotel(float *x, float *y, int ns) {
    float spend = 0;
    float z;
    int t = 0;
    float bud = 90 * ns;
    string str;
    
    cout << "Your budget for Hotels was: $" << bud << endl;
    cout << "How much did your hotels cost? (Total not per night)" << endl;
    while (t == 0) {
        cin >> spend;
        if (spend >= 0) {
            t = t + 1;
        }
    }
    z = bud - spend;
    if (z == 0) {
        *x = bud + *x;
    }
    if (z > 0) {
        *x = z + *x;
    }
    if (z < 0) {
        float d = -1 * z;
        *y = d + *y;
        *x = bud + *x;
    }
}

/*Function: Meals
 Description: Void that updates Reimbursement/Out of Pocktet based on departure and arrival time
 Parameters: Reimbursement, Out of Pocket Cost
 Pre-Conditions: Must pay for a food
 Post-Conditions: Update Reimbursement and/or Out of Pocket Cost
 */
void food(float *x, float *y,float ds) { // more than 20 to save time
    string dti;
    float fooddone = 0;
    float dt;
    string ati;
    float at;
    float fooddtwo = 0;
    int b = 0;
    int c = 0;
    float middle;
    float dayot;
    float total;
    int h = 0;
    
    for (int i = 0; i <= 0; b++) {
        cout << "what was your departure time on the first day?" << endl;
        cin >> dt;
        if (dt <= 7) {
            fooddone = 37;
            i = i +1;
        }
        if (dt <= 12) {
            fooddone = 28;
            i = i +1;
        }
        if (dt <= 16) {
            fooddone = 16;
            i = i +1;
        }
    }
    if (ds > 1) {
        
        for (int i = 0; i <= 0; c++) {
            cout << "what was your arrival time on the last day?" << endl;
            cin >> at;
            if (at >= 8) {
                fooddtwo = 9;
                i = i +1;
            }
            if (at >= 1) {
                fooddtwo = 21;
                i = i +1;
            }
            if (at >= 7) {
                fooddtwo = 37;
                i = i +1;
            }
        }
        dayot = fooddtwo + fooddone;
        middle = 37 * (ds-2);
        total = dayot + middle;
        
        cout << "Your budget for food was: $" << total << endl;
        cout << "How much did your food cost? (Total not per meal)" << endl;
        
        float spent = 0;
        string str;
        int t = 0;
        int z = 0;
        
        while (t == 0) {
            cin >>  spent;
            if (spent >= 1) {
                t = t + 1;
            }
        }
        z = total - spent;
        if (z == 0) {
            *x = total + *x;
        }
        if (z > 0) {
            *x = z + *x;
        }
        if (z < 0) {
            float d = -1 * z;
            *y = d + *y;
            *x = total + *x;
        }
    }
    
}


/*Function: Main
 Description: Calls Void Functions to update pointers that store Reimbursement and Out of Pocket Cost
 Parameters: Days, Nights, Arrival Time, Depature Time, amount spent on food, hotels and transport
 Pre-Conditions: None
 Post-Conditions: Give Total Cost, Reimbursement, and Out of Pocket Cost
 */
int main () { //more than 20 lines becuase it calls all the void functions
    int days;
    string dayz;
    int nights;
    string ni;
    int yn;
    int t = 0;
    int s = 0;
    int i = 0;
    float rei = 0;
    float oop = 0;
    
    while (s == 0) {
        cout << "how many days long was your trip?" << endl;
        getline(cin, dayz);
        days = getint(dayz);
        int h = days;
        if (h >= 1){
            s = s + 1;
        }
    }
    
    
    airfare(&rei);
    regisration(&rei);
    while (i == 0) {
        cout << "Did you rent a car? (1 yes 2 no)" << endl;
        cin >> yn;
        if (yn == 1) {
            carrent(&rei, days);
            i = i + 1;
        }
        if(yn == 2) {
            i = i + 1;
        }
    }
    
    parking(&rei, &oop, days);
    while (i == 1) {
        cout << "Did you use a taxi at all? (1 yes 2 no)" << endl;
        cin >> yn;
        if (yn == 1) {
            taxi(&rei, &oop, days);
            i = i + 1;
        }
        if(yn == 2) {
            i = i + 1;
        }
    }
    
    while (t == 0) {
        cout << "How many nights were you gone on your trip?" << endl;
        getline(cin, ni);
        nights = getint(ni);
        int h = nights;
        if (h >= 1){
            t = t + 1;
        }
    }
    
    hotel(&rei, &oop, nights);
    
    food(&rei, &oop, days);
    
    cout << "Amount to be Reimbursed: $" << rei << endl;
    cout << "Amount to be Paid Out of Pocket: $" << oop << endl;
    cout << "Total Amount Spent: $" << oop + rei << endl;
}


