//Implementation of printing Natural Numbers in Reverse Order using Recursion.
#include <iostream>
using namespace std;
void printReverse(int n) {
    if (n == 0) {
        return; // Base case: stop when n is 0
    }
    cout << n << " "; // Print the current number
    printReverse(n - 1); // Recursive call with n-1
}
int main() {
    int n;
    cout << "Enter a number to print natural numbers in reverse order: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
    } else {
        cout << "Natural numbers in reverse order: ";
        printReverse(n);
        cout << endl;
    }

    return 0;
}
