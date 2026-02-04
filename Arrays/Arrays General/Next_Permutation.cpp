#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    int i = n-2;
    while(i>=0 && a[i]>=a[i+1]) i--;

    if(i>=0)
    {
        int j = n-1;
        while(a[j]<=a[i]) j--;
        int t = a[i]; a[i]=a[j]; a[j]=t;
    }

    int l = i+1, r = n-1;
    while(l<r)
    {
        int t = a[l]; a[l]=a[r]; a[r]=t;
        l++; r--;
    }

    for(int k=0;k<n;k++) cout << a[k] << " ";
    return 0;
}
//This code finds the next lexicographical permutation of a given array of integers. It first identifies the rightmost pair of elements where the left element is smaller than the right, indicating a potential for a higher permutation. If such a pair is found, it then locates the smallest element to the right of this pair that is larger than the identified left element and swaps them. Finally, it reverses the order of elements to the right of the original position of the left element to achieve the next permutation in ascending order. If no such pair exists, it means the array is in its highest permutation, and reversing it results in the lowest permutation.