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

bool askInputSource(string &fileName) {

    char answer = 'n';
    cout << "Input from a file? (y/n): ";
    cin >> answer;
    cin.ignore();
    if(tolower(answer) == 'y') {
        // input source is a file
        cout << "Enter a file name with its extension: ";
        cin >> fileName;
        cin.ignore();
        return true;
    } else {
        // input source is not a file
        return false;
    }
}

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
    string word, line, fileName = "";
    bool isFile = false;

    // check if input will come from a file or the command console
    isFile = askInputSource(fileName);
    Input inputParser = Input(isFile, fileName);
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
