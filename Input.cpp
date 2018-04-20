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
		vector<int> getLinesToRemove(vector<vector<string> > input);
		vector<string> getStopWords(vector<vector<string> > lines);
	private:
		bool isFile;
		string fileName;
		vector<vector<string> > processInput(queue<string> lines);
		vector<string> splitLine(string line);
		vector<int> indexes;
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

vector<string> Input::getStopWords(vector<vector<string> > lines) {
	char ask = ' ';
	vector<string> stopWords;
	cout << "Do you want to erase some words from the input(y/n)? ";
	cin >> ask;
	while(ask != 'y' && ask != 'n') {
			cout << "Error: Answer should be 'y' or 'n'\n";
			cout << "Do you want to erase some words from the input(y/n)? ";
			cin >> ask;
	}
	if(ask == 'y') {
			int amount = 0;
			string word = "";
			cout << "How many words? ";
			cin >> amount;
			for(int i = 0; i < amount; i++) {
					cout << "Word #" << i+1 << ": ";
					cin >> word;
					stopWords.push_back(word);            
			}
	}
	return stopWords;
}

// This function asks for the indexes of the lines to remove from 
// the original input
vector<int> Input::getLinesToRemove(vector<vector<string> > input) {
	vector<int> indexes;
	cout << "Do you want to delete lines from the original input? (y/n)? ";
	char isDelete = ' ';
	cin >> isDelete;
	while(isDelete != 'y' && isDelete != 'n') {
		cout << "Error: Answer should be 'y' or 'n'\n";
		cout << "Do you want to delete lines from the original input? (y/n)? ";
		cin >> isDelete;
	}
	if (isDelete == 'y') {
      int number_lines_reduced = -1;
			cout << "How many lines do you want to remove? ";
      cin >> number_lines_reduced;
      while (number_lines_reduced < 0 or number_lines_reduced >= input.size()) {
        if (number_lines_reduced < 0) {
          cout << "Error: Please enter a positive number of lines." << endl;
        } else if (number_lines_reduced >= input.size()) {
          cout << "Error: Please enter a number lower than the number of lines." << endl;
        }
				cout << "How many lines do you want to remove? ";
      	cin >> number_lines_reduced;
      }
      int index;
      
      while (number_lines_reduced) {
        do {
          cout << "Enter the index of line you want to delete: ";
          cin >> index;
          if (index < 0) {
            cout << "Error: Please make sure to enter a number greater than 0." << endl;
          } else if (index > input.size()) {
            cout << "Error: Please make sure to enter an index that does not exceed the number of lines." << endl;
          } else if (find(indexes.begin(), indexes.end(), index) != indexes.end()) {
            cout << "Error: Please make sure not to enter repeated indexes" << endl;
            cout << "The current indexes are: " << endl;
            for (auto &i: indexes) {
              cout << i << " ";
            }
            cout << endl;
          }
        } while ((index < 0 or index > number_lines_reduced > input.size()) or find(indexes.begin(), indexes.end(), index) != indexes.end());
        indexes.push_back(index);
        --number_lines_reduced;
      }
    }
	return indexes;
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
		cout << "Enter your input:\n";
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
		inner = splitLine(line);
		wordsByLine.push_back(inner);
		// remove line from queue
		lines.pop();
	}
	return wordsByLine;
}

// Converts every word to lowercase and removes the period (if it has one)
// receives as a parameter a string that represents the line, and a delimitir
// always a ' ' (space)
vector<string> Input::splitLine(string line) {
	// convert all words to lower
	transform(line.begin(), line.end(), line.begin(),(int (*)(int))tolower);
	// remove all "." periods
	line.erase(remove(line.begin(), line.end(), '.'), line.end());
	istringstream iss(line);
    vector<string> v(istream_iterator<string>{iss},
                                 istream_iterator<string>());

	return v;
}