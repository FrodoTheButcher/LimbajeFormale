#include <iostream>

using namespace std;

int main() {
    char input;
    int state = 1; 
    string iesire;

    while (true) {
        cout << "Intrare (A/B): ";
        cin >> input;

        if (input == 'Q' || input == 'q') break; 

        if (state == 1) {
            if (input == 'A') {
                state = 1;
            } else if (input == 'B') {
                state = 2;
            }
            iesire = "O1";
            cout << "Starea curenta: S" << state <<" cu iesirea "<<iesire;
        } 
        else if (state == 2) {
            if (input == 'A') {
                state = 1;
            } else if (input == 'B') {
                state = 2;
            }
            iesire="o2";
            cout << "Starea curenta: S" << state <<" cu iesirea "<<iesire;
        } 
        else {
            cout << "Stare invalida!\n";
        }
    }

    return 0;
}

/*
        A       B       EXIST
S1->    S1      S2        O1
S2->    S1       S2        O2

*/