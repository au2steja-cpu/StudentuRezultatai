#include <string>
#include <vector>

#include "studentas.h"

std::string failoPavadinimas(const std::string& pradzia, int n);

void generuotiFaila(int n);
void nuskaitytiStudentus(std::vector<Studentas>& grupe, const std::string& filename);
void ivestiStudentus(const std::vector<Studentas>& grupe, const std::string& filename);
bool ArFailaiEgzistuoja(int min, int max);