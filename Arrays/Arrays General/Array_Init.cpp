#include <iostream>
using namespace std;    

int main() 
{
    int n, ar[5]={1,2,3,4,5};
    for(int i=0;i<5;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}