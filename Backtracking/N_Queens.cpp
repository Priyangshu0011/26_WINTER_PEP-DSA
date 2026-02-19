//N-queens problem using backtracking
#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<vector<int>> &board, int row, int col)
{
    int n = board.size();
    for(int i=0;i<col;i++)
        if(board[row][i] == 1)
            return false;
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        if(board[i][j] == 1)
            return false;
    for(int i=row,j=col;i<n && j>=0;i++,j--)
        if(board[i][j] == 1)
            return false;
    return true;
}
bool solveNQUtil(vector<vector<int>> &board, int col)
{
    int n = board.size();
    if(col >= n)
        return true;
    for(int i=0;i<n;i++)
    {
        if(isSafe(board, i, col))
        {
            board[i][col] = 1;
            if(solveNQUtil(board, col+1))
                return true;
            board[i][col] = 0; // Backtrack
        } 
    }
    return false;
}
void solveNQ(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    if(!solveNQUtil(board, 0))
    {
        cout << "Solution does not exist";
        return;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    solveNQ(n);
    return 0;
}

