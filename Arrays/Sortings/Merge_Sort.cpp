//Merge Sort:
#include <iostream>
using namespace std;
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
//Explanation:
// Merge Sort is a divide-and-conquer sorting algorithm that works by recursively dividing the input array into two halves,
// sorting each half, and then merging the sorted halves back together.
// The algorithm begins by dividing the array into two halves until each sub-array contains a single element (which is inherently sorted).
// Then, it merges the sub-arrays back together in a sorted manner by comparing the elements of each sub-array and arranging them in order.
// Time Complexity: O(n log n) for all cases (best, average, worst)
// Space Complexity: O(n) due to the temporary arrays used for merging
// Use Cases: Merge Sort is particularly useful for sorting linked lists and large datasets that do not fit into memory,
// as it can be implemented as an external sorting algorithm. It is also stable, meaning that it preserves the relative order of equal elements.