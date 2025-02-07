#include "mano_lib.h"

int main(){
    Studentas stud;
    while (true){
            cout << "Įveskite studento vardą (norėdami sustabdyti programą rašykite stop)" << endl;
            cin >> stud.vardas;
            if (stud.vardas == "stop"){
                break;
            }
            cout << "Įveskite studento pavardę" << endl;
            cin >> stud.pavarde;
            cout << "Įveskite studento namų darbų pažymius (baigę įveskite -1)" << endl;
            int input;
            while (true){
                cin >> input;
                if (input == -1)
                break;
                stud.pazymiai.push_back(input);
            }
            cout << "Įveskite studento egzamino pažymį" <<endl;
            cin >> stud.egzaminas;
    }
}