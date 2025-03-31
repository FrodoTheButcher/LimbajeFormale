#include <iostream>
#include <string>
 
int main() {
    enum Stare { q0, q1, q2, q3, q4 };
    Stare stareCurenta = q0;
 
    std::string cuvant;
    std::cout << "Introduceti un cuvant: ";
    std::cin >> cuvant;
 
    for (char simbol : cuvant) {
        switch (stareCurenta) {
            case q0:
                if (simbol == 'b')
                    stareCurenta = q1;
                else if (simbol == 'a')
                    stareCurenta = q4;
                break;
 
            case q1:
                if (simbol == 'a' || simbol == 'b')
                    stareCurenta = q2;
                break;
 
            case q2:
                if (simbol == 'a' || simbol == 'b')
                    stareCurenta = q2;
                else if (simbol == 'e')
                    stareCurenta = q3;
                break;
 
            case q3:
                stareCurenta = q4;
                break;
 
            case q4:
                break;
        }
    }

    if (stareCurenta == q4)
        std::cout << "Cuvant ACCEPTAT\n";
    else
        std::cout << "Cuvant RESPINS\n";
 
    return 0;
}
//orice cuvant incepe cu b,urmeaza a sau b , apoi oricate a sau b sau doar a