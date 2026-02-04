//Bucket Sort using array and without using vector:
#include <iostream>
using namespace std;
void bucketSort(int arr[], int n, int bucketRange)
{
    int bucketCount = 255 / bucketRange + 1; // Assuming input values are in the range 0-255
    int buckets[bucketCount][n];              // 2D array to hold buckets
    int bucketSizes[bucketCount] = {0};       // To keep track of sizes of each bucket

    // Distributing input array values into buckets
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = arr[i] / bucketRange;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Sorting individual buckets using insertion sort
    for (int i = 0; i < bucketCount; i++)
    {
        for (int j = 1; j < bucketSizes[i]; j++)
        {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Merging sorted buckets back into original array
    int index = 0;
    for (int i = 0; i < bucketCount; i++)
    {
        for (int j = 0; j < bucketSizes[i]; j++)
        {
            arr[index++] = buckets[i][j];
        }
    }
}
int main()
{
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(arr) / sizeof(arr[0]);
    int bucketRange = 10; // Define the range of each bucket
    bucketSort(arr, n, bucketRange);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
//Explanation:
// Bucket Sort is a distribution-based sorting algorithm that works by dividing the input array into several '
// buckets', sorting each bucket individually, and then merging the sorted buckets back together.
// In this implementation, we create a fixed number of buckets based on the defined bucket range.
// Each bucket is represented as a 2D array, and we keep track of the size of each bucket using a separate
// array. We use insertion sort to sort each individual bucket, which is efficient for small datasets.
// Finally, we merge the sorted buckets back into the original array to produce the final sorted output.
// Time Complexity: O(n + k) on average, where n is the number of elements and k is the number of buckets.
// Space Complexity: O(n + k) due to the additional space used for buckets.

