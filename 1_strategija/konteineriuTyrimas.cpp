#include "../mano_lib.h"
#include "strategijos_bibl.h"

int main(){
    vector<Studentas> studentuSarasasV;
    deque<Studentas> studentuSarasasD;
    list<Studentas> studentuSarasasL;

    string failas;
    failas = pasirinktiFaila();

    Timer v;
    Timer d;
    Timer l;

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
        nuskaitytiFailaT(failas, studentuSarasasV);
        rikiuotiPagalGalutiniVidT(studentuSarasasV);
        skirstytiStudentus(studentuSarasasV);
        trukmeV += v.elapsed();


    }
    


}