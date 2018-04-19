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

class Input {
	public:
		Input();
		void askInputSource();
		queue<string> getInput();
		vector<vector<string> > processInput(queue<string> lines);
	private:
		bool isFile;
		string fileName;
		vector<string> splitLine(string line, char delimite);
};

void Input::askInputSource() {
	char answer = 'n';
	cout << "Input from a file? (y/n): ";
	cin >> answer;
	cin.ignore();
	if (tolower(answer) == 'y') {
		// input source is a file
		cout << "Enter a file name with its extension: ";
		cin >> fileName;
		cin.ignore();
		this->isFile = true;
	} else {
		this->isFile = false;
	}
}

Input::Input() {
	this->isFile = false;
	this->fileName = "";
}

queue<string> Input::getInput()  {
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
	return result;
}

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