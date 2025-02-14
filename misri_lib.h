#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <numeric>
#include <ctime>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::accumulate;
using std::ifstream;

struct Studentas{
    string vardas, pavarde;
    int* pazymiai;
    int egzaminas;
    int pazymiuKiekis;
};

double skaiciuotiGalutiniSuVidurkiu(Studentas stud);
double skaiciuotiGalutiniSuMediana(Studentas stud);
void rodytiRezultatus(vector<Studentas> studentuSarasas);
void generuotiPazymius(vector<Studentas> &studentuSarasas);
void generuotiStudentus(vector<Studentas> &studentuSarasas);
void atlaisvintiAtminti(vector<Studentas> &studentuSarasas);
