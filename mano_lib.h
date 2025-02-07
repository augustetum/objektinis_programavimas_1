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