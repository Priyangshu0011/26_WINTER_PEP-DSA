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

    int i=0,j=c-1;
    while(i<r && j>=0)
    {
        if(a[i][j]==x)
        {
            cout << i << " " << j;
            return 0;
        }
        else if(a[i][j]>x) j--;
        else i++;
    }
    cout << -1;
    return 0;
}
//This code searches for a given element 'x' in a row-wise and column-wise sorted matrix. It starts from the top-right corner of the matrix and compares the current element with 'x'. If the current element is equal to 'x', it prints the indices and exits. If the current element is greater than 'x', it moves left (decreases the column index) to find smaller elements. If the current element is less than 'x', it moves down (increases the row index) to find larger elements. This process continues until the element is found or the indices go out of bounds, in which case it prints -1. The algorithm runs in O(r + c) time complexity, where r is the number of rows and c is the number of columns.