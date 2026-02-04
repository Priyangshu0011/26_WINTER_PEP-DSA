//Explanation: 
// Quick Sort is a divide-and-conquer algorithm that works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot. The sub-arrays are then recursively sorted.
// Time Complexity: O(n log n) on average, O(n^2) in the worst case (when the pivot is always the smallest or largest element).
// Space Complexity: O(log n) due to recursion stack.
// Use Cases: Quick Sort is efficient for large datasets and is widely used in practice due to its average-case performance.

// Quick Sort Implementation
#include <iostream>
using namespace std;
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high]; // pivot
        int i = (low - 1);     // Index of smaller element

        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot)
            {
                i++; // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        // Recursively sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

//for firat pass low = 0, high = 5
//pivot = arr[5] = 5
//i = low -1 = -1   
//after 1st pass array will look like this: 1 7 8 9 10 5
//after 2nd pass array will look like this: 1 5 8 9 10 7
//after 3rd pass array will look like this: 1 5 7 9 10 8
//now swap arr[i+1] and arr[high] => swap arr[2] and arr[5]