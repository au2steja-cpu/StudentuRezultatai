#include "ivestis.h"

#include <iomanip>
#include <iostream>
#include <string>

#include "utils.h"

namespace {
	Studentas ivestiStudenta() {
		Studentas s;
		std::cout << "\n--- Naujas studentas ---\n";
		std::cout << "Vardas: ";
		std::getline(std::cin >> std::ws, s.vardas);
		std::cout << "Pavardė: ";
		std::getline(std::cin >> std::ws, s.pavarde);
		const int n = ivestiSkaiciu("Namų darbų kiekis (0-20): ", 0, 20);
		for (int i = 0; i < n; i++) {
			s.paz.push_back(ivestiSkaiciu("Namų darbo pažymys " + std::to_string(i + 1) + " (1-10): ", 1, 10));
		}
		s.exam = ivestiSkaiciu("Egzamino pažymys (1-10): ", 1, 10);
		skaiciuotiGalutini(s);
		return s;
	}

	template <typename C>
	void spausdintiSuAdresais(const std::string& pavadinimas, const C& grupe) {
		std::cout << "\n=== " << pavadinimas << " (elementų: " << grupe.size() << ") ===\n";
		std::cout << std::left << std::setw(utf8Plotis("Vardas")) << "Vardas"
			<< std::setw(utf8Plotis("Pavardė")) << "Pavardė"
			<< std::setw(12) << "Galutinis" << "Adresas\n";
		std::cout << std::fixed << std::setprecision(2);
		for (const Studentas& s : grupe) {
			std::cout << std::left << std::setw(utf8Plotis(s.vardas)) << s.vardas
				<< std::setw(utf8Plotis(s.pavarde)) << s.pavarde
				<< std::setw(12) << s.galutinis
				<< static_cast<const void*>(&s) << "\n";
		}
	}
}

void rankinisIvedimas() {
	std::vector<Studentas> vec;
	std::list<Studentas> lst;

	do {
		Studentas s = ivestiStudenta();
		vec.push_back(s);
		lst.push_back(std::move(s));
	} while (taipArNe("Ar įvesti dar vieną studentą? [y/n] "));

	spausdintiSuAdresais("std::vector", vec);
	spausdintiSuAdresais("std::list", lst);
	std::cout << "\nPastaba: std::vector elementai guli vienas šalia kito (adresų skirtumas = sizeof(Studentas) = "
		<< sizeof(Studentas) << " B), o std::list elementai išsklaidyti atmintyje (kiekvienas mazgas "
		<< "alokuojamas atskirai).\n";
}