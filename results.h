#pragma once
#include <ostream>
#include <string>
#include <vector>

struct Rezultatai {
	std::string konteineris;
	int dydis = 0;
	std::vector<double> nuskaitymai, galutiniai, rusiavimai, dalijimai,
		isvedimaiNuskriaustuku, isvedimaiKietuku, bendri;
};

void spausdintiLentele(std::ostream& out, const std::string& pavadinimas, const std::vector<Rezultatai>& visi);
void spausdintiPalyginima(std::ostream& out, const std::vector<Rezultatai>& vec, const std::vector<Rezultatai>& lst);