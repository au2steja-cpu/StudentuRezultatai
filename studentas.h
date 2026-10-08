#include <numeric>
#include <string>
#include <vector>

enum class Rusiuoti { vardas, pavarde, pazymys };
constexpr double IslaikymoRiba = 5.0;

struct Studentas {
	std::string vardas, pavarde;
	std::vector<int> nd;
	int exam = 0;
	double galutinis = 0.0;
};

void skaiciuotiGalutini(Studentas& s);
void rusiuotiStudentus(std::vector<Studentas>& grupe, Rusiuoti r);
