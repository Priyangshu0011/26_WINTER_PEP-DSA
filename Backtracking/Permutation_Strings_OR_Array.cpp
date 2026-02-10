//WAP to find all permutation of strings or array using backtracking. Consider the string or array to the user's input.
#include <iostream>
using namespace std;

int permute(string str, int l, int r) {
    int count=0;
    if (l == r) 
    {
        cout << str << endl;
        count++;
    } 
    else 
    {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]); // Swap the current index with the loop index
            count += permute(str, l + 1, r); // Recur with the next index
            swap(str[l], str[i]); // Backtrack to restore the original string
        }
    }
    return count;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "Permutations of the string are:" << endl;
    int count = permute(str, 0, str.length() - 1);
    cout << "Total number of permutations: " << count << endl;

    return 0;
}