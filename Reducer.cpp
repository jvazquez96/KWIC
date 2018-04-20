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

class Reducer {
    // Methods
    public:
        // constructors
        Reducer();
        Reducer(vector<vector<string> > input);
        Reducer(vector<vector<string> > input, vector<int> lines);

        // getters
        vector<vector<string> > getInputLines();
        vector<int> getLinesToReduce();

        // setters
        void setInputLines(vector<vector<string> > vI);
        void setReduceLines(vector<int> vR);

        // additional functions
        vector<vector<string> > eraseLines();
        void askForLines();
    // Attributes
    private:
        vector<vector<string> > vInput;
        vector<int> vLines; //contains the indexes of the liens to remove

};

Reducer::Reducer() {
    // vectors get initialized on their own
}

Reducer::Reducer(vector<vector<string> > input) {
    this->vInput = input;
}

Reducer::Reducer(vector<vector<string> > input, vector<int> lines) {
    this->vInput = input;
    this->vLines = lines;
    ::sort(this->vLines.begin(), this->vLines.end(), less<int> ());
}

// getters
vector<vector<string> > Reducer::getInputLines() {
    return this->vInput;
}

vector<int> Reducer::getLinesToReduce() {
    return this->vLines;
}
// setters
void Reducer::setInputLines(vector<vector<string> > vI) {
    this->vInput = vI;
}
void Reducer::setReduceLines(vector<int> vR) {
    this->vLines = vR;
}
// additional
vector<vector<string> > Reducer::eraseLines() {
    // for the user line indexing starts at 1.
    // so we need to substract 1 to each line index given
    int counter = 0;
    int line = 0;
    int index = 0;
    for(int i = 0; i < this->vLines.size(); i++) {
        line = this->vLines[i] - 1;
        index = line - counter;
        this->vInput.erase(vInput.begin() + index);
        counter++;
    }
    return this->vInput;
}
void Reducer::askForLines() {
    // empty vector of lines
    this->vLines.clear();
    // auxiliar variables
    int lines = 0, index = 0;

    cout << "How many lines you want to remove?\n";
    cin >> lines;
    for(int i = 0; i < lines; i++) {
        cout << "Enter line number(" << i + 1 << "): ";
        cin >> index;
        this->vLines.push_back(index);
    }
}
