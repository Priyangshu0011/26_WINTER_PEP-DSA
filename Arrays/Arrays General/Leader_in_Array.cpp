#include <iostream>
using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;       
//     int arr[n],idx;
//     cout<<"Enter "<< n <<" elements: ";
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     int max=INT_MIN;
//     for(int i=0;i<n;i++)
//     {
//         if(max<arr[i])
//         {
//             max=arr[i];
//             idx=i;
//         }
//     }
//     for(int i=idx+1;i<n-1;i++)
//     {
//         arr[i-1]=arr[i];
//     }
//     arr[n-1]=max;
//     cout<<"Leader in the array: "<<max;
//     cout<<"Present Array"<<endl;
//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// }

//leader from gfg

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;       
    int arr[n];
    cout<<"Enter "<< n <<" elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Leaders in the array are: ";
    for(int i=0;i<n;i++)
    {
        bool isLeader=true;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]<=arr[j])
            {
                isLeader=false;
                break;
            }
        }
        if(isLeader)
        {
            cout<<arr[i]<<" ";
        }
    }
}