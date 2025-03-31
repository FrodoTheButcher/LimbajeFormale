#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Stare {
    S0, // Verde strada A
    S1  // Verde strada B
};

class AutomatMealy {
private:
    Stare stareCurenta;

public:
    AutomatMealy() {
        stareCurenta = S0; 
    }

    void setStare(Stare stare)
    {
        this->stareCurenta=stare;
    }

    pair<Stare, int> proceseazaPereche(int a, int b) {
        Stare stareUrmatoare = stareCurenta;
        int iesire = 0;

        switch (stareCurenta) {
            case S0:
                if (a == 0 && b == 0) { stareUrmatoare = S0; iesire = 0; }
                else if (a == 0 && b == 1) { stareUrmatoare = S1; iesire = 1; }
                else if (a == 1 && b == 0) { stareUrmatoare = S0; iesire = 0; }
                else if (a == 1 && b == 1) { stareUrmatoare = S1; iesire = 1; }
                break;
            case S1:
                if (a == 0 && b == 0) { stareUrmatoare = S1; iesire = 1; }
                else if (a == 0 && b == 1) { stareUrmatoare = S1; iesire = 1; }
                else if (a == 1 && b == 0) { stareUrmatoare = S0; iesire = 0; }
                else if (a == 1 && b == 1) { stareUrmatoare = S0; iesire = 0; }
                break;
        }

        Stare stareAnterioara = stareCurenta;
        stareCurenta = stareUrmatoare;

        return {stareAnterioara, iesire};
    }

    string denumireStare(Stare s) {
        return s == S0 ? "S0" : "S1";
    }
};

int main() {
    AutomatMealy automat;
    int n;
    cout << "Nr de perechi";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        auto [stareInainte, iesire] = automat.proceseazaPereche(a, b);

        cout << "Stare curenta: " << automat.denumireStare(stareInainte)
             << " Intrare: (" << a << "," << b << ")"
             << " Iesire: " << iesire << "\n";
    }

    return 0;
}
