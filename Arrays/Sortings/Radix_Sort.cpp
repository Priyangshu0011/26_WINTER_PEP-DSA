//Radix Sort:
#include <iostream>
using namespace std;
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that it now contains actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int max = getMax(arr, n);

    // Do counting sort for every digit. Note that
    // instead of passing digit number, exp is passed.
    // exp is 10^i where i is current digit number
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
//Explanation:
// Radix Sort is a non-comparative integer sorting algorithm that sorts numbers by processing individual
// digits. It works by distributing the numbers into buckets based on each digit, starting from the least
// significant digit to the most significant digit. The algorithm uses a stable sorting algorithm (like
// Counting Sort) as a subroutine to sort the numbers based on each digit.
// Time Complexity: O(d*(n + k)), where d is the number of digits in
// the maximum number, n is the number of elements in the array, and k is the range of the input.
// Space Complexity: O(n + k) for the output and count arrays used in Counting Sort
// Use Cases: Radix Sort is particularly useful for sorting large sets of integers or strings where the
// range of the input values (k) is not significantly larger than the number of values to be sorted (n).
