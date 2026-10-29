#include "results.h"

#include <iomanip>

#include "utils.h"

namespace {
	void header(std::ostream& out) {
		out << "| Studentu skaicius | Nuskaitymas | Galutiniu skaiciavimas | Rusiavimas | Dalijimas i 2 grupes "
			<< "| Nuskriaustuku isvedimas | Kietuku isvedimas | Viso |\n";
		out << "|---|---|---|---|---|---|---|---|\n";
	}
	void eilute(std::ostream& out, const Rezultatai& r) {
		out << "| " << r.dydis << " | " << vidurkis(r.nuskaitymai) << " s | "
			<< vidurkis(r.galutiniai) << " s | "
			<< vidurkis(r.rusiavimai) << " s | "
			<< vidurkis(r.dalijimai) << " s | "
			<< vidurkis(r.isvedimaiNuskriaustuku) << " s | "
			<< vidurkis(r.isvedimaiKietuku) << " s | "
			<< vidurkis(r.bendri) << " s |\n";
	}
}

void spausdintiLentele(std::ostream& out, const std::string& pavadinimas, const std::vector<Rezultatai>& visi) {
	out << std::fixed << std::setprecision(3);
	out << "### " << pavadinimas << "\n\n";
	header(out);
	for (const auto& r : visi) eilute(out, r);
	out << "\n";
}

void spausdintiPalyginima(std::ostream& out, const std::vector<Rezultatai>& vec, const std::vector<Rezultatai>& lst) {
	out << std::fixed << std::setprecision(3);
	out << "### Palyginimas: vector vs list\n\n";
	out << "| Studentu skaicius | Rusiavimas (vector) | Rusiavimas (list) | Dalijimas (vector) | Dalijimas (list) "
		<< "| Viso (vector) | Viso (list) |\n";
	out << "|---|---|---|---|---|---|---|\n";
	for (size_t i = 0; i < vec.size() && i < lst.size(); i++) {
		out << "| " << vec[i].dydis
			<< " | " << vidurkis(vec[i].rusiavimai) << " s | " << vidurkis(lst[i].rusiavimai) << " s"
			<< " | " << vidurkis(vec[i].dalijimai) << " s | " << vidurkis(lst[i].dalijimai) << " s"
			<< " | " << vidurkis(vec[i].bendri) << " s | " << vidurkis(lst[i].bendri) << " s |\n";
	}
	out << "\n";
}