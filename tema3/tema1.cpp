#include <iostream>
#include <string>

class AutomatBauturi {
private:
    static constexpr const char* STARE_INITIALA = "q0";
    static constexpr const char* STARE_SELECTIE = "q1";
    static constexpr const char* STARE_PREGATIRE = "q2";
    static constexpr const char* CAFEA = "C";
    static constexpr const char* CEAI = "T";
    static constexpr const char* CAPPUCCINO = "A";
    static constexpr const char* CONFIRMARE = "OK";

    std::string stareCurenta = STARE_INITIALA;

public:
    void comandaBautura(const std::string& comanda) {
        if (stareCurenta == STARE_INITIALA && (comanda == CAFEA || comanda == CEAI || comanda == CAPPUCCINO)) {
            stareCurenta = STARE_SELECTIE;
            std::cout << "Bautura selectata. Apasa OK.\n";
        } else if (stareCurenta == STARE_SELECTIE && comanda == CONFIRMARE) {
            stareCurenta = STARE_PREGATIRE;
            std::cout << "Bautura e pregatita. Apasa OK.\n";
        } else if (stareCurenta == STARE_PREGATIRE && comanda == CONFIRMARE) {
            stareCurenta = STARE_INITIALA;
            std::cout << "Revenire la meniu.\n";
        } else {
            std::cout << "Comanda invalida.\n";
        }
    }
};

int main() {
    AutomatBauturi automat;
    std::string comanda;
    
    while (true) {
        std::cout << "Introduceti comanda: ";s
        std::cin >> comanda;
        automat.comandaBautura(comanda);
    }
    
    return 0;
}