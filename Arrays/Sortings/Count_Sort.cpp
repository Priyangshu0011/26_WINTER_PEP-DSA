//Count Sort:
#include <iostream>
using namespace std;
void countSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    int count[max + 1] = {0};

    // Store count of each number
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Modify count array by adding previous counts
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int output[n];
    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
//Explanation:
// Counting Sort is a non-comparative sorting algorithm that sorts elements by counting the number of occurrences of each unique element in the input array. It is particularly efficient for sorting integers within a known, limited range.
// The algorithm works by creating a count array where the index represents the elements from the input array, and the value at each index represents the count of occurrences of that element. After counting, the count array is modified to store the actual positions of elements in the output array. Finally, the output array is constructed by placing elements in their correct positions based on the count array.
// Time Complexity: O(n + k), where n is the number of elements in the input array and k is the range of the input values.
// Space Complexity: O(k) for the count array.
// Use Cases: Counting Sort is useful when the range of input values (k) is not significantly larger than the number of elements (n). It is often used as a subroutine in other sorting algorithms, such as Radix Sort.
