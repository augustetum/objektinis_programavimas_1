#include "mano_lib.h"

int main(){
    Studentas stud;
    do {
            cout << "Įveskite studento vardą (norėdami sustabdyti programą rašykite stop)" << endl;
            cin >> stud.vardas;
            cout << "Įveskite studento pavardę";
            cin >> stud.pavarde;
            cout << "Įveskite studento namų darbų pažymius (baigę įveskite -1)";
            int input;
            while (input > 0){
                cin >> input;
                stud.pazymiai.push_back(input);
            }
            cout << "Įveskite studento egzamino pažymį";
            cin >> stud.egzaminas;
    } while (stud.vardas != "stop");
}