#include <vector>
#include <string>
#include <iostream>

using namespace std;


// Output class.
// Prints a list of strings
class Output {
	public:
		Output();
		Output(vector<string> lines);
		void print();
		void setLines(vector<string> l);
	private:
		vector<string> lines;
};

Output::Output() {
	
}

// Set the private variable lines to the received parameters.
// The expected type is a vector of strings.
Output::Output(vector<string> lines) {
	this->lines = lines;
}

// Iterates through the private vector using the C++11 specifier auto.
// This allow us to not specify the data type and let the compiler
// automatically deduct the type which is easier for us.
void Output::print() {
	for (auto &i: lines) {
		cout << i << "\n";
	}
}

void Output::setLines(vector<string> l) {
	this->lines = l;
}