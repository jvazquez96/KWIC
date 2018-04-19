#include <algorithm>
#include <string>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <sstream>
#include "Alphabetizer.cpp"
#include "CircularShifter.cpp"
#include "Input.cpp"

using namespace std;

void printLines(vector<string> lines) {
	Alphabetizer alphabetizer = Alphabetizer(lines);
	bool type ;// Ascending
	cout << "Do you want to sort it your ascending(1) or descending(0)" << endl;
	cin >> type;
	vector<string> sortedLines = alphabetizer.sort(type);
	for (auto &i : sortedLines) {
		cout << i << endl;
	}
}

int main() {
    queue<string> linesList;

    Input inputParser = Input();
	// check if input will come from a file or the command console
    inputParser.askInputSource();

    // get the stuff again
    linesList = inputParser.getInput();
    
    // Get the stuff again
    vector<vector<string> > wordsByLine = inputParser.processInput(linesList);

    // Circular shift the stuff
   	CircularShifter shifter = CircularShifter(wordsByLine);
   	vector<string> rotatedLines = shifter.rotateLines();

   	// Print stuff
    printLines(rotatedLines);

	return 0;
}
