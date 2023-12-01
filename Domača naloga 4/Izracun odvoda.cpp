#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


int main() {

    std::string ZapisDatoteka = "diff_poly.txt"; 
    std::string BranaDatoteka = "poly.txt";  

    std::ofstream outputFile(ZapisDatoteka);
    std::ifstream indata;
    indata.open(BranaDatoteka);

    int N = 0;
    indata >> N;

    std::vector<double> x;
    std::vector<double> f;
    
     for (int i = 0; i < N; i++) {
     
        double PravaVrednost, DrugaVrednost, ID;

        char colon; 
        indata >> ID >> colon >> PravaVrednost >> DrugaVrednost;
        x.push_back(PravaVrednost);
        f.push_back(DrugaVrednost);
    }
    indata.close();

    //Definiram korak h (korak med x vrednostmi, ki je konstanten)
    double h = abs(x[1] - x[2]);
    double DiferencnaShemaNaprej;
    
    //Zapišem enačbo za diferenčno shemo naprej (uporabim samo na prvem elementu)
    DiferencnaShemaNaprej = (-3 * f[0] + 4 * f[1] - f[2]) / abs(x[2]-x[0]);
    std::vector<double> DatotekaOdvodov;
    //Shranim v prvo vrstico
    DatotekaOdvodov.push_back(DiferencnaShemaNaprej);

    //Uporabim for zanko, da izračunam odvod s centralno diferenčno shemo v vseh točkah razen prve in zadnje
    for (int i = 1; i < (N - 1); i++) {
        double CentralnaDiferencnaShema;
        CentralnaDiferencnaShema = (f[i + 1] - f[i - 1]) / (2 * h);
        //Shranim v vmesne vrstice
        DatotekaOdvodov.push_back(CentralnaDiferencnaShema);
    }
    //Izračunam zadnjo vrdnost odvoda
    double DiferencnaShemaNazaj;
    DiferencnaShemaNazaj = (3*f[102] - 4*f[101] + f[100])/(2*abs(x[102]-x[101]));
    //Shranim v zadnjo vrstico
    DatotekaOdvodov.push_back(DiferencnaShemaNazaj);

    // Zapišem podatke v novo datoteko
   for (double value : DatotekaOdvodov) {
        outputFile << "f'(x) = "<< value << '\n';
    }
    outputFile.close();
    
   return 0;
}