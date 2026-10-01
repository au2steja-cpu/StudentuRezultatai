#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

struct Studentas {
	string vardas;
	string pavarde;
	vector<int> nd;
	int egz;
};

float vidurkis(const vector<int>& nd) {
	if (nd.empty())
		return 0.0f;

	float sum = 0.0f;
	for (int pazymys : nd) {
		sum += pazymys;
	}
	return sum / nd.size();
}

float mediana(vector<int> nd) {
	if (nd.empty())
		return 0.0f;
	sort(nd.begin(), nd.end());
	int n = nd.size();

	if (n % 2 == 0) {
		return (nd[(n / 2) - 1] + nd[n / 2]) / 2.0f;
	}
	else {
		return nd[n / 2];
	}
}

int gautiRandomPazymi(int min, int max) {
	static mt19937 gen(random_device{}());
	uniform_int_distribution<int> dist(min, max);
	return dist(gen);
}

void RankiniuBudu(vector<Studentas>& studentai) {
	Studentas s;

	cout << "\n--- Prideti Studenta ---\n";
	cout << "Vardas: ";
	cin >> s.vardas;

	cout << "Pavarde: ";
	cin >> s.pavarde;

	cout << "Iveskite egzamino pazymi (1-10): ";
	while (!(cin >> s.egz) || s.egz < 1 || s.egz > 10) {

		cout << "Neteisingai! Iveskite skaiciu tarp 1 ir 10: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int n;
	cout << "Iveskite namu darbu kieki (1-10): ";
	while (!(cin >> n) || n < 0 || n > 10) {
		cout << "Neteisingai! Iveskite skaiciu tarp 1 ir 10: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	for (int i = 0; i < n; i++) {
		int pazymys;
		cout << "Iveskite namu darbu pazymius" << (i + 1) << "(1-10): ";
		while (!(cin >> pazymys) || pazymys < 1 || pazymys > 10) {
			cout << "Neteisingai! Iveskite skaiciu tarp 1 ir 10: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		s.nd.push_back(pazymys);
	}
	studentai.push_back(s);
	cout << "Studentas pridetas sekmingai!\n";
}

void generuotiStudentus(vector<Studentas>& studentai) {
	int skaiciusStudentu;
	cout << "\n Kiek studentu norite generuoti? (1-1000): ";

	while (!(cin >> skaiciusStudentu) || skaiciusStudentu < 1 || skaiciusStudentu > 1000) {
		cout << "Neteisingai! Iveskite skaiciu tarp 1 ir 1000: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	const vector<string> vardai = { "Jonas", "Petras", "Ona", "Ieva", "Tomas", "Laura", "Mantas", "Aiste", "Darius", "Rasa" };
	const vector<string> pavarde = { "Jonaitis", "Petraitis", "Onaitis", "Ievaitis", "Tomas", "Lauraitis", "Mantaitis", "Aistaitis", "Darius", "Rasaitis" };

	for (int i = 0; i < skaiciusStudentu; i++) {
		Studentas s;
		s.vardas = vardai[gautiRandomPazymi(0, vardai.size() - 1)];
		s.pavarde = pavarde[gautiRandomPazymi(0, pavarde.size() - 1)];

		int ndKiekis = gautiRandomPazymi(1, 10);
		for (int j = 0; j < ndKiekis; j++) {
			s.nd.push_back(gautiRandomPazymi(1, 10));
		}
		s.egz = gautiRandomPazymi(1, 10);
		studentai.push_back(s);
	}
	cout << skaiciusStudentu << "studentu prideta sekmingai! \n";
}

bool cmp(const Studentas& s1, const Studentas& s2) {
	if (s1.vardas == s2.vardas) {
		return s1.pavarde < s2.pavarde;
	}
	return s1.vardas < s2.vardas;
}
void spausdintiStudentuRezultatus(vector<Studentas>& studentai) {
	if (studentai.empty()) {
		cout << "\n Kolkas studentu nera! \n";
		return;
	}
	sort(studentai.begin(), studentai.end(), cmp);

	cout << "\n Studentu rezultatai:\n";
	cout << "Pasirinkite metoda: \n";
	cout << "1. Vidurkis \n";
	cout << "2. Mediana \n";
	cout << "3. Abu \n";
	cout << "Jusu pasirinkimas: ";

	int pasirinkimas;

	while (!(cin >> pasirinkimas) || pasirinkimas < 1 || pasirinkimas > 3) {
		cout << "Neteisingai! Iveskite skaiciu tarp 1 ir 3: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << fixed << setprecision(2);

	if (pasirinkimas == 1) {
		cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << "Vidurkis \n";
		cout << "----------------------------------------\n";
		for (const auto& s : studentai) {
			cout << left << setw(15) << s.vardas << setw(15) << s.pavarde << vidurkis(s.nd) << "\n";
		}
	}
	else if (pasirinkimas == 2) {
		cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << "Mediana \n";
		cout << "----------------------------------------\n";
		for (const auto& s : studentai) {
			cout << left << setw(15) << s.vardas << setw(15) << s.pavarde << mediana(s.nd) << "\n";
		}

	}
	else if (pasirinkimas == 3) {
		cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(10) << "Vidurkis" << "Mediana \n";
		cout << "--------------------------------------------------\n";
		for (const auto& s : studentai) {
			cout << left << setw(15) << s.vardas << setw(15) << s.pavarde
				<< setw(12) << vidurkis(s.nd) << mediana(s.nd) << "\n";
		}
	}
}

void Meniu() {
	cout << "\n--- Studentu Rezultatai ---\n";
	cout << "1. Rankiniu budu prideti studenta\n";
	cout << "2. Generuoti studentus\n";
	cout << "3. Spausdinti studentu rezultatus\n";
	cout << "4. Baigti programa\n";
}

int main() {
	vector<Studentas> studentai;
	int pasirinkimas;

	do {
		Meniu();
		cout << "Jusu pasirinkimas:";

		while (!(cin >> pasirinkimas) || pasirinkimas < 1 || pasirinkimas > 4) {
			cout << "Neteisingai! Iveskite skaiciu tarp 1 ir 4: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (pasirinkimas) {
		case 1:
			RankiniuBudu(studentai);
			break;
		case 2:
			generuotiStudentus(studentai);
			break;
		case 3:
			spausdintiStudentuRezultatus(studentai);
			break;
		case 4:
			cout << "Programa baigta. \n";
		}
	}
	while (pasirinkimas != 4);
	return 0;
}