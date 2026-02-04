//Selection sort:
#include <iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
//Explanation:
// Selection Sort is a simple comparison-based sorting algorithm that divides the input array into two parts:
// a sorted and an unsorted region. It repeatedly selects the smallest (or largest, depending on sorting order)
// element from the unsorted region and swaps it with the leftmost unsorted element, moving the boundary
// between the sorted and unsorted regions one element to the right.
// Time Complexity: O(n^2) for all cases (best, average, worst)
// Space Complexity: O(1) as it is an in-place sorting algorithm
// Use Cases: Selection Sort is not suitable for large datasets due to its quadratic time complexity.
// However, it can be useful for small datasets or when memory space is limited, as it requires minimal additional storage.
