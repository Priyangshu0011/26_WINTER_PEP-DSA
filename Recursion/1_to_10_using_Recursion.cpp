//Implementation of printing numbers from 1 to 10 using recursion in C++
#include <iostream>
using namespace std;
void printNumbers(int n) {
    if (n > 10) {
        return; // Base case: stop when n exceeds 10
    }
    cout << n << " "; // Print the current number
    printNumbers(n + 1); // Recursive call with n+1
}
int main() {
    cout << "Numbers from 1 to 10: ";
    printNumbers(1); // Start printing from 1
    cout << endl;
    return 0;
}
