#include "mano_lib.h"
#include "strategijos1_bibl.h"
#include "timer.h"
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

    // vector testavimas
    nuskaitytiFailaT(failas, studentaiV);


}
