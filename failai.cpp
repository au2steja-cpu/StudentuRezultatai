#include "failai.h"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>

#include "utils.h"

using std::string;
using std::vector;

namespace {

	void rasytiAntraste(std::ostream& out) {
		out << std::left << std::setw(plotis) << "Vardas" << "|";
		out << std::setw(utf8Plotis("Pavarde")) << "Pavarde" << "|";
		out << std::setw(plotis) << "Galutinis" << "|\n";
	}

	void rastiStudenta(std::ostream& out, const Studentas& s) {
		out << std::left << std::setw(utf8Plotis(s.vardas)) << s.vardas << "|";
		out << std::setw(utf8Plotis(s.pavarde)) << s.pavarde << "|";
		out << std::right << std::setw(plotis) << s.galutinis << "|\n";
	}
}

string failoPavadinimas(const string& pradzia, int n) {
	return pradzia + std::to_string(n) + ".txt";
}

void generuotiFaila(const int n) {
	const auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 gen(static_cast<std::mt19937::result_type>(seed));
	std::uniform_int_distribution<int> pazymiuDist(min_paz, max_paz);
	std::uniform_int_distribution<int> ndDist(1, 20);
	const int ndKiekis = ndDist(gen);

	const string pavadinimas = failoPavadinimas("kursiokai", n);
	std::cout << "Generuojamas failas " << pavadinimas << "\n";
	std::ofstream output(pavadinimas);

	output << std::left << std::setw(plotis) << "Vardas";
	output << std::setw(utf8Plotis("Pavarde")) << "Pavarde";
	for (int i = 0; i < ndKiekis; i++) {
		output << std::setw(plotis) << "Nd" + std::to_string(i + 1);
	}
	output << std::setw(plotis) << "Egzaminas" << "\n";

	for (int i = 0; i < n; i++) {
		output << std::left << std::setw(plotis) << "Vardenis" + std::to_string(i + 1);
		output << std::setw(plotis) << "Pavardenis" + std::to_string(i + 1);
		output << std::right;
		for (int j = 0; j < ndKiekis; j++) {
			output << std::setw(plotis) << pazymiuDist(gen);
		}
		output << std::setw(plotis) << pazymiuDist(gen) << "\n";
	}
}

void nuskaitytiStudentus(vectos<Studentas>& grupe, const string& filename) {
	std::ifstream ins(filename);
	if (!ins) throw std::runtime_error("Nepavyko atidaryti failo " + filename);

	string eilute;
	std::getline(ins, eilute);
	std::istringstream antraste(eilute);
	string zodis;
	int stulpeliu = 0;
	while (antraste >> zodis) stulpeliu++;
	const int pazKiekis = std::max(stulpeliu - 3, 0);

	while (std::getline(ins, eilute)) {
		Studentas s;
		std::istringstream duomenys(eilute);
		duomenys >> s.vardas >> s.pavarde;
		s.paz.reserve(pazKiekis);
		for (int i = 0; i < pazKiekis; i++) {
			int num;
			duomenys >> num;
			s.paz.push_back(num);
		}
		duomenys >> s.exam;
		grupe.push_back(std::move(s));
	}
}
void isvestiStudentus(const vector<Studentas>& grupe, const string& filename) {
	std::ofstream out(filename);
	out << std::fixed << std::setprecision(2);

	rasytiAntraste(out);
	for (const Studentas& s : grupe) {
		rasytiStudenta(out, s);
	}
}
bool arFailaiEgzistuoja(int min, int max) {
	for (int i = min; i <= max; i *= 10) {
		std::ifstream file(failoPavadinimas("kursiokai", i));
		if (!file.is_open()) {
			return false;
		}
	}
	return true;
}