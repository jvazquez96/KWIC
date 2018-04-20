#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

typedef vector<string> vs;

// Alphabetizer class.
// Sorts a list of strings (ascending or descending)
// based on a received parameter
// Example:
// Alphabetizer foo = Alphabetizer(list_of_words)
// sortedAscendedList = foo.sort(true) Ascending
// sortedDescendedList = foo.sort(false) Descending

class Alphabetizer {
	public:
		Alphabetizer(vs lines);
		vs sort(bool type);
	private:
		void sortAscending();
		void sortDescending();
		// Used to store the lines
		vs lines;
};

// Sets the private variable lines to the received parameter.
// The expected data type is a vector of strings.
Alphabetizer::Alphabetizer(vs lines) {
	this->lines = lines;
}

// Sorts the list of strings in ascending order.
// This method is only called when the user calls the 
// sort method with a true value.
void Alphabetizer::sortAscending() {
	::sort(lines.begin(), lines.end(), less<string> ());
}

// Sorts the list of strings in descending order.
// This method is only called when the user calls the
// sort method with a false value.
void Alphabetizer::sortDescending() {
	::sort(lines.begin(), lines.end(), greater<string>());
}

// Public method that receives as a paremter a boolean.
// If it's true then the function will call the private
// method sortAscending otherwise the private method
// sortDescending is called.
// It returns the sortedlist
vs Alphabetizer::sort(bool type) {
	if (type == 1) { // Ascending
		sortAscending();
	} else { // Descending
		sortDescending();
	}
	return this->lines;
}