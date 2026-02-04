#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    k = k % n; // In case k is greater than n
    // Reverse the whole array
    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - i - 1]);
    }
    // Reverse first k elements
    for (int i = 0; i < k / 2; i++) {
        swap(arr[i], arr[k - i - 1]);
    }
    // Reverse remaining n-k elements
    for (int i = k; i < (n + k) / 2; i++) {
        swap(arr[i], arr[n - (i - k) - 1]);
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}