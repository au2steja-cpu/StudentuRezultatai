#include <limits>
#include <numeric>
#include <string>
#include <vector>

constexpr int min_paz = 0;
constexpr int max_paz = 10;
constexpr int be_ribos = std::numeric_limits<int>::max();
constexpr int plotis = 20;

size_t utf8Ilgis(const std::string& tekstas);

int utf8Plotis(const std::string& tekstas);

int ivestiSkaiciu(const std::string& klausimas, int nuo, int iki);

bool taipArNe(const std::string& klausimas);

template <typename T>
double vidurkis(const std::vector<T>& v) {
	if (v.empty()) return 0.0;
	return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}