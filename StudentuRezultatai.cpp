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
