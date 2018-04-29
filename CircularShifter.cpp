#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

typedef vector<string> vs;


// CircularShifter class.
// Performs a circular shift of a series of line.
// The constructor takes a vector of vectors (matrix) of strings
// and for each line it performs the rotation and it stores it 
// vector

class CircularShifter {
	public:
		CircularShifter();
		CircularShifter(vector<vector<string> > lines);
		vs rotateLines();
		// setter
		void setLines(vector<vector<string> > newLines);
	private:
		vector<vector<string> > lines;
		vs generateRotations(vector<string> line);
};

CircularShifter::CircularShifter(){
	
}

// Constructor that takes as a parameter a matrix of strings
CircularShifter::CircularShifter(vector<vector<string> > lines) {
	this->lines = lines;
}


// Private function that receives a vector of strings
// and performs a rotation
vs CircularShifter::generateRotations(vector<string> line) {
	vector<string> results;
	string words = "";
	string rotatedWord = "";
	for (int j = 0; j < line.size(); ++j) {
		for (int i = 0; i < line.size(); ++i) {
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

		// set the words back to empty
		words = "";
	}
	return results;
}

// Public function that for each line it rotates it
// and returns the vector that contains all the strings.
vs CircularShifter::rotateLines() {
	vector<string> rotatedLines(1);
	vector<string> aux;
	string line;
	for (int i = 0; i < lines.size(); ++i) {
		// for each line do the following, generate its rotations
		aux = generateRotations(lines[i]);
		// append it to final vector
		rotatedLines.insert(rotatedLines.end(), aux.begin(), aux.end());
	}
	rotatedLines.erase(rotatedLines.begin());
	return rotatedLines;
}

void CircularShifter::setLines(vector<vector<string> > newLines) {
	this->lines = newLines;
}