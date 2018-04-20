#include <iostream>
#include <vector>
#include <queue>
#include "Alphabetizer.cpp"
#include "CircularShifter.cpp"
#include "Input.cpp"
#include "Output.cpp"
#include "Reducer.cpp"
#include "Cleaner.cpp"

using namespace std;

// Main class that controls the flow of the whole
// pipes and filter sistem
int main() {
    // First filter, get the input
    Input inputParser = Input();
    vector<vector<string> > wordsByLine = inputParser.getInput();

    // Second filter
    vector<string> stopWords = inputParser.getStopWords(wordsByLine);
    Cleaner wordCleaner = Cleaner(wordsByLine, stopWords);
    wordsByLine = wordCleaner.removeWords();
    
    // Third filter, delete lines?
    vector<int> indexes = inputParser.getLinesToRemove(wordsByLine);
    Reducer reducer = Reducer(wordsByLine, indexes);
    wordsByLine = reducer.eraseLines();

    // Fourth filter, perform a rotation of the input
    CircularShifter shifter = CircularShifter(wordsByLine);
    vector<string> rotatedLines = shifter.rotateLines();

    // Fifith filter, sort the data
    Alphabetizer alphabetizer = Alphabetizer(rotatedLines);
    bool type;
    cout << "Do you want to sort it ascending(1) or descending(0)? ";
    cin >> type;
    vector<string> sortedLines = alphabetizer.sort(type);

    // Sixth filter, print the data
    Output printer = Output(sortedLines);
    printer.print();    

    return 0;
}
