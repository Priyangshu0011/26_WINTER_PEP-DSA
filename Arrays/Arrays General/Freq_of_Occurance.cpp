/* WAP to count the frequency: show attendance of those students whose roll are repeating (a problem occurred in attendance login system):
input [1, 2, 3, 2, 1, 5, 9, 27]
Output [1, 2]\
using frequency count logic
*/

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

    int freq[100] = {0};

    for (int i = 0; i < n; i++) 
    {
        freq[arr[i]]++;
    }

    cout << "Students with repeating roll numbers: ";
    for (int i = 0; i < 100; i++) 
    {
        if (freq[i] > 1) 
        {
            cout << i << " ";
            cout << " (Frequency: " << freq[i] << ") ";
        }
    }
    cout << endl;
    return 0;
}