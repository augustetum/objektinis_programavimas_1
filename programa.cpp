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
            cout << "6 | Generuoti studentų failą" << endl;
            cout << "7 | Atlikti laiko matavimo tyrimą" << endl;
            cout << "8 | Baigti darbą" << endl;
            cin >> menuChoice;

            if(cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::runtime_error("Neteisingas meniu pasirinkimas!");
            }

            if (menuChoice != 1 && menuChoice != 2 && menuChoice != 3 && menuChoice != 4 && menuChoice != 5 && menuChoice != 6 && menuChoice != 7 && menuChoice != 8){
                throw std::runtime_error("Neteisingas meniu pasirinkimas!");
            }

            switch(menuChoice) 
            {
                case 1: {
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
                            while (true){
                                try {
                                    int input;
                                    cin >> input;
                                    if (input == -1){
                                        break;
                                    } 
                                    if(cin.fail() || input < 1 || input > 10) {
                                        cin.clear();
                                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                        throw std::runtime_error("Neteisingas pažymys! Pažymys susidaro tik iš skaičių, turi būti tarp 1 ir 10");
                                    }
                                    stud.pazymiai.push_back(input);
                                } catch (const std::runtime_error &e){
                                    cout << e.what() << endl;
                                    continue;
                                }
                            }
                            while (true) {
                                try {
                                    int input;
                                    cout << "Įveskite studento egzamino pažymį" << endl;
                                    cin >> input;
                                    if(cin.fail() || input < 1 || input > 10) {
                                        cin.clear();
                                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                        throw std::runtime_error("Neteisingas egzamino pažymys! Pažymys susidaro tik iš skaičių, turi būti sveikas skaičius tarp 1 ir 10");
                                    }
                                    stud.egzaminas = input;
                                    break;
                                } catch (const std::runtime_error &e){
                                    cout << e.what() << endl;
                                    continue;
                                }
                            }

                            studentuSarasas.push_back(stud);
                        } catch (const std::runtime_error &e){
                            cout << e.what() << endl;
                            continue;
                        }
                    }
                    rodytiRezultatus(studentuSarasas);
                break;
                }

                case 2: {
                    cout << "Pasirinkote generuoti pažymius" << endl;
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
                            studentuSarasas.push_back(stud);
                        } catch (const std::runtime_error &e){
                        cout << e.what() << endl;
                        }
                    }

                    generuotiPazymius(studentuSarasas);
                    rodytiRezultatus(studentuSarasas);

                break;
                }

                case 3: {
                    cout << "Pasirinkote generuoti pažymius, studentų pavardes ir vardus" << endl;
                    cout << "---------------------------------" << endl;
                    generuotiStudentus(studentuSarasas);
                    generuotiPazymius(studentuSarasas);
                    rodytiRezultatus(studentuSarasas);
                break;
                }

                case 4: {
                    cout << "Pasirinkote nuskaityti duomenis iš failo" << endl;
                    cout << "----------------------------------------" << endl;
                    try {
                        string fail = pasirinktiFaila();
                        nuskaitytiFaila(fail, studentuSarasas);
                    } catch (const char* e){
                        cout << "Nuskaitymas nepavyko. " << e << endl;
                        break;
                    } catch (const std::runtime_error e){
                        cout << e.what();
                    }

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
                                rodytiVisusRezultatus(studentuSarasas);
                            } else if (rikiavimas == 2) {
                                rikiuotiPagalPavarde(studentuSarasas);
                                rodytiVisusRezultatus(studentuSarasas);
                            } else if (rikiavimas == 3) {
                                rikiuotiPagalGalutiniVid(studentuSarasas);
                                rodytiVisusRezultatus(studentuSarasas);
                            } else if (rikiavimas == 4) {
                                rikiuotiPagalGalutiniMed(studentuSarasas);
                                rodytiVisusRezultatus(studentuSarasas);
                            } else if (rikiavimas == 5) {
                                rodytiVisusRezultatus(studentuSarasas);
                                rodytiVisusRezultatus(studentuSarasas);
                            } else {
                                throw std::runtime_error("Neteisingas meniu pasirinkimas!");
                            }
                        } catch (std::runtime_error &e) {
                            cout << e.what() << endl;
                            continue;
                        }
                        break;
                    }
                break;
                }

                case 5: {
                    while(true){
                        try {
                        cout << "Pasirinkote testuoti programą" <<endl;
                        int kartai;
                        cout << "Kiek kartų norite nuskaityti failą?" << endl;
                        cin >> kartai;
                        if (cin.fail() || kartai < 1){
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            throw std::runtime_error("Neteisingas testų skaičiaus pasirinkimas");
                        }
                        testuotiFailuNuskaityma(studentuSarasas, kartai);
                    } catch (std::runtime_error &e){
                        cout << e.what() << endl;
                        continue;
                    }
                    break;
                }
                break;
                }
                    
                case 6: {
                    cout << "Pasirinkote generuoti failus" << endl;
                    int studentuKiekis;
                    cout << "Įveskite norimą studentų kiekį: " << endl;
                    cin >> studentuKiekis;
                    Timer t;
                    generuotiFailus(studentuKiekis);
                    cout << "Failą sukurti užtruko: " << t.elapsed() << " s\n";
                break;
                }

                case 7: {
                    cout << "Pasirinkote atlikti laiko matavimo tyrimą" << endl;
                    cout << "-----------------------------------------" << endl;
                    int kartai;
                    cout << "Kelis kartus norite tirti failą?" << endl;
                    cin >> kartai;

                    
                    string fail = pasirinktiFaila();
                    int rikiavimas;
                    cout << "Pasirinkite failo rikiavimo būdą: " << endl;
                    cout << "1 | Rikiuoti pagal vardą" << endl;
                    cout << "2 | Rikiuoti pagal pavardę" << endl;
                    cout << "3 | Rikiuoti pagal galutinį pažymį (su vidurkiu)" << endl;
                    cout << "4 | Rikiuoti pagal galutinį pažymį (su mediana)" << endl;
                    cout << "5 | Nerikiuoti" << endl;
                    while (true){
                        try{
                            cin >> rikiavimas;
                            if (cin.fail()){
                                cin.clear();
                                cin.ignore();
                                throw std::runtime_error("Neteisingas meniu pasirinkimas");
                            } else if (rikiavimas != 1 && rikiavimas != 2 && rikiavimas != 3 && rikiavimas != 4 && rikiavimas != 5){
                                throw std::runtime_error("Neteisingas meniu pasirinkimas");
                            }
                            break;
                        } catch (const std::runtime_error &e){
                            cout << e.what() << endl;
                            continue;
                        }
                    }
                    Timer p;
                    Timer p2;
                    for (int i = 0; i < kartai; i++){
                        p2.reset();
                    cout << endl;
                    cout << "----------------------------------------------------" << endl;
                    Timer f;
                    nuskaitytiFaila(fail, studentuSarasas);
                    cout << std::left << std::setw(60) << "Failą " + fail + " nuskaityti užtruko: " << std::right << std::setw(10) << std::to_string(f.elapsed()) + "s" << endl;
                    Timer r;
                    if (rikiavimas == 1) {
                        rikiuotiPagalVarda(studentuSarasas);
                        cout << std::left << std::setw(60) << "Rikiavimas užtruko: " << std::right << std::setw(10) << std::to_string(r.elapsed()) + "s" << endl;
                    } else if (rikiavimas == 2) {
                        rikiuotiPagalPavarde(studentuSarasas);
                        cout << std::left << std::setw(60) << "Rikiavimas užtruko: " << std::right << std::setw(10) << std::to_string(r.elapsed()) + "s" << endl;
                    } else if (rikiavimas == 3) {
                        rikiuotiPagalGalutiniVid(studentuSarasas);
                        cout << std::left << std::setw(60) << "Rikiavimas užtruko: " << std::right << std::setw(10) << std::to_string(r.elapsed()) + "s" << endl;
                    } else if (rikiavimas == 4) {
                        rikiuotiPagalGalutiniMed(studentuSarasas);
                        cout << std::left << std::setw(60) << "Rikiavimas užtruko: " << std::right << std::setw(10) << std::to_string(r.elapsed()) + "s" << endl;
                    } else if (rikiavimas == 5) {
                        cout << std::left << std::setw(60) << "Rikiavimas užtruko: 0s" << endl;
                    }
                    skirstytiStudentus(studentuSarasas); //viduje metodo laiko matavimas

                    cout << endl;
                    cout << std::left << std::setw(60) << "Iš viso programa užtruko: " << std::right << std::setw(10) << std::to_string(p2.elapsed()) + "s" << endl;
                    cout << "----------------------------------------------------" << endl;
                    cout << endl;
                }
                double vidutinisLaikas = p.elapsed() / (double)kartai;
                cout << endl;
                cout << std::left << std::setw(60) << "Iš viso vidutiniškai programa užtruko: " << std::right << std::setw(10) << std::to_string(vidutinisLaikas) + "s" << endl;
                cout << endl;
                break;
                }

                case 8: {
                    cout << "Programa baigta" << endl;
                    veikimas = false;
                break;
                }
            }
        } catch (const std::runtime_error &e) {
            cout << e.what() << endl;
            continue;
        }
    }
}