#include "mano_lib.h"

int main(){
    vector<Studentas> studentuSarasas;
    int menuChoice;
    int rikiavimas;
    cout << "Pasirinkite programos eigą:" << endl;
    cout << "1 | Įvesti studentus ranka" << endl;
    cout << "2 | Generuoti pažymius" << endl;
    cout << "3 | Generuoti pažymius bei studentų vardus, pavardes" << endl;
    cout << "4 | Nuskaityti duomenis iš failo" << endl;
    cout << "5 | Baigti darbą" << endl;
    cin >> menuChoice;

    if (menuChoice == 1 || menuChoice == 2 || menuChoice == 3 || menuChoice == 4 || menuChoice == 5){

        switch(menuChoice) 
        {
            case 1:

                cout << "Pasirinkote studentų įvestį ranka" << endl;
                cout << "---------------------------------" << endl;
                
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
                    cout << "Įveskite studento egzamino pažymį" << endl;
                    cin >> stud.egzaminas;

                    studentuSarasas.push_back(stud);
                    }

                    rodytiRezultatus(studentuSarasas);

                break;

            case 2:
                cout << "Pasirinkote generuoti pažymius" << endl;
                cout << "---------------------------------" << endl;

                while (true){
                    Studentas stud;
                    cout << "Įveskite studento vardą (įvedę visus norimus studentus ir norėdami užbaigti rašykite stop)" << endl;
                    cin >> stud.vardas;
                    if (stud.vardas == "stop"){
                        break;
                    }
                    cout << "Įveskite studento pavardę" << endl;
                    cin >> stud.pavarde;

                    studentuSarasas.push_back(stud);
                }

                generuotiPazymius(studentuSarasas);
                rodytiRezultatus(studentuSarasas);

                break;

            case 3:
                cout << "Pasirinkote generuoti pažymius, studentų pavardes ir vardus" << endl;
                cout << "---------------------------------" << endl;
                generuotiStudentus(studentuSarasas);
                generuotiPazymius(studentuSarasas);
                rodytiRezultatus(studentuSarasas);
                break;

            case 4:
                cout << "Pasirinkote nuskaityti duomenis iš failo" << endl;
                cout << "----------------------------------------" << endl;
                skaitytiIsFailo(studentuSarasas);

                cout << "Pasirinkite rikiavimo būdą: " << endl;
                cout << "1 | Rikiuoti pagal vardą" << endl;
                cout << "2 | Rikiuoti pagal pavardę" << endl;
                cout << "3 | Rikiuoti pagal galutinį pažymį (su vidurkiu)" << endl;
                cout << "4 | Rikiuoti pagal galutinį pažymį (su mediana)" << endl;
                cout << "5 | Nerikiuoti" << endl;
                cin >> rikiavimas;

                if (rikiavimas == 1)
                    rikiuotiPagalVarda(studentuSarasas);
                if (rikiavimas == 2)
                    rikiuotiPagalPavarde(studentuSarasas);
                if (rikiavimas == 3)
                    rikiuotiPagalGalutiniVid(studentuSarasas);
                if (rikiavimas == 4)
                    rikiuotiPagalGalutiniMed(studentuSarasas);
                else
                    cout << "Neteisingas meniu pasirinkimas" << endl;

                break;

            case 5:
                cout << "Programa baigta" << endl;
                break;
        }
    } else {
        cout << "Neteisingas meniu pasirinkimas" << endl;
    }


}

void Studentas::skaiciuotiGalutiniSuVidurkiu(){
    double sum = accumulate(pazymiai.begin(), pazymiai.end(),0);
    double pazymiuVidurkis = sum / (double)pazymiai.size();
    double galutinis = 0.4 * pazymiuVidurkis + 0.6 * egzaminas;
    galutinisVid = galutinis;
}

void Studentas::skaiciuotiGalutiniSuMediana(){
    int n = pazymiai.size();
    int med = 1;
    sort(pazymiai.begin(), pazymiai.end());
    if ( n % 2 != 0){
        med = (double)pazymiai[n/2];
    } else {
        med = (double)(pazymiai[(n-1)/2] + pazymiai[n/2]) / 2.0;
    }

    double galutinis = 0.4 * med + 0.6 * egzaminas;
    galutinisMed = galutinis;
}

void rodytiRezultatus(vector<Studentas> studentuSarasas){
    int choice;
    cout << "Jei norėtumete galutinį balą skaičiuoti su vidurkiu, įrašykite 0, jei su mediana - įrašykite 1" << endl;
    cin >> choice;

    cout << "Štai rezultatai: " << endl;
    cout << endl;

    cout << std::left << std::setw(20) << "Pavardė" << std::setw(20) << "Vardas";

    if (choice == 0){
        cout << std::setw(20) << "Galutinis (Vid.)" << endl;
        cout << "---------------------------------------------------------" << endl;
        for (Studentas s : studentuSarasas){
            s.skaiciuotiGalutiniSuVidurkiu();
            cout << std::left << std::setw(20) << s.pavarde << std::setw(20) << s.vardas << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisVid<< endl;
        }
    } else if (choice == 1){
        cout << std::setw(20) << "Galutinis (Med.)" << endl;
        cout << "---------------------------------------------------------" << endl;
        for (Studentas s : studentuSarasas){
            s.skaiciuotiGalutiniSuMediana();
            cout << std::left << std::setw(20) << s.pavarde << std::setw(20) << s.vardas << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisMed << endl;
        }
        } else {
            cout << "Neteisingai įvestas pasirinkimas";
        }
}

void rodytiVisusRezultatus(vector<Studentas> studentuSarasas){
    for (Studentas s: studentuSarasas){
        cout << std::left << std::setw(20) << s.pavarde << std::setw(20) << s.vardas << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisVid << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisMed << endl;
    }
 }

void generuotiPazymius(vector<Studentas> &studentuSarasas){
    srand(time(NULL));
    for (Studentas &s : studentuSarasas){
        int pazymiuKiekis = 3 + (rand() % 18);
        for (int x = 0; x < pazymiuKiekis; x++){
            int pazymys = 1 + (rand() % 10);
            s.pazymiai.push_back(pazymys);
        }
        int egzPazymys = 1 + (rand() % 10);
        s.egzaminas = egzPazymys;
        s.skaiciuotiGalutiniSuMediana();
        s.skaiciuotiGalutiniSuVidurkiu();
    }
}

void generuotiStudentus(vector<Studentas> &studentuSarasas){
    srand(time(NULL));

    vector<string> vardai;
    vector<string> pavardes;
    string name;

    ifstream varduFailas("firstNames.txt");
    while(getline(varduFailas, name)){
        vardai.push_back(name);
    }
    varduFailas.close();

    ifstream pavardziuFailas("lastNames.txt");
    while(getline(pavardziuFailas, name)){
        pavardes.push_back(name);
    }
    pavardziuFailas.close();

    int studentuSkaicius = 4 + (rand()%7);

    for (int i = 0; i < studentuSkaicius; i++){
        Studentas stud;
        stud.vardas = vardai [rand() % vardai.size()];
        stud.pavarde = pavardes [rand() % pavardes.size()];
        stud.skaiciuotiGalutiniSuMediana();
        stud.skaiciuotiGalutiniSuVidurkiu();
        studentuSarasas.push_back(stud);
    }

}

void skaitytiIsFailo(vector<Studentas> &studentuSarasas){
    ifstream failas("studentai10000.txt");
    string eilut;
    int pazymys;

    getline(failas, eilut);

    while(getline(failas, eilut)){
        Studentas stud;
        istringstream eilute(eilut);
        eilute >> stud.vardas >> stud.pavarde;
        while(eilute >> pazymys){
            stud.pazymiai.push_back(pazymys);
        }

        stud.egzaminas = stud.pazymiai.back();
        stud.pazymiai.pop_back();
        stud.skaiciuotiGalutiniSuMediana();
        stud.skaiciuotiGalutiniSuVidurkiu();

        studentuSarasas.push_back(stud);
    }
}

void rikiuotiPagalVarda(vector<Studentas> studentuSarasas){
    sort(studentuSarasas.begin(), studentuSarasas.end(), [](const Studentas& a, const Studentas& b) {
        return a.vardas < b.vardas;
    });

    for (Studentas s : studentuSarasas){
        cout << std::left << std::setw(20) << s.pavarde << std::setw(20) << s.vardas << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisVid << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisMed << endl;
    }
}

void rikiuotiPagalPavarde(vector<Studentas> studentuSarasas){}

void rikiuotiPagalGalutiniMed(vector<Studentas> studentuSarasas){}

void rikiuotiPagalGalutiniVid(vector<Studentas> studentuSarasas){}

