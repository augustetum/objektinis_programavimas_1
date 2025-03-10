#include "../mano_lib.h"
#include "strategijos1_bibl.h"
// 1 strategija: Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) 
// į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Tokiu būdu tas pats studentas 
// yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai). 
// Nesunku pastebėti, kad tokia strategija yra neefektyvi užimamos atminties atžvilgiu (įsitikinkite tuo!), 
// tačiau šiame žingsnyje svarbiausia yra patyrinėti, kaip programos veikimo sparta priklauso nuo konteinerio tipo?


int main(){
    cout << "Konteinerių testavimo programa | 1 strategija" << endl;
    vector<Studentas> studentaiV;
    deque<Studentas> studentaiD;
    list<Studentas> studentaiL;
    string failas = pasirinktiFaila();
    int rikiavimas;
    cout << "Pasirinkite failo rikiavimo būdą: " << endl;
    cout << "1 | Rikiuoti pagal vardą" << endl;
    cout << "2 | Rikiuoti pagal pavardę" << endl;
    cout << "3 | Rikiuoti pagal galutinį pažymį (su vidurkiu)" << endl;
    cout << "4 | Rikiuoti pagal galutinį pažymį (su mediana)" << endl;
    cin >> rikiavimas;

    Timer v;
    // vector testavimas
    nuskaitytiFailaT(failas, studentaiV);
    if (rikiavimas == 1) {
        rikiuotiPagalVarda(studentaiV);
    } else if (rikiavimas == 2) {
        rikiuotiPagalPavarde(studentaiV);
    } else if (rikiavimas == 3) {
        rikiuotiPagalGalutiniVid(studentaiV);
    } else if (rikiavimas == 4) {
        rikiuotiPagalGalutiniMed(studentaiV);
    } 
    skirstytiStudentusSuTaisPaciaisKonteineriaisT(studentaiV);
    cout << "Programa užtruko: " << v.elapsed() << "s\n";


}
