#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<n;i++)
    {
        int idx = abs(arr[i]) - 1;
        if(arr[idx] < 0)
            cout << idx + 1 << " ";
        else
            arr[idx] = -arr[idx];
    }
    return 0;
}
