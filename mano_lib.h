#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <numeric>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::accumulate;

struct Studentas{
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas;
};

double skaiciuotiGalutiniSuVidurkiu(Studentas stud){
    double sum = accumulate(stud.pazymiai.begin(), stud.pazymiai.end(),0);
    double pazymiuVidurkis = sum / (double)stud.pazymiai.size();
    double galutinis = 0.4 * pazymiuVidurkis + 0.6 * stud.egzaminas;
    return galutinis;
}

double skaiciuotiGalutiniSuMediana(Studentas stud){
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
}
