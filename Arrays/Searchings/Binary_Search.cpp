//Binary Search:
#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }

    // Target was not found in the array
    return -1;
}
int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, n, target);
    if (result != -1)
        cout << "Element is present at index " << result << endl;
    else
        cout << "Element is not present in array" << endl;
    return 0;
}
//Explanation:
// Binary Search is an efficient algorithm for finding a target value within a sorted array. It works by repeatedly dividing the search interval in half. If the target value is less than the middle element of the array, the search continues in the left half; otherwise, it continues in the right half. This process is repeated until the target value is found or the search interval is empty.
// Time Complexity: O(log n) in the average and worst case, O(1) in the best case (when the target is at the middle).
// Space Complexity: O(1) as it is an iterative implementation.
// Use Cases: Binary Search is widely used in various applications, such as searching in databases, libraries, and any scenario where quick search operations are required on sorted data.
