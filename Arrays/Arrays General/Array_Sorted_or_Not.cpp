#include <iostream>
using namespace std;

int main()
{
    int n,ci=0,cd=0;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]<arr[i+1])
        {
            ci=1;
            break;
        }
    }
    cd=0;
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            cd=1;
            break;
        }
    }
    if(ci==1 && cd==1)
    {
        cout<<"Array is not sorted"<<endl;
    }
    else
    {
        cout<<"Array is sorted"<<endl;
    }
}