#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

class LimbajeRegulate {
public:
    static vector<string> CitireFancy() {
        string input;
        getline(cin, input);

        vector<string> rezultat;
        stringstream ss(input);
        string element;

        while (getline(ss, element, ',')) {
            rezultat.push_back(element);
        }

        return rezultat;
    }

    static vector<string> Uniune(const vector<string>& L1, const vector<string>& L2) {
        set<string> rezultat(L1.begin(), L1.end());
        rezultat.insert(L2.begin(), L2.end());
        return vector<string>(rezultat.begin(), rezultat.end());
    }

    static vector<string> Intersectie(const vector<string>& L1, const vector<string>& L2) {
        vector<string> rezultat;
        for (const auto& e : L1) {
            if (find(L2.begin(), L2.end(), e) != L2.end()) {
                rezultat.push_back(e);
            }
        }
        return rezultat;
    }

    static vector<string> Concatenare(const vector<string>& L1, const vector<string>& L2) {
        set<string> rezultat;
        for (const auto& a : L1) {
            for (const auto& b : L2) {
                rezultat.insert(a + b);
            }
        }
        return vector<string>(rezultat.begin(), rezultat.end());
    }

    static vector<string> Diferenta(const vector<string>& L1, const vector<string>& L2) {
        vector<string> rezultat;
        for (const auto& e : L1) {
            if (find(L2.begin(), L2.end(), e) == L2.end()) {
                rezultat.push_back(e);
            }
        }
        return rezultat;
    }

    static void Apartine(const vector<string>& L1, const vector<string>& L2, const string& cuvant) {
        bool gasit = find(L1.begin(), L1.end(), cuvant) != L1.end() ||
                     find(L2.begin(), L2.end(), cuvant) != L2.end();

        if (gasit) {
            cout << "da,apartine.\n";
        } else {
            cout << "nope.\n";
        }
    }
};

int main() {
    while (true) {
        vector<string> L1 = LimbajeRegulate::CitireFancy();
        vector<string> L2 = LimbajeRegulate::CitireFancy();

        cout << 
                     "1. Uniune\n"
                     "2. Intersectie\n"
                     "3. Concatenare\n"
                     "4. Diferenta\n"
                     "5. Apartine limbaj\n"
                     "0. Iesire\n";

        while (true) {
            cout << endl<<"Alege operatia:";
            string optiune;
            getline(cin, optiune);
            vector<string> rezultat;
            if (optiune == "1") {
                rezultat = LimbajeRegulate::Uniune(L1, L2);
            } else if (optiune == "2") {
                rezultat= LimbajeRegulate::Intersectie(L1, L2);
            } else if (optiune == "3") {
                rezultat = LimbajeRegulate::Concatenare(L1, L2);
            } else if (optiune == "4") {
                rezultat = LimbajeRegulate::Diferenta(L1, L2);
            } else if (optiune == "5") {
                cout << "Introdu cuv: ";
                string cuvant;
                getline(cin, cuvant);
                LimbajeRegulate::Apartine(L1, L2, cuvant);
            } else if (optiune == "0") {
                return 0;
            } else {
                cout << "Optiune invalida!\n";
            }
            for(string value : rezultat)
            {
                cout<<value<<" ";
            }
            cout << "\nApasa Enter pentru a continua...";
            cin.get();
        }
    }

    return 0;
}

/*
L1 = {ab, ba}
L2 = {a, b}
UNIUNE:{ab, ba, a, b}



L1 = {ab, ba, b}
L2 = {b, a}
INTERSECTIE:{b}


L1 = {a, b}
L2 = {x, y}
Concatenare(L1, L2)
{ax, ay, bx, by}
PRACTIC LE CONCATENEAZA UNA CATE UNA



L1 = {a, b, c}
L2 = {b}
Difenta(L1, L2)
{a, c}
PRACTC IA CE NU E IN FIECARE



L1 = {ab, ba}
L2 = {a, b}
Apartine(L1, L2, "ba")
Cuvantul 'ba'
PRACTIC VERIFICA DACA APARTINE IN UNUL DIN ELE
*/