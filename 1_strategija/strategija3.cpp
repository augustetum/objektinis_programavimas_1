#include "../mano_lib.h"
#include "strategijos_bibl.h"


int main(){
    cout << "Konteinerių testavimo programa | 3 strategija" << endl;
    cout << "---------------------------------------------" << endl;
    vector<Studentas> studentaiV;

    string failas = pasirinktiFaila();

    int rikiavimas;
    cout << "Pasirinkite failo rikiavimo būdą: " << endl;
    cout << "1 | Rikiuoti pagal vardą" << endl;
    cout << "2 | Rikiuoti pagal pavardę" << endl;
    cout << "3 | Rikiuoti pagal galutinį pažymį (su vidurkiu)" << endl;
    cout << "4 | Rikiuoti pagal galutinį pažymį (su mediana)" << endl;
    cin >> rikiavimas;

    int kartai;
    cout << "Kiek kartų norite testuoti programą su skirtingais konteineriais?" << endl;
    cin >> kartai;

    double vektoriuTrukme;
    Timer v;

    for (int x = 0; x < kartai; x++){

        //vektoriaus testavimas
        v.reset();
        nuskaitytiFailaT(failas, studentaiV);
        studentuSkirstymas3(studentaiV, rikiavimas);
        vektoriuTrukme += v.elapsed();
        studentaiV.clear();
    }
    cout << "----------------------------Rezultatai------------------------------" << endl;
    cout << "Programa su vektoriais (vector) vidutiniškai užtruko: " << vektoriuTrukme / (double)kartai << "s\n";
    cout << "--------------------------------------------------------------------" << endl;
}