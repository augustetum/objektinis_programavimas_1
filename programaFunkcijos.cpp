#include "mano_lib.h"

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
    std::ostringstream buferis;
    buferis << std::left << std::setw(20) << "Pavardė" << std::setw(20) << "Vardas" << std::setw(20) << std::fixed << std::setprecision(2) << "Galutinis (Vid.)" << std::setw(20) << std::fixed << std::setprecision(2) << "Galutinis (Med.)" << endl;
    for (Studentas s: studentuSarasas){
        buferis << std::left << std::setw(20) << s.pavarde << std::setw(20) << s.vardas << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisVid << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisMed << endl;
    }

    int choice;
    cout << "Ar norėtumėte rezultatus matyti:" << endl;
    cout << "1 | Komandinėje eilutėje" << endl;
    cout << "2 | Faile" << endl;
    cin >> choice;

    if (choice == 1){
        cout << buferis.str();
    } else if (choice == 2){
        Timer t;
        std::ofstream failas("studentuRezultatai.txt");
        failas << buferis.str();
        failas.close();
        cout << "Failą išvesti užtruko: " << t.elapsed() << " s\n";
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
    ifstream failas("studentai1000000.txt");
    string eilut;
    int pazymys;

    getline(failas, eilut);

    
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
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
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now()-start; 
    std::cout << "Failo nuskaitymas užtruko: "<< diff.count() << " s\n";

    failas.close();
}

void skaitytiIsFailoSuBuf(vector<Studentas> &studentuSarasas){
    string eilut;
    int pazymys;
    std::stringstream buferis;
    
    system("ls *.txt > temp.txt");
    ifstream tempFail("temp.txt");
    vector<string> failuPav;
    std::unordered_set<string> nenorimiFailai = {"studentuRezultatai.txt", "firstNames.txt", "lastNames.txt"};
    string failoPav;
    while(getline(tempFail, failoPav)){
        if (nenorimiFailai.find(failoPav) == nenorimiFailai.end()) {
            failuPav.push_back(failoPav);
        }
    }
    tempFail.close();
    system("rm temp.txt");

    cout << "Pasirinkite norimą failą" << endl;
    for(int i = 1; i <= failuPav.size(); i++){
        cout << i << "| " << failuPav[i-1] << endl;
    }
    int choice;
    cin >> choice;
    if (choice < 1 || choice > failuPav.size()) {
        cout << "Neteisingas meniu pasirinkimas" << endl;
        return;
    }

    string fail = failuPav[choice-1];

    ifstream failas(fail);
    Timer t;
    buferis << failas.rdbuf();
    failas.close();

    getline(buferis, eilut);

    while(getline(buferis, eilut)){
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

    std::cout << "Procesas užtruko: "<< t.elapsed() << " s\n";

}

void rikiuotiPagalVarda(vector<Studentas> studentuSarasas){

    sort(studentuSarasas.begin(), studentuSarasas.end(), [](const Studentas& a, const Studentas& b) {
        return a.vardas < b.vardas;
    });

    rodytiVisusRezultatus(studentuSarasas);
}

void rikiuotiPagalPavarde(vector<Studentas> studentuSarasas){
    sort(studentuSarasas.begin(), studentuSarasas.end(), [](const Studentas& a, const Studentas& b) {
        return a.pavarde < b.pavarde;
    });

    rodytiVisusRezultatus(studentuSarasas);
}

void rikiuotiPagalGalutiniMed(vector<Studentas> studentuSarasas){
    sort(studentuSarasas.begin(), studentuSarasas.end(), [](const Studentas& a, const Studentas& b) {
        return a.galutinisMed < b.galutinisMed;
    });

    rodytiVisusRezultatus(studentuSarasas);
}

void rikiuotiPagalGalutiniVid(vector<Studentas> studentuSarasas){
    sort(studentuSarasas.begin(), studentuSarasas.end(), [](const Studentas& a, const Studentas& b) {
        return a.galutinisVid < b.galutinisVid;
    });

    rodytiVisusRezultatus(studentuSarasas);
}

void testuotiFailuNuskaityma(vector<Studentas> studentuSarasas, int kartai){
    string eilut;
    int pazymys;
    double duration;
    
    int choice;
    cout << "Įveskite norimą studentų kiekį (10000, 100000 ar 1000000)" << endl;
    cin >> choice;
    string fail;
    Timer t;
    
    if (choice == 10000){
        fail = "studentai10000.txt";
    } else if (choice == 100000) {
        fail = "studentai100000.txt";
    } else if (choice == 1000000) {
        fail = "studentai1000000.txt";
    } else {
        cout << "Neteisingas meniu pasirinkimas";
    }

    for (int x = 0; x < kartai; x++){
        ifstream failas(fail);
        std::stringstream buferis;
        studentuSarasas.clear();
        t.reset();
        buferis << failas.rdbuf();
        failas.close();

        getline(buferis, eilut);

        while(getline(buferis, eilut)){
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
        duration += t.elapsed();
    }

    double durationAvg = duration / kartai;

    std::cout << "Procesas vidutiniškai užtruko: "<< durationAvg << " s\n";

}