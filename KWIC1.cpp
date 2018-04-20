#include <iostream>
#include <vector>
#include <queue>
#include "Alphabetizer.cpp"
#include "CircularShifter.cpp"
#include "Input.cpp"
#include "Output.cpp"

using namespace std;


// Main class that controls the flow of the whole
// pipes and filter sistem
int main() {
    // First filter, get the input
    Input inputParser = Input();
    vector<vector<string> > wordsByLine = inputParser.getInput();

    // Second filter, perform a rotation of the input
   	CircularShifter shifter = CircularShifter(wordsByLine);
   	vector<string> rotatedLines = shifter.rotateLines();

   	// Third filter, sort the data
   	Alphabetizer alphabetizer = Alphabetizer(rotatedLines);
   	bool type;
   	cout << "Do you want to sort it ascending(1) or descending(0)" << endl;
   	cin >> type;
   	vector<string> sortedLines = alphabetizer.sort(type);

   	// Fourth filter, print the data
    Output printer = Output(sortedLines);
    printer.print();

	return 0;
}
