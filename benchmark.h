#pragma once
#include <iostream>
#include <string>

#include "failai.h"
#include "konteineriai.h"
#include "results.h"
#include "timer.h"

template <typename C>
Rezultatai testuotiFaila(int dydis, int kartai, Rusiuoti rusiuoti) {
	const std::string vardas = KonteinerioVardas<C>::vardas;
	Rezultatai rez;
	rez.konteineris = vardas;
	rez.dydis = dydis;

	const std::string pavadinimas = failoPavadinimas("kursiokai", dydis);
	std::cout << "[" << vardas << "] Apdorojamas failas " << pavadinimas << "\n";

	for (int j = 0; j < kartai; j++) {
		std::cout << "  " << j + 1 << "-oji iteracija\n";
		Timer apdorojimas;
		Timer t;

		C grupe;
		nuskaitytiStudentus(grupe, pavadinimas);
		rez.nuskaitymai.push_back(t.elapsed());

		t.reset();
		for (Studentas& st : grupe) skaiciuotiGalutini(st);
		rez.galutiniai.push_back(t.elapsed());

		t.reset();
		rusiuotiStudentus(grupe, rusiuoti);
		rez.rusiavimai.push_back(t.elapsed());

		t.reset();
		C nuskriaustukai, kietukai;
		dalintiStudentus(grupe, nuskriaustukai, kietukai);
		rez.dalijimai.push_back(t.elapsed());

		t.reset();
		isvestiStudentus(nuskriaustukai, failoPavadinimas("nuskriaustukai_" + vardas + "_", dydis));
		rez.isvedimaiNuskriaustuku.push_back(t.elapsed());

		t.reset();
		isvestiStudentus(kietukai, failoPavadinimas("kietukai_" + vardas + "_", dydis));
		rez.isvedimaiKietuku.push_back(t.elapsed());

		rez.bendri.push_back(apdorojimas.elapsed());
		std::cout << "    nuskaitymas " << rez.nuskaitymai.back()
			<< " s | rūšiavimas " << rez.rusiavimai.back()
			<< " s | dalijimas " << rez.dalijimai.back()
			<< " s | viso " << rez.bendri.back() << " s\n";
	}
	return rez;
}