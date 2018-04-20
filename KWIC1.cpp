#include <iostream>
#include <vector>
#include <queue>
#include "Alphabetizer.cpp"
#include "CircularShifter.cpp"
#include "Input.cpp"
#include "Output.cpp"

using namespace std;

int main() {
    queue<string> linesList;

    // Get the input
    Input inputParser = Input();
    vector<vector<string> > wordsByLine = inputParser.getInput();

    // Circular shift the stuff
   	CircularShifter shifter = CircularShifter(wordsByLine);
   	vector<string> rotatedLines = shifter.rotateLines();

   	// Sort the stuff
   	Alphabetizer alphabetizer = Alphabetizer(rotatedLines);
   	bool type;
   	cout << "Do you want to sort it ascending(1) or descending(0)" << endl;
   	cin >> type;
   	vector<string> sortedLines = alphabetizer.sort(type);

   	// Print stuff
    Output printer = Output(sortedLines);
    printer.print();

	return 0;
}
