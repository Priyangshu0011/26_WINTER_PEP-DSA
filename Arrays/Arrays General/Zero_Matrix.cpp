#include <iostream>
using namespace std;

int main()
{
    int r,c;
    cin >> r >> c;
    int a[r][c];
    bool row[r]={0}, col[c]={0};

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            cin >> a[i][j];
            if(a[i][j]==0)
            {
                row[i]=true;
                col[j]=true;
            }
        }

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(row[i] || col[j])
                a[i][j]=0;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
//This code modifies a given r x c matrix such that if any element in the matrix is 0, its entire row and column are set to 0. It first scans the matrix to identify which rows and columns contain a 0, storing this information in two boolean arrays. Then, it iterates through the matrix again, setting elements to 0 if their corresponding row or column is marked. This approach ensures that the original matrix is updated correctly while maintaining an efficient O(r*c) time complexity and O(r + c) space complexity.