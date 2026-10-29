#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

#include "benchmark.h"
#include "failai.h"
#include "ivestis.h"
#include "results.h"
#include "studentas.h"
#include "timer.h"
#include "utils.h"

namespace {
	void testavimas(int maxFailas) {
		constexpr int MINFAILAS = 1000;
		constexpr int KARTAI = 5;

		std::cout << "Pagal ka rusiuoti isvesties failus?\n"
			<< "[0] - Varda\n[1] - Pavarde\n[2] - Galutini bala\n";
		const auto rusiuoti = static_cast<Rusiuoti>(ivestiSkaiciu("Pasirinkimas: ", 0, 2));

		if (!arFailaiEgzistuoja(MINFAILAS, maxFailas) || taipArNe("Ar generuoti naujus failus? [y/n] ")) {
			Timer visas;
			for (int i = MINFAILAS; i <= maxFailas; i *= 10) {
				Timer t;
				generuotiFaila(i);
				std::cout << "  Generavimas uztruko: " << t.elapsed() << " s\n";
			}
			std::cout << "Visu failu generavimas uztruko: " << visas.elapsed() << " s\n\n";
		}

		std::vector<Rezultatai> rezVector, rezList;
		for (int i = MINFAILAS; i <= maxFailas; i *= 10) {
			rezVector.push_back(testuotiFaila<std::vector<Studentas>>(i, KARTAI, rusiuoti));
			rezList.push_back(testuotiFaila<std::list<Studentas>>(i, KARTAI, rusiuoti));
		}

		std::ofstream out("rezultatai.md");
		spausdintiLentele(out, "std::vector", rezVector);
		spausdintiLentele(out, "std::list", rezList);
		spausdintiPalyginima(out, rezVector, rezList);
		std::cout << "\nRezultatų lentelės įrašytos į rezultatai.md\n";
	}
}

int main(int argc, char* argv[]) {
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
#endif
	const int maxFailas = argc > 1 ? std::stoi(argv[1]) : 10000000;
	std::cout << std::fixed << std::setprecision(3);

	std::cout << "--- Studentu rezultatai v0.3 ---\n"
		<< "[1] - Rankinis ivedimas (rodomi objektu atminties adresai)\n"
		<< "[2] - Konteinerių testavimas (vector vs list)\n"
		<< "[0] - Iseiti\n";
	switch (ivestiSkaiciu("Pasirinkite programos rezima: ", 0, 2)) {
	case 1: rankinisIvedimas(); break;
	case 2: testavimas(maxFailas); break;
	default: break;
	}
}