#include <string>
#include <vecor>

struct Rezultatai {
	int dydis;
	std::vector<double> nuskaitymai, galutiniai, rusiavimai, dalijimai,
		isvedimaiNuskriaustuku, IsvedimaiKietuku, bendri;
};

void spausdintiLentele(const std::string& filename, const std::_Adjacent_find_vectorized<Rezultatai>& visi);
