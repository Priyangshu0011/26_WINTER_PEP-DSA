// 3 5 7 8 13 15 17 18 23 25 27 28 - only one single loop find max min sum

#include <iostream> 
using namespace std;
int main() 
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    int maxVal = arr[0];
    int minVal = arr[0];
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        sum += arr[i];
        if (arr[i] > maxVal) 
        {
            maxVal = arr[i];
        }
        if (arr[i] < minVal) 
        {
            minVal = arr[i];
        }
    }
    cout << "Maximum value: " << maxVal << endl;
    cout << "Minimum value: " << minVal << endl;
    cout << "Sum of all elements: " << sum << endl;

    return 0;
}