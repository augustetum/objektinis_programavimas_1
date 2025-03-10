#ifndef STRATEGIJOS1_BIBL_H
#define STRATEGIJOS1_BIBL_H

#include <list>
#include "../mano_lib.h"

using std::deque;
using std::list;

template <typename Container> 
void nuskaitytiFailaT(string fail, Container &studentuSarasas){
    string eilut;
    int pazymys;
    std::stringstream buferis;
    ifstream failas(fail);
            if (!failas.is_open()){
                throw std::runtime_error("Failo nepavyko atidaryti arba jis neegzistuoja šiame aplankale");
            }

            buferis << failas.rdbuf();
            failas.close();

            getline(buferis, eilut);

            while(getline(buferis, eilut)){
                Studentas stud;
                istringstream eilute(eilut);
                eilute >> stud.vardas >> stud.pavarde;

                if (eilute.eof()) {
                    throw "Netinkamas failo formatas: faile nėra pažymių";
                }
                
                while(true){
                    eilute >> pazymys;
                    if (eilute.fail()){
                        if (eilute.eof()){
                            break;
                        }
                        eilute.clear();
                        eilute.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw "Netinkamas failo formatas: pažymiai nėra skaitinės reikšmės";
                    }
                    if (pazymys < 1 || pazymys > 10){
                        throw "Netinkamas failo formatas: pažymiai nėra sveiki skaičiai ribose nuo 1 iki 10";
                    }
                    stud.pazymiai.push_back(pazymys);
                }
                if (!stud.pazymiai.empty()) {
                    stud.egzaminas = stud.pazymiai.back();
                    stud.pazymiai.pop_back();
                } else {
                    throw "Netinkamas failo formatas: faile nėra pažymių";
                }
                stud.skaiciuotiGalutiniSuMediana();
                stud.skaiciuotiGalutiniSuVidurkiu();

                studentuSarasas.push_back(stud);
            }
}

template <typename Container>
void rikiuotiPagalVardaT(Container &studentuSarasas){
    if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
        studentuSarasas.sort([](const Studentas &a, const Studentas &b) {
            return a.vardas < b.vardas;
        });
    } else {
        sort(studentuSarasas.begin(), studentuSarasas.end(), [](const Studentas& a, const Studentas& b) {
            return a.vardas < b.vardas;
        });

    }
}

template <typename Container>
void rikiuotiPagalPavardeT(Container &studentuSarasas){
    if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
        studentuSarasas.sort([](const Studentas &a, const Studentas &b) {
            return a.pavarde < b.pavarde;
        });
    } else {
        sort(studentuSarasas.begin(), studentuSarasas.end(), [](const Studentas& a, const Studentas& b) {
            return a.pavarde < b.pavarde;
        });

    }
}

template <typename Container>
void rikiuotiPagalGalutiniMedT(Container &studentuSarasas){
    if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
        studentuSarasas.sort([](const Studentas &a, const Studentas &b) {
            return a.galutinisMed < b.galutinisMed;
        });
    } else {
        sort(studentuSarasas.begin(), studentuSarasas.end(), [](const Studentas& a, const Studentas& b) {
            return a.galutinisMed < b.galutinisMed;
        });

    }
}

template <typename Container>
void rikiuotiPagalGalutiniVidT(Container &studentuSarasas){
    if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
        studentuSarasas.sort([](const Studentas &a, const Studentas &b) {
            return a.galutinisVid < b.galutinisVid;
        });
    } else {
        sort(studentuSarasas.begin(), studentuSarasas.end(), [](const Studentas& a, const Studentas& b) {
            return a.galutinisVid < b.galutinisVid;
        });

    }
}

template <typename Container>
void skirstytiStudentusSuTaisPaciaisKonteineriaisT(Container &studentuSarasas){
    Timer t;
    Container nepazangus;
    Container pazangus;
    for(Studentas s : studentuSarasas){
        if (s.galutinisVid < 5){
            nepazangus.push_back(s);
        } else if (s.galutinisVid >= 5){
            pazangus.push_back(s);
        }
    }

    if constexpr(std::is_same_v<Container, vector<Studentas>> || std::is_same_v<Container, deque<Studentas>>){
        nepazangus.shrink_to_fit();
        pazangus.shrink_to_fit();
    }
    isvestiDuFailusT(nepazangus, pazangus);
}

template <typename Container>
void isvestiDuFailusT(Container grupe1, Container grupe2){
    Timer v;
    std::ostringstream buferis;
    buferis << std::left << std::setw(20) << "Pavardė" << std::setw(20) << "Vardas" << std::setw(20) << std::fixed << std::setprecision(2) << "Galutinis (Vid.)" << std::setw(20) << std::fixed << std::setprecision(2) << "Galutinis (Med.)" << endl;
    for (Studentas s: grupe1){
        buferis << std::left << std::setw(20) << s.pavarde << std::setw(20) << s.vardas << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisVid << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisMed << endl;
    }
    std::ofstream failas1("nepazangus.txt");
    failas1 << buferis.str();
    failas1.close();

    Timer k;
    std::ostringstream buferis2;
    buferis2 << std::left << std::setw(20) << "Pavardė" << std::setw(20) << "Vardas" << std::setw(20) << std::fixed << std::setprecision(2) << "Galutinis (Vid.)" << std::setw(20) << std::fixed << std::setprecision(2) << "Galutinis (Med.)" << endl;
    for (Studentas s: grupe2){
        buferis2 << std::left << std::setw(20) << s.pavarde << std::setw(20) << s.vardas << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisVid << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisMed << endl;
    }

    std::ofstream failas2("pazangus.txt");
    failas2 << buferis2.str();
    failas2.close();

}

#endif