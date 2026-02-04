//Heap Sort:
#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
//Explanation:
// Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure to sort elements.
// The algorithm works by first building a max heap from the input array. In a max heap, the largest element is at the root.
// Once the max heap is built, the largest element (the root) is swapped with the last element of the heap,
// and the size of the heap is reduced by one. The heapify process is then called on the root to maintain the max heap property.
// This process is repeated until all elements are sorted.
// Time Complexity: O(n log n) for all cases (best, average, worst)
// Space Complexity: O(1) as it is an in-place sorting algorithm
