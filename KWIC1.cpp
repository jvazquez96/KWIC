#include <iostream>
#include <vector>
#include <queue>
#include "Facade.cpp"

using namespace std;

// Main class that calls the Facade, which controls
// the flow of the program
int main() {
        
    // Facade
    Facade fac = Facade();
    fac.run();

    return 0;
}
