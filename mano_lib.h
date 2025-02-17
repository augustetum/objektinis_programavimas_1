#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <numeric>
#include <ctime>
#include <sstream>
#include <chrono>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::accumulate;
using std::ifstream;
using std::istringstream;

struct Studentas{
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinisMed, galutinisVid, pazymiuVidurkis;
    void skaiciuotiGalutiniSuVidurkiu();
    void skaiciuotiGalutiniSuMediana();
};

void rodytiRezultatus(vector<Studentas> studentuSarasas);
void generuotiPazymius(vector<Studentas> &studentuSarasas);
void generuotiStudentus(vector<Studentas> &studentuSarasas);
void skaitytiIsFailo(vector<Studentas> &studentuSarasas);
void rodytiVisusRezultatus(vector<Studentas> studentuSarasas);
