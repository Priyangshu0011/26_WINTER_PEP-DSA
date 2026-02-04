#include <iostream>
using namespace std;

long long merge(int arr[], int temp[], int l, int m, int r)
{
    int i=l, j=m, k=l;
    long long inv=0;

    while(i<m && j<=r)
    {
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];
            inv += m - i;
        }
    }

    while(i<m) temp[k++]=arr[i++];
    while(j<=r) temp[k++]=arr[j++];

    for(i=l;i<=r;i++) arr[i]=temp[i];
    return inv;
}

long long mergesort(int arr[], int temp[], int l, int r)
{
    long long inv=0;
    if(l<r)
    {
        int m=(l+r)/2;
        inv+=mergesort(arr,temp,l,m);
        inv+=mergesort(arr,temp,m+1,r);
        inv+=merge(arr,temp,l,m+1,r);
    }
    return inv;
}

int main()
{
    int n;
    cin >> n;
    int arr[n], temp[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << mergesort(arr,temp,0,n-1);
    return 0;
}
//This code counts the number of inversions in an array using a modified merge sort algorithm. An inversion is defined as a pair of indices (i, j) such that i < j and arr[i] > arr[j]. The algorithm works by recursively dividing the array into two halves, counting the inversions in each half, and then counting the inversions that occur between the two halves during the merge step. The total number of inversions is the sum of inversions from the left half, right half, and those found during merging. This approach has a time complexity of O(n log n), making it efficient for large arrays.