#include "misri_lib.h"

double skaiciuotiGalutiniSuVidurkiu(Studentas stud){
    /*
    double sum = accumulate(stud.pazymiai.begin(), stud.pazymiai.end(),0);
    double pazymiuVidurkis = sum / (double)stud.pazymiai.size();
    double galutinis = 0.4 * pazymiuVidurkis + 0.6 * stud.egzaminas;
    return galutinis;
    */
}

double skaiciuotiGalutiniSuMediana(Studentas stud){
    /*
    int n = stud.pazymiai.size();
    int med = 1;
    sort(stud.pazymiai.begin(), stud.pazymiai.end());
    if ( n % 2 != 0){
        med = (double)stud.pazymiai[n/2];
    } else {
        med = (double)(stud.pazymiai[(n-1)/2] + stud.pazymiai[n/2]) / 2.0;
    }

    double galutinis = 0.4 * med + 0.6 * stud.egzaminas;
    return galutinis;
     */
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

void generuotiPazymius(vector<Studentas> &studentuSarasas){
    srand(time(NULL));

     for (Studentas &s : studentuSarasas){
        int pazymiuKiekis = 3 + (rand() % 18);
        s.pazymiai = new int[pazymiuKiekis]; //pritaikyta C array

        for (int x = 0; x < pazymiuKiekis; x++){
            int pazymys = 1 + (rand() % 10);
            s.pazymiai[x] = pazymys;
        }

        int egzPazymys = 1 + (rand() % 10);
        s.egzaminas = egzPazymys;
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
        studentuSarasas.push_back(stud);
    }
}

void atlaisvintiAtminti(vector<Studentas> &studentuSarasas){
    for (Studentas &s : studentuSarasas){
        delete[] s.pazymiai;
    }
}

int main(){
    vector<Studentas> studentuSarasas;
    int menuChoice;
    cout << "Pasirinkite programos eigą:" << endl;
    cout << "1 | Įvesti studentus ranka" << endl;
    cout << "2 | Generuoti pažymius" << endl;
    cout << "3 | Generuoti pažymius bei studentų vardus, pavardes" << endl;
    cout << "4 | Baigti darbą" << endl;
    cin >> menuChoice;

    if (menuChoice == 1 || menuChoice == 2 || menuChoice == 3 || menuChoice == 4){

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
                    int count = 0;

                    stud.pazymiai = nullptr; //pradzioj pointer rodo i null

                    while (true){
                        cin >> input;
                        if (input == -1)
                        break;

                        int* tempPazymiai = new int[count + 1]; //naujas (didesnis) dinaminis masyvas
                        for (int x = 0; x < count; x++){
                            tempPazymiai[x]=stud.pazymiai[x]; //nukopijuoja elementus
                        }
                        tempPazymiai[count] = input;
                        delete[] stud.pazymiai;
                        stud.pazymiai = tempPazymiai;
                        count++;
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
                cout << "Programa baigta" << endl;
                break;
        }
    } else {
        cout << "Neteisingas meniu pasirinkimas" << endl;
    }

    atlaisvintiAtminti(studentuSarasas);
}