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

    int j=c-1,row=-1;
    for(int i=0;i<r;i++)
        while(j>=0 && a[i][j]==1)
        {
            row=i;
            j--;
        }

    cout << row;
    return 0;
}
//This code finds the row with the maximum number of 1s in a binary matrix where each row is sorted (i.e., all 0s come before 1s). It starts from the top-right corner of the matrix and iterates through each row. For each row, it moves leftwards as long as it encounters 1s, updating the row index whenever it finds a new maximum. This approach ensures that each element is processed at most once, resulting in an efficient O(r + c) time complexity, where r is the number of rows and c is the number of columns. If no 1s are found, it returns -1.