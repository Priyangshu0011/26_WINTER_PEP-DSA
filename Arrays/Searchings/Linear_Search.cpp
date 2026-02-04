//Linear search:
#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i; // Target found at index i
    }
    return -1; // Target not found
}
int main()
{
    int arr[] = {4, 2, 3, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = linearSearch(arr, n, target);
    if (result != -1)
        cout << "Element is present at index " << result << endl;
    else
        cout << "Element is not present in array" << endl;
    return 0;
}
//Explanation:
// Linear Search is a straightforward algorithm used to find a specific element in an array by checking each element one by one until the target element is found or the end of the array is reached.
// Time Complexity: O(n) in the average and worst case, O(1) in the best case (when the target is at the first position).
// Space Complexity: O(1) as it uses a constant amount of additional memory.
// Use Cases: Linear Search is useful for small or unsorted datasets where the overhead of more complex algorithms is not justified. It is also easy to implement and understand.
