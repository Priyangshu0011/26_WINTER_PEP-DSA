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

    int maxv = a[n-1][n-1];
    int res = -100000;

    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            res = max(res, maxv - a[i][j]);
            maxv = max(maxv, a[i][j]);
        }
    }

    cout << res;
    return 0;
}
//This code finds the maximum difference between two elements in a square matrix such that the larger element appears after the smaller element when traversing the matrix from top-left to bottom-right. It initializes a variable 'maxv' to keep track of the maximum value encountered so far, starting from the bottom-right corner of the matrix. It then iterates through the matrix in reverse order (from bottom-right to top-left), updating the maximum difference 'res' whenever it finds a larger difference between 'maxv' and the current element. The 'maxv' is also updated to ensure it always holds the maximum value seen so far. This approach ensures that each element is processed only once, resulting in an efficient O(n^2) time complexity for an n x n matrix.