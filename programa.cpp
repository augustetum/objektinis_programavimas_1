#include "mano_lib.h"

int main(){
    bool veikimas = true;
    while(veikimas){
        try{
            vector<Studentas> studentuSarasas;
            int menuChoice;
            
            cout << "Pasirinkite programos eigą:" << endl;
            cout << "1 | Įvesti studentus ranka" << endl;
            cout << "2 | Generuoti pažymius" << endl;
            cout << "3 | Generuoti pažymius bei studentų vardus, pavardes" << endl;
            cout << "4 | Nuskaityti duomenis iš failo" << endl;
            cout << "5 | Testuoti failų nuskaitymą" << endl;
            cout << "6 | Baigti darbą" << endl;
            cin >> menuChoice;

            if(cin.fail()) {
                cin.clear();
                cin.ignore();
                throw std::runtime_error("Neteisingas meniu pasirinkimas!");
            }

            if (menuChoice != 1 && menuChoice != 2 && menuChoice != 3 && menuChoice != 4 && menuChoice != 5 && menuChoice != 6){
                throw std::runtime_error("Neteisingas meniu pasirinkimas!");
            }

            switch(menuChoice) 
            {
                case 1:

                    cout << "Pasirinkote studentų įvestį ranka" << endl;
                    cout << "---------------------------------" << endl;
                    
                    while (true){
                        try {
                            Studentas stud;
                            cout << "Įveskite studento vardą (įvedę visus norimus studentus ir norėdami užbaigti rašykite stop)" << endl;
                            cin >> stud.vardas;
                            if (stud.vardas == "stop"){
                                break;
                            }
                            if (!vardoTikrinimas(stud.vardas)) {
                                throw std::runtime_error("Neteisingas vardas! Vardas turi būti sudarytas tik iš raidžių.");
                            }
                            cout << "Įveskite studento pavardę" << endl;
                            cin >> stud.pavarde;
                            if (!vardoTikrinimas(stud.pavarde)) {
                                throw std::runtime_error("Neteisinga pavardė! Pavardė turi būti sudaryta tik iš raidžių.");
                            }
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
                        } catch (const std::runtime_error &e){
                            cout << e.what() << endl;
                            continue;
                        }
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
                    skaitytiIsFailoSuBuf(studentuSarasas);

                    while (true){
                        try {
                            int rikiavimas;
                            cout << "Pasirinkite rikiavimo būdą: " << endl;
                            cout << "1 | Rikiuoti pagal vardą" << endl;
                            cout << "2 | Rikiuoti pagal pavardę" << endl;
                            cout << "3 | Rikiuoti pagal galutinį pažymį (su vidurkiu)" << endl;
                            cout << "4 | Rikiuoti pagal galutinį pažymį (su mediana)" << endl;
                            cout << "5 | Nerikiuoti" << endl;
                            cin >> rikiavimas;

                            if (rikiavimas == 1) {
                                rikiuotiPagalVarda(studentuSarasas);
                            } else if (rikiavimas == 2) {
                                rikiuotiPagalPavarde(studentuSarasas);
                            } else if (rikiavimas == 3) {
                                rikiuotiPagalGalutiniVid(studentuSarasas);
                            } else if (rikiavimas == 4) {
                                rikiuotiPagalGalutiniMed(studentuSarasas);
                            } else if (rikiavimas == 5) {
                                rodytiVisusRezultatus(studentuSarasas);
                            } else {
                                throw "Neteisingas meniu pasirinkimas!";
                            }
                        } catch (const char* msg) {
                            cout << msg << endl;
                            continue;
                        }
                        break;
                    }
                break;

                case 5:
                    cout << "Pasirinkote testuoti programą" <<endl;
                    int kartai;
                    cout << "Kiek kartų norite nuskaityti failą?" << endl;
                    cin >> kartai;
                    testuotiFailuNuskaityma(studentuSarasas, kartai);
                break;
                    
                case 6:
                    cout << "Programa baigta" << endl;
                    veikimas = false;
                break;
            }
        } catch (const std::runtime_error &e) {
            cout << e.what() << endl;
            continue;
        }
    }
}