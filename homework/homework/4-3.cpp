#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // 1. Declare variables for column widths
    int numWidth = 10;
    int squareWidth = 15;

    int i = 1;

    // 2. Loop from 1 to 1000
    while (i <= 1000) {
        // Use the variables inside setw()
        cout << setw(numWidth) << i
            << setw(squareWidth) << i * i << endl;

        i++;
    }

    return 0;
}
