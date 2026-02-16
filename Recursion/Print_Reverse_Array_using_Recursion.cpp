//Implementation of printing reverse array using recursion in C++ using backtracking
#include <iostream>
using namespace std;
void reverse(int *arr,int j,int k)
{
    if(k>j)
        return;
    reverse(arr,j,k+1);
    cout<<arr[k]<<" ";
}
int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int j=n-1;
    reverse(arr,j,0);
}