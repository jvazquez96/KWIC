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
		Input(bool isFile, string fileName);
		queue<string> getInput();
	private:
		bool isFile;
		string fileName;
};

Input::Input(bool isFile, string fileName) {
	this->isFile = isFile;
	this->fileName = fileName;
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