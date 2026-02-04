//Given an array of 0s, 1s and 2s, sort it in O(n) time

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    cout<<high<<" "<<mid<<" "<<low<<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

//Explanation:
//This code implements the Dutch National Flag algorithm to sort an array containing only 0s, 1s, and 2s in a single pass (O(n) time complexity) and O(1) space complexity. It uses three pointers: 'low' to track the position for 0s, 'mid' to traverse the array, and 'high' to track the position for 2s. Depending on the value at 'mid', it swaps elements to ensure that all 0s are at the beginning, all 1s in the middle, and all 2s at the end of the array.