#include <iostream>
#include <vector>
#include <queue>
#include "Alphabetizer.cpp"
#include "CircularShifter.cpp"
#include "Input.cpp"
#include "Output.cpp"
#include "Reducer.cpp"

using namespace std;


// Main class that controls the flow of the whole
// pipes and filter sistem
int main() {
    // First filter, get the input
    Input inputParser = Input();
    vector<vector<string> > wordsByLine = inputParser.getInput();

    // Second filter, delete files?
    cout << "Do you want to delete lines from the original file? yes(1), no(0)" << endl;
    bool isDelete = false;
    cin >> isDelete;
    if (isDelete) {
      int number_lines_reduced = 0;
      do {
        cout << "How many lines do you want to reduce?" << endl;
        cin >> number_lines_reduced;
        if (number_lines_reduced < 0) {
          cout << "Please enter a positive number of lines" << endl;
        } else if (number_lines_reduced > wordsByLine.size()) {
          cout << "Please enter a number less than the number of lines" << endl;
        }
      } while (number_lines_reduced < 0 or number_lines_reduced > wordsByLine.size());
      int index;
      vector<int> indexes;
      while (number_lines_reduced) {
        do {
          cout << "Enter the index of line you want to delete" << endl;
          cin >> index;
          if (index < 0) {
            cout << "Please make sure to enter a number greater than 0" << endl;
          } else if (index > wordsByLine.size()) {
            cout << "Please make sure to enter a number less than the size of the list of words" << endl;
          } else if (find(indexes.begin(), indexes.end(), index) != indexes.end()) {
            cout << "Please make sure not to enter a repeated indexes" << endl;
            cout << "The current indexes are: " << endl;
            for (auto &i: indexes) {
              cout << i << " ";
            }
            cout << endl;
          }
        } while ((index < 0 or index > number_lines_reduced > wordsByLine.size()) or find(indexes.begin(), indexes.end(), index) != indexes.end());
        indexes.push_back(index);
        --number_lines_reduced;
      }
      Reducer reducer = Reducer(wordsByLine, indexes);
      wordsByLine = reducer.eraseLines();
    }

    // Thrids filter, perform a rotation of the input
   	CircularShifter shifter = CircularShifter(wordsByLine);
   	vector<string> rotatedLines = shifter.rotateLines();

   	// Fourth filter, sort the data
   	Alphabetizer alphabetizer = Alphabetizer(rotatedLines);
   	bool type;
   	cout << "Do you want to sort it ascending(1) or descending(0)" << endl;
   	cin >> type;
   	vector<string> sortedLines = alphabetizer.sort(type);


   	// Fifth filter, print the data
    Output printer = Output(sortedLines);
    printer.print();

	return 0;
}
