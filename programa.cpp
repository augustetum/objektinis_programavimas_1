#include "mano_lib.h"

double skaiciuotiGalutini(Studentas stud);

int main(){
    Studentas stud;
    vector<Studentas> studentuSarasas;
    while (true){
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

    cout << std::left << std::setw(20) << "Pavardė" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << endl;
    cout << "-------------------------------------" << endl;
    for (Studentas s : studentuSarasas){
        cout << std::left << std::setw(20) << s.pavarde << std::setw(20) << s.vardas << std::setw(20) << skaiciuotiGalutini(s) << endl;
    }

}

double skaiciuotiGalutini(Studentas stud){
    int sum = accumulate(stud.pazymiai.begin(), stud.pazymiai.end(),0);
    double pazymiuVidurkis = sum / (double)stud.pazymiai.size(); //pataisyta
    double galutinis = 0.4 * pazymiuVidurkis + 0.6 * stud.egzaminas;
    return galutinis;
}