#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][2];
    for(int i=0;i<n;i++) cin >> a[i][0] >> a[i][1];

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i][0]>a[j][0])
            {
                int t=a[i][0]; a[i][0]=a[j][0]; a[j][0]=t;
                t=a[i][1]; a[i][1]=a[j][1]; a[j][1]=t;
            }

    int s=a[0][0], e=a[0][1];
    for(int i=1;i<n;i++)
    {
        if(a[i][0]<=e)
            e = max(e,a[i][1]);
        else
        {
            cout << s << " " << e << endl;
            s=a[i][0]; e=a[i][1];
        }
    }
    cout << s << " " << e;
    return 0;
}
//This code merges overlapping intervals from a list of intervals. It first sorts the intervals based on their starting points. Then, it iterates through the sorted intervals, comparing the current interval with the last merged interval. If they overlap (i.e., the start of the current interval is less than or equal to the end of the last merged interval), it updates the end of the last merged interval to be the maximum of both ends. If they do not overlap, it prints the last merged interval and starts a new one. Finally, it prints the last merged interval after processing all intervals. This approach ensures that all overlapping intervals are combined efficiently.