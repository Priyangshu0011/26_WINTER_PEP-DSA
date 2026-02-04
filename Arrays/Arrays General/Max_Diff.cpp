#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout<<"Enter "<< n <<" elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max=INT_MIN;
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
    }
    int dif=max-min;
    cout<<"Maximum Number: "<<max<<endl;
    cout<<"Minimum Number: "<<min<<endl;
    cout<<"Max Difference: "<<dif<<endl;
}