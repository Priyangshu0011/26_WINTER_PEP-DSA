#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > largest) 
        {
            second_largest = largest;
            largest = arr[i];
        } 
        else if (arr[i] > second_largest && arr[i] != largest) 
        {
            second_largest = arr[i];
        }
    }

    if (second_largest == INT_MIN) 
    {
        cout << "No second largest element";
    } 
    else 
    {
        cout << second_largest;
    }

    return 0;
}