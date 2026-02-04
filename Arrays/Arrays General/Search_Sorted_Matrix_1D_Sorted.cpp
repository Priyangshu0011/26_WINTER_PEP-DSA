#include <iostream>
using namespace std;

int main()
{
    int r,c,x;
    cin >> r >> c >> x;
    int a[r][c];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin >> a[i][j];

    int l=0,h=r*c-1;
    while(l<=h)
    {
        int m=(l+h)/2;
        int val=a[m/c][m%c];
        if(val==x)
        {
            cout << m/c << " " << m%c;
            return 0;
        }
        else if(val<x) l=m+1;
        else h=m-1;
    }
    cout << -1;
    return 0;
}
//This code searches for a given element 'x' in a matrix that is sorted as a 1D array (i.e., each row is sorted and the last element of each row is less than or equal to the first element of the next row). It uses a binary search approach by treating the 2D matrix as a 1D array. The algorithm calculates the middle index and converts it back to 2D indices to access the matrix elements. Depending on whether the middle element is equal to, less than, or greater than 'x', it adjusts the search range accordingly. This method ensures an efficient O(log(r*c)) time complexity, where r is the number of rows and c is the number of columns.