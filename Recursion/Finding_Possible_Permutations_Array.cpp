//Finding All Possible Permutations of a Given Array
#include <iostream>
using namespace std;

void swapVal(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void permute(int arr[], int l, int r)
{
    if(l == r)
    {
        for(int i=0;i<=r;i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }
    for(int i=l;i<=r;i++)
    {
        swapVal(arr[l], arr[i]);
        permute(arr, l+1, r);
        swapVal(arr[l], arr[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    permute(arr, 0, n-1);
    return 0;
}
