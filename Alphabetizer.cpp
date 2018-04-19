#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

typedef vector<string> vs;

class Alphabetizer {
	public:
		Alphabetizer(vs lines);
		vs sort(bool type);
	private:
		void sortAscending();
		void sortDescending();
		vs lines;
};


Alphabetizer::Alphabetizer(vs lines) {
	this->lines = lines;
}

void Alphabetizer::sortAscending() {
	::sort(lines.begin(), lines.end(), less<string> ());
}

void Alphabetizer::sortDescending() {
	::sort(lines.begin(), lines.end(), greater<string>());
}

vs Alphabetizer::sort(bool type) {
	if (type == 1) { // Ascending
		sortAscending();
	} else { // Descending
		sortDescending();
	}
	return this->lines;
}