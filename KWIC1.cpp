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

queue<string> getInput(bool isFile, string fileName) {

    string line = "";
    queue<string> result;

    if(isFile) {
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

vector<string> splitLine(string line, char delimiter) {

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

vector<string> generateRotations(vector<string> line) {

    vector<string> results;
    string words = "";
    string rotatedWord = "";
    for(int j = 0; j < line.size(); j++) {
        for(int i = 0; i < line.size(); i++) {
            // get line into a single string
            words += line[i] + " ";
        }
        // add this rotation to the results
        results.push_back(words);

        // save the word at the start
        rotatedWord = line[0];

        // move word at the start to the end
        line.erase(line.begin());
        line.push_back(rotatedWord);

        // set words back to empty
        words = "";
    }
    
    return results;
}

void rotateLines(vector<vector<string> > v) {


    vector<string> rotatedLines(1);
    vector<string> aux;
    string line;
    for(int i = 0; i < v.size(); i++) {
        // for each line do the following, generate its rotations
        aux = generateRotations(v[i]);
        // append it to final vector 
        rotatedLines.insert(rotatedLines.end(), aux.begin(), aux.end());
    }
    rotatedLines.erase(rotatedLines.begin());

    // sort
    sort(rotatedLines.begin(), rotatedLines.end());
    // print result
    cout << "\n";
    printLines(rotatedLines);
}

void processInput(queue<string> lines) {

    string line;
    vector<vector<string> > wordsByLine;
    vector<string> inner;

    while(!lines.empty()) {

        // get line
        line = lines.front();

        // split into words and add it to vector of vectors
        inner = splitLine(line, ' ');
        wordsByLine.push_back(inner);

        // remove line from queue;
        lines.pop();
    }

    rotateLines(wordsByLine);

}


int main() {

    queue<string> linesList;
    string word, line, fileName = "";
    bool isFile = false;

    
    // check if input will come from a file or the command console
    isFile = askInputSource(fileName);
    
    // get the lines
    linesList = getInput(isFile, fileName);
    
    processInput(linesList);

	return 0;
}
