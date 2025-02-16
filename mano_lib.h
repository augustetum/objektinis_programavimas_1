#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <numeric>
#include <ctime>
#include <sstream>

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
};

double skaiciuotiGalutiniSuVidurkiu(Studentas stud);
double skaiciuotiGalutiniSuMediana(Studentas stud);
void rodytiRezultatus(vector<Studentas> studentuSarasas);
void generuotiPazymius(vector<Studentas> &studentuSarasas);
void generuotiStudentus(vector<Studentas> &studentuSarasas);
