#include "../mano_lib.h"
#include "strategijos_bibl.h"

int main(){
    vector<Studentas> studentuSarasasV;
    deque<Studentas> studentuSarasasD;
    list<Studentas> studentuSarasasL;

    string failas;
    failas = pasirinktiFaila();

    Timer v, d, l; //bendram laikui
    Timer nV, nD, nL; //nuskaitymui
    Timer rV, rD, rL; //rikiavimui
    Timer sV, sD, sL; //skirstymui

    double trukmeV = 0.0;
    double trukmeD = 0.0;
    double trukmeL = 0.0;

    double nuskaitymoTrukmeV = 0.0;
    double nuskaitymoTrukmeD = 0.0;
    double nuskaitymoTrukmeL = 0.0;

    double rikiavimoTrukmeV = 0.0;
    double rikiavimoTrukmeD = 0.0;
    double rikiavimoTrukmeL = 0.0;

    double skirstymoTrukmeV = 0.0;
    double skirstymoTrukmeD = 0.0;
    double skirstymoTrukmeL = 0.0;

    cout << "Tyrimas | Konteinerių skirtumai" << endl;
    for (int i = 0; i < 3; i++){
        v.reset();

        nV.reset();
        nuskaitytiFailaT(failas, studentuSarasasV);
        nuskaitymoTrukmeV += nV.elapsed();

        rV.reset();
        rikiuotiPagalGalutiniVidT(studentuSarasasV);
        rikiavimoTrukmeV += rV.elapsed();

        sV.reset();
        skirstytiStudentus(studentuSarasasV);
        skirstymoTrukmeV += sV.elapsed();

        trukmeV += v.elapsed();
    }



    cout << "-----------Vektoriai-----------" << endl;
    cout << "Failo nuskaitymas: " << nuskaitymoTrukmeV / 3.0 << "s\n";
    cout << "Rikiavimas: " << rikiavimoTrukmeV / 3.0 << "s\n";
    cout << "Skirstymas: " << skirstymoTrukmeV / 3.0 << "s\n";
    cout << "Iš viso: " << trukmeV / 3.0 << "s\n";

     


}