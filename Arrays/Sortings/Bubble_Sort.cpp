#include <iostream>
using namespace std;
int main() 
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
    }
}
//Explanation:
// Bubble Sort is a simple comparison-based sorting algorithm that repeatedly steps through the list, compares adjacent
// elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.
// Time Complexity: O(n^2) for all cases (best, average, worst)
// Space Complexity: O(1) as it is an in-place sorting algorithm
// Use Cases: Bubble Sort is not suitable for large datasets due to its quadratic time complexity. However, it can be useful for small datasets or educational purposes to illustrate the concept of sorting algorithms.
