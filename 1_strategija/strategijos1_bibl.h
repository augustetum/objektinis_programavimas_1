#include <list>;
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