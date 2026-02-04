#include <iostream>
using namespace std;

int main()
{
    int r,c;
    cin >> r >> c;
    int a[r][c];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin >> a[i][j];

    int top=0,bot=r-1,left=0,right=c-1;
    while(top<=bot && left<=right)
    {
        for(int i=left;i<=right;i++) cout << a[top][i] << " ";
        top++;
        for(int i=top;i<=bot;i++) cout << a[i][right] << " ";
        right--;
        if(top<=bot)
        {
            for(int i=right;i>=left;i--) cout << a[bot][i] << " ";
            bot--;
        }
        if(left<=right)
        {
            for(int i=bot;i>=top;i--) cout << a[i][left] << " ";
            left++;
        }
    }
    return 0;
}
//This code performs a spiral traversal of a given 2D matrix. It initializes four pointers (top, bot, left, right) to keep track of the current boundaries of the matrix that need to be traversed. The algorithm iteratively prints the elements in a spiral order by moving right across the top row, down the rightmost column, left across the bottom row, and up the leftmost column, adjusting the boundaries after each complete traversal of a side. This continues until all elements have been printed in spiral order.