#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            int t=a[i][j]; a[i][j]=a[j][i]; a[j][i]=t;
        }

    for(int i=0;i<n;i++)
    {
        int l=0,r=n-1;
        while(l<r)
        {
            int t=a[i][l]; a[i][l]=a[i][r]; a[i][r]=t;
            l++; r--;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
//This code rotates a given n x n matrix by 90 degrees clockwise. It first transposes the matrix by swapping elements across the main diagonal. After transposition, it reverses each row of the matrix to achieve the 90-degree clockwise rotation. The algorithm processes each element of the matrix a constant number of times, resulting in an overall time complexity of O(n^2), where n is the dimension of the matrix. The space complexity is O(1) since the rotation is done in place without using any additional storage.