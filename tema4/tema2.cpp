#include <iostream>

using namespace std;

int main() {
    char input;
    int state = 1; 


    while (true) {
        cout << "Intrare (X/Y): ";
        cin >> input;

        if (state == 1) {
            if (input == 'X') {
                state = 2;
                cout << "Stare: Q2 - Iesire: O1\n";
            } else if (input == 'Y') {
                state = 1;
                cout << "Stare: Q1 - Iesire: O1\n";
            }
        } 
        else if (state == 2) {
            if (input == 'X') {
                state = 1;
                cout << "Stare: Q1 - Iesire: O2\n";
            } else if (input == 'Y') {
                state = 2;
                cout << "Stare: Q2 - Iesire: O2\n";
            }
        } 
        else {
            cout << "invalid!\n";
        }
    }

    return 0;
}

/*
Stare curentă	Intrare	Stare următoare	Ieșire
Q1	            X	    Q2	            O1
Q1	            Y	    Q1	            O1
Q2	            X	    Q1	            O2
Q2	            Y	    Q2	            O2
*/