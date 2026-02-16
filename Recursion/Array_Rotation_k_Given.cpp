//Array Rotation with k Given
#include <iostream>
using namespace std;

void reverseArr(int arr[], int l, int r)
{
    if(l >= r)
        return;
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
    reverseArr(arr, l+1, r-1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int k;
    cin >> k;
    k = k % n;
    reverseArr(arr, 0, k-1);
    reverseArr(arr, k, n-1);
    reverseArr(arr, 0, n-1);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    return 0;
}
