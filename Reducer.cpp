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
        Reduccer();
        Reducer(vector<string> vInput);
        Reducer(vector<string> vInput, vector<int> vLines);

        // getters
        vector<string> getInputLines();
        vector<int> getLinesToReduce();

        // setters
        void setInputLines(vector<string> vI);
        void setReduceLines(vector<int> vR);

        // additional functions
        vector<string> eraseLines();
        void askForLines();
    // Attributes
    private:
        vector<string> vInput;
        vector<int> vLines; //contains the indexes of the liens to remove

};

Reducer::Reduccer() {
    // vectors get initialized on their own
}

Reducer::Reducer(vector<string> vInput) {
    this.vInput = vInput;
}

Reducer::Reducer(vector<string> vInput, vector<int> vLines) {
    this.vInput = vInput;
    this.vLines = vLines;
}

// getters
vector<string> Reducer::getInputLines() {
    return this.vInput;
}
vector<int> Reducer::getLinesToReduce() {
    return this.vLines;
}
// setters
void Reducer::setInputLines(vector<string> vI) {
    this.vInput = vI;
}
void Reducer::setReduceLines(vector<int> vR) {
    this.vLines = vR;
}
// additional
vector<string> Reducer::eraseLines() {
    // for the user line indexing starts at 1.
    // so we need to substract 1 to each line index given
    for(int i = 0; i < this.vLines.size(); i++) {
        line = this.vLines[i] - 1;
        this.vInput.erase(this.vInput.begin() + line);
    }
}
void Reducer::askForLines() {
    // empty vector of lines
    this.vLines.clear()
    // auxiliar variables
    int lines = 0, index = 0;

    cout << "How many lines you want to remove?\n";
    cin >> lines;
    for(int i = 0; i < lines; i++) {
        cout << "Enter line number(" << i + 1 << "): ";
        cin >> index;
        this.vLines.push_back(index);
    }
}
