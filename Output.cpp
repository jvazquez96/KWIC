#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Output {
	public:
		Output(vector<string> lines);
		void print();
	private:
		vector<string> lines;
};

Output::Output(vector<string> lines) {
	this->lines = lines;
}

void Output::print() {
	for (auto &i: lines) {
		cout << i << "\n";
	}
}