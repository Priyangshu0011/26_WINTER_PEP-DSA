//Insertion sort
#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
//Explanation:
// The insertion sort algorithm builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. However, insertion sort provides several advantages:
// Simple implementation: Insertion sort is straightforward and easy to implement.
// Efficient for small data sets: It performs well on small lists or arrays.
// Adaptive: It is efficient for data sets that are already substantially sorted.
// Stable: It maintains the relative order of records with equal keys.
// In-place: It requires only a constant amount O(1) of additional memory space.
// Time Complexity: O(n^2) in the average and worst case, O(n) in the best case (when the array is already sorted).
// Space Complexity: O(1)
// Use Cases: Insertion sort is often used as part of more complex algorithms, such as Timsort, and is also used for small data sets or as a final pass in more advanced sorting algorithms.