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

// Cleaner class.
// Erase some words from some lines (vector<vector<string> >)
class Cleaner {
	public:
		Cleaner();
        Cleaner(vector<vector<string> > newLines);
        Cleaner(vector<string> newWords);
        Cleaner(vector<vector<string> > newLines, vector<string> newWords);

        // getters
        vector<vector<string> > getLines();
        vector<string> getWords();

        // setters
        void setLines(vector<vector<string> > l);
        void setWords(vector<string> w);

        // extra
        vector<vector<string> > removeWords();
        vector<vector<string> > removeWords(vector<string> w);
	private:
		vector<vector<string> > lines;
        vector<string> words;
};

// Empty constructor.
// Sets the private variables to a default variable.
Cleaner::Cleaner() {
    // a vector initializes by itself to empty
}

Cleaner::Cleaner(vector<vector<string> > newLines) {
    this->lines = newLines;
}

Cleaner::Cleaner(vector<string> newWords) {
    this->words = newWords;
}

Cleaner::Cleaner(vector<vector<string> > newLines, vector<string> newWords) {
    this->lines = newLines;
    this->words = newWords;
}

vector<vector<string> > Cleaner::getLines() {
    return this->lines;
}

vector<string> Cleaner::getWords() {
    return this->words;
}

void Cleaner::setLines(vector<vector<string> > l) {
    this->lines = l;
}

void Cleaner::setWords(vector<string> w) {
    this->words = w;
}

vector<vector<string> > Cleaner::removeWords() {
    // for each word
    vector<vector<string> > temp = this->lines;
    string w = "";
    for(int i = 0; i < this->words.size(); i++) {
        w = this->words[i];
        // delete the word for each line
        for(int j = 0; j < temp.size(); j++) {
            for(int k = 0; k < temp[j].size(); k++) {
                // delete the word if it is an stop word
                if(temp[j][k] == w) {
                    temp[j].erase(temp[j].begin() + k);
                }
            }
        }
    }
    return temp; 
}
vector<vector<string> > Cleaner::removeWords(vector<string> w){
    this->words = w;
    return this->removeWords();
}


