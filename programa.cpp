#include "mano_lib.h"

int main(){
    vector<Studentas> studentuSarasas;
    while (true){
            Studentas stud;
            cout << "Įveskite studento vardą (įvedę visus norimus studentus ir norėdami užbaigti rašykite stop)" << endl;
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

            studentuSarasas.push_back(stud);
    }

    int choice;
    cout << "Jei norėtumete galutinį balą skaičiuoti su vidurkiu, įrašykite 0, jei su mediana - įrašykite 1";
    cin >> choice;

    cout << "Štai rezultatai: " << endl;
    cout << endl;

    cout << std::left << std::setw(20) << "Pavardė" << std::setw(20) << "Vardas";

    if (choice == 0){
        cout << std::setw(20) << "Galutinis (Vid.)" << endl;
        cout << "---------------------------------------------------------" << endl;
        for (Studentas s : studentuSarasas){
            cout << std::left << std::setw(20) << s.pavarde << std::setw(20) << s.vardas << std::setw(20) << std::fixed << std::setprecision(2) << skaiciuotiGalutiniSuVidurkiu(s) << endl;
        }
    } else if (choice == 1){
        cout << std::setw(20) << "Galutinis (Med.)" << endl;
        cout << "---------------------------------------------------------" << endl;
        for (Studentas s : studentuSarasas){
            cout << std::left << std::setw(20) << s.pavarde << std::setw(20) << s.vardas << std::setw(20) << std::fixed << std::setprecision(2) << skaiciuotiGalutiniSuVidurkiu(s) << endl;
        }
    } else {
        cout << "Neteisingai įvestas pasirinkimas";
    }

}