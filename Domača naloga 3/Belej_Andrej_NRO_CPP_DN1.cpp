#include <iostream>
#include <cmath>

// Funkcija arctan s pomočjo Taylorjeve vrste
double arctan(double x, int n) {
    double result = 0;
    for (int i = 0; i <= n; i++) {
        double n_clen = std::pow(-1, i) * std::pow(x, 2 * i + 1) / (2 * i + 1);
        result += n_clen;
    }
    return result;
}

//Funkcija za izračun integrala s trapezno metodo (za 20 členov Taylorjeve vrste)
double povrsina(double a, double b, int n) {
    double dolzina_clen = (b - a) / n;
    double ZV_integral = 0;

    for (int i = 0; i <= n; i++) {
        double tocka_ab = a + i * dolzina_clen;
        double funkcija = std::exp(3 * tocka_ab) * arctan(tocka_ab / 2, 20);
        if (i == 0 || i == n) {
            ZV_integral += funkcija;
        } 
        else {
            ZV_integral += 2 * funkcija;
        }
    }

    ZV_integral *= (b - a) / (2 * n);
    return ZV_integral;
}

int main() {
    double zacetna_tocka = 0.0;
    double koncna_tocka = M_PI_4;
    int podintervali = 100;

    double result = povrsina(zacetna_tocka, koncna_tocka, podintervali);

    std::cout << result << std::endl;

    return 0;
}

 