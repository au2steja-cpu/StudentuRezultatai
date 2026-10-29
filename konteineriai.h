#pragma once
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include "studentas.h"
#include "utils.h"

template <typename C> struct KonteinerioVardas;
template <> struct KonteinerioVardas<std::vector<Studentas>> { static constexpr const char* vardas = "vector"; };
template <> struct KonteinerioVardas<std::list<Studentas>> { static constexpr const char* vardas = "list"; };

namespace detail {
	inline void rasytiAntraste(std::ostream& out) {
		out << std::left << std::setw(plotis) << "Vardas" << "|";
		out << std::setw(utf8Plotis("Pavardė")) << "Pavardė" << "|";
		out << std::setw(plotis) << "Galutinis" << "|\n";
	}

	inline void rasytiStudenta(std::ostream& out, const Studentas& s) {
		out << std::left << std::setw(utf8Plotis(s.vardas)) << s.vardas << "|";
		out << std::setw(utf8Plotis(s.pavarde)) << s.pavarde << "|";
		out << std::right << std::setw(plotis) << s.galutinis << "|\n";
	}

	template <typename C, typename Cmp>
	void rusiuoti(C& c, Cmp cmp) {
		using Kategorija = typename std::iterator_traits<typename C::iterator>::iterator_category;
		if constexpr (std::is_base_of_v<std::random_access_iterator_tag, Kategorija>) {
			std::sort(c.begin(), c.end(), cmp);
		}
		else {
			c.sort(cmp);
		}
	}
}

template <typename C>
void nuskaitytiStudentus(C& grupe, const std::string& filename) {
	std::ifstream ins(filename);
	if (!ins) throw std::runtime_error("Nepavyko atidaryti failo " + filename);

	std::string eilute;
	std::getline(ins, eilute);
	std::istringstream antraste(eilute);
	std::string zodis;
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

template <typename C>
void isvestiStudentus(const C& grupe, const std::string& filename) {
	std::ofstream out(filename);
	out << std::fixed << std::setprecision(2);
	detail::rasytiAntraste(out);
	for (const Studentas& s : grupe) {
		detail::rasytiStudenta(out, s);
	}
}

template <typename C>
void rusiuotiStudentus(C& grupe, Rusiuoti r) {
	switch (r) {
	case Rusiuoti::vardas:
		detail::rusiuoti(grupe, [](const Studentas& a, const Studentas& b) {
			if (a.vardas != b.vardas) return a.vardas < b.vardas;
			if (a.pavarde != b.pavarde) return a.pavarde < b.pavarde;
			return a.galutinis < b.galutinis;
			});
		break;
	case Rusiuoti::pavarde:
		detail::rusiuoti(grupe, [](const Studentas& a, const Studentas& b) {
			if (a.pavarde != b.pavarde) return a.pavarde < b.pavarde;
			if (a.vardas != b.vardas) return a.vardas < b.vardas;
			return a.galutinis < b.galutinis;
			});
		break;
	case Rusiuoti::galutinis:
		detail::rusiuoti(grupe, [](const Studentas& a, const Studentas& b) {
			if (a.galutinis != b.galutinis) return a.galutinis < b.galutinis;
			if (a.pavarde != b.pavarde) return a.pavarde < b.pavarde;
			return a.vardas < b.vardas;
			});
		break;
	}
}

template <typename C>
void dalintiStudentus(C& grupe, C& nuskriaustukai, C& kietukai) {
	for (Studentas& st : grupe) {
		(st.galutinis < IslaikymoRiba ? nuskriaustukai : kietukai).push_back(std::move(st));
	}
	grupe.clear();
}