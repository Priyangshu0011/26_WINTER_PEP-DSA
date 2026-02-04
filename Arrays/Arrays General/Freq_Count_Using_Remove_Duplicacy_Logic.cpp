//Duplicacy remove: HR mistakenly copied id of an employess so remove duplicacy

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

    cout << "Unique employee IDs: ";
    for (int i = 0; i < n; i++) 
    {
        bool isDuplicate = false;
        for (int j = 0; j < i; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) 
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    return 0;
}