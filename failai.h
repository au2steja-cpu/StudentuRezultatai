#pragma once
#include <string>
#include <vector>

#include "studentas.h"

std::string failoPavadinimas(const std::string& pradzia, int n);

void generuotiFaila(int n);
void nuskaitytiStudentus(std::vector<Studentas>& grupe, const std::string& filename);
void isvestiStudentus(const std::vector<Studentas>& grupe, const std::string& filename);
bool arFailaiEgzistuoja(int min, int max);