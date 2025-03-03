#include <iostream>
#include <vector>

class ParcareaMasinilor {
private:
    std::vector<int> locuriParcare;
    int numarLocuri;

    int gasesteLocLiber() {
        for (int i = 0; i < numarLocuri; i++) {
            if (locuriParcare[i] == 0) {
                return i;
            }
        }
        return -1;
    }

    int gasesteLocOcupat() {
        for (int i = 0; i < numarLocuri; i++) {
            if (locuriParcare[i] == 1) {
                return i;
            }
        }
        return -1;
    }

    void afiseazaStareaParcarii() {
        std::cout << "Starea parcare:\n";
        for (int i = 0; i < numarLocuri; i++) {
            std::cout << "Loc " << (i + 1) << ": " 
                      << (locuriParcare[i] == 0 ? "loc liber" : "loc ocupat") << "\n";
        }
    }

public:
    ParcareaMasinilor(int numarLocuri) : numarLocuri(numarLocuri) {
        locuriParcare.resize(numarLocuri, 0); 
    }

    void proceseazaComanda(const std::string& comanda) {
        if (comanda == "P") { 
            int locLiber = gasesteLocLiber();
            if (locLiber != -1) {
                locuriParcare[locLiber] = 1;
                std::cout << "Masina parcata in " << locLiber + 1 << "\n";
            } else {
                std::cout << "Parcarea este plina.\n";
            }
        } else if (comanda == "A") { 
            int locOcupat = gasesteLocOcupat();
            if (locOcupat != -1) {
                locuriParcare[locOcupat] = 0;
                std::cout << "Masina pleaca din " << locOcupat + 1 << "\n";
            } else {
                std::cout << "Parcare goala.\n";
            }
        } else if (comanda == "O") {
            afiseazaStareaParcarii();
        } else {
            std::cout << "P pentru parcare "
                      << "A pt. plecare masina sau O pentru a vedea starea parcarii.\n";
        }
    }
};

int main() {
    int numarLocuri;
    std::cout << "Introduceti numarul de locuri in parcare: ";
    std::cin >> numarLocuri;

    ParcareaMasinilor parcarea(numarLocuri);
    std::string comanda;
    
    while (true) {
        std::cout << "(P - parcare, A - plecare, O - stare, Q - iesire): ";
        std::cin >> comanda;

        if (comanda == "Q") {
            break;
        }

        parcarea.proceseazaComanda(comanda);
    }
    
    return 0;
}
