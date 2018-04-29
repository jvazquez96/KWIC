#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include "Alphabetizer.cpp"
#include "CircularShifter.cpp"
#include "Input.cpp"
#include "Output.cpp"
#include "Reducer.cpp"
#include "Cleaner.cpp"

using namespace std;

typedef vector<string> vs;


// Facade class.
// Hides the process from the client

class Facade {
	public:
        Facade();
        void run();
	private:
		Input inputParser;
        Cleaner wordCleaner;
        Reducer reducer;
        CircularShifter shifter;
        Alphabetizer alphabetizer;
        Output printer;
};

Facade::Facade() {
    this->inputParser = Input();
    this->wordCleaner = Cleaner();
    this->reducer = Reducer();
    this->shifter = CircularShifter();
    this->alphabetizer = Alphabetizer();
    this->printer = Output();

}

void Facade::run() {
    // First filter, get the input
    vector<vector<string> > wordsByLine = this->inputParser.getInput();

    // Second filter
    vector<string> stopWords = inputParser.getStopWords(wordsByLine);
    this->wordCleaner.setLines(wordsByLine);
    this->wordCleaner.setWords(stopWords);
    wordsByLine = wordCleaner.removeWords();
    
    // Third filter, delete lines?
    vector<int> indexes = inputParser.getLinesToRemove(wordsByLine);
    this->reducer.setInputLines(wordsByLine);
    this->reducer.setReduceLines(indexes);
    wordsByLine = reducer.eraseLines();

    // Fourth filter, perform a rotation of the input
    this->shifter.setLines(wordsByLine);
    vector<string> rotatedLines = shifter.rotateLines();

    // Fifith filter, sort the data
    Alphabetizer alphabetizer = Alphabetizer(rotatedLines);
    this->alphabetizer.setLines(rotatedLines);
    bool type;
    cout << "Do you want to sort it ascending(1) or descending(0)? ";
    cin >> type;
    vector<string> sortedLines = alphabetizer.sort(type);

    // Sixth filter, print the data
    this->printer.setLines(sortedLines);
    printer.print(); 
}


