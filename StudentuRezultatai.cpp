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
