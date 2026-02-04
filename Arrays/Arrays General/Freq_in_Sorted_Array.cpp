/*
Frequency in a sorted Array : 1 1 1 2 6 6 6 9 78 78 96 102 102 102 106
Freqs of:
1: 3
2: 1
6: 3
9: 1
78: 2
96: 1
102: 3
106: 1
*/
#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout<<"Enter size of the array: ";
    cin >> n;
    cout<<endl;
    int arr[n];

    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    cout << "Frequencies of: "<<endl;

    int count = 1;

    for (int i = 1; i < n; i++) 
    {
        if (arr[i] == arr[i - 1]) 
        {
            count++;
        }
        else 
        {
            if (count > 0)
            {
                cout << arr[i - 1] << ": " << count<<endl;
            }
            count = 1;
        }
    }

    // handle last group
    if (count > 1)
    {
        cout << arr[n - 1] << " (Frequency: " << count << ") ";
    }

    cout << endl;
    return 0;
}

