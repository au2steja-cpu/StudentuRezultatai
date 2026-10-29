#include "failai.h"

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>

#include "utils.h"

using std::string;

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
	output << std::setw(utf8Plotis("Pavardė")) << "Pavardė";
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

bool arFailaiEgzistuoja(int min, int max) {
	for (int i = min; i <= max; i *= 10) {
		std::ifstream file(failoPavadinimas("kursiokai", i));
		if (!file.is_open()) return false;
	}
	return true;
}