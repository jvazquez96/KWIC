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

using namespace std;


// Input class.
// Ask the user for the input. It can be directly type or received
// through a file.
// Example:
// Input foo = Input();
// foo.getInput()

class Input {
	public:
		Input();
		void askInputSource();
		vector<vector<string> > getInput();
	private:
		bool isFile;
		string fileName;
		vector<vector<string> > processInput(queue<string> lines);
		vector<string> splitLine(string line, char delimite);
};

// Empty constructor.
// Sets the private variables to a default variable.
Input::Input() {
	this->isFile = false;
	this->fileName = "";
}


// This function check whether the user wants to type the input data
// or if its comes from a file.
// If its comes from a file it sets a boolean flag to true, otherwise
// its false.
void Input::askInputSource() {
	char answer = 'n';
	cout << "Input from a file? (y/n): ";
	cin >> answer;
	cin.ignore();
	if (tolower(answer) == 'y') {
		cout << "Enter a file name with its extension: ";
		cin >> fileName;
		cin.ignore();
		this->isFile = true;
	} else {
		this->isFile = false;
	}
}

// This functions goes through all the file or the user input
// and stores it in a queue.
// The expected format of the input is a line with several words
// that end with a .(Period)
vector<vector<string> > Input::getInput()  {

	askInputSource();

	string line = "";
	queue<string> result;

	if (isFile) {
		// open file
		ifstream myFile(fileName);
		if(myFile.is_open()) {
			// process file if it was opened
			while (getline(myFile, line)) {
			// push line to queue
			result.push(line);
			}
			myFile.close();
		} else {
			cout << "File could not be opened.\n";
		}
	} else {
		// ask for lines
		int linesAmount = 0;
		string line = "";
		cout << "How many lines will there be? ";
		cin >> linesAmount;
		cin.ignore();
		while (linesAmount--) {
			// get line x
			getline(cin, line);
			result.push(line);
		}
	}
	return processInput(result);
}

// Function that process the received input. It split it into single
// words and stores it into a vector of vectors (matrix) of strings
vector<vector<string> > Input::processInput(queue<string> lines) {
	string line;
	vector<vector<string> > wordsByLine;
	vector<string> inner;

	while(!lines.empty()) {
		// get line
		line = lines.front();
		// split into words and add it to vectors of vectors
		inner = splitLine(line, ' ');
		wordsByLine.push_back(inner);
		// remove line from queue
		lines.pop();
	}
	return wordsByLine;
}

// Converts every word to lowercase and removes the period (if it has one)
// receives as a parameter a string that represents the line, and a delimitir
// always a ' ' (space)
vector<string> Input::splitLine(string line, char delimiter) {
	// convert all words to lower
	transform(line.begin(), line.end(), line.begin(),(int (*)(int))tolower);
	// remove "." periods
	line.erase(line.find("."));
	std::istringstream ss(line);
	string word;
	vector<string> v;
	while (getline(ss, word, delimiter)) {
		// push every single word to the vector
		v.push_back(word);
	}
	return v;
}