#include <iostream>
using namespace std;

int main()
{
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    int a[n1],b[n2],c[n3];
    for(int i=0;i<n1;i++) cin >> a[i];
    for(int i=0;i<n2;i++) cin >> b[i];
    for(int i=0;i<n3;i++) cin >> c[i];

    int i=0,j=0,k=0;
    while(i<n1 && j<n2 && k<n3)
    {
        if(a[i]==b[j] && b[j]==c[k])
        {
            cout << a[i] << " ";
            i++; j++; k++;
        }
        else if(a[i]<b[j]) i++;
        else if(b[j]<c[k]) j++;
        else k++;
    }
    return 0;
}
//This code finds and prints the common elements present in three sorted arrays. It uses three pointers (i, j, k) to traverse each of the arrays simultaneously. If the elements at all three pointers are equal, it prints the element and increments all three pointers. If the elements are not equal, it increments the pointer of the array with the smallest element to potentially find a match in subsequent iterations. This approach ensures that each array is traversed only once, resulting in an efficient O(n1 + n2 + n3) time complexity, where n1, n2, and n3 are the sizes of the three arrays.