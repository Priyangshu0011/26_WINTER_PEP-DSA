// Cricket run analysis: Batsman's last 10 matches run (take array that the avg comes > 30)
// 1. total runs
// 2. no. of ducks
// 3. best innings
// 4. consistent score (avg score must be >=30)

#include <iostream>
using namespace std;
int main() 
{
    int matches = 10;
    int runs[matches];
    cout << "Enter runs scored in last 10 matches: " << endl;
    for (int i = 0; i < matches; i++) 
    {
        cin >> runs[i];
    }
    int totalRuns = 0;
    int duckCount = 0;
    int bestInnings = runs[0];
    for (int i = 0; i < matches; i++) 
    {
        totalRuns += runs[i];
        if (runs[i] == 0) 
        {
            duckCount++;
        }
        if (runs[i] > bestInnings) 
        {
            bestInnings = runs[i];
        }
    }
    double averageScore = (double)(totalRuns) / matches;
    cout << "Total Runs: " << totalRuns << endl;
    cout << "Number of Ducks: " << duckCount << endl;
    cout << "Best Innings: " << bestInnings << endl;
    cout << "Average Score: " << averageScore << " hence ";
    if (averageScore >= 30) 
    {
        cout << "The batsman is consistent." << endl;
    } 
    else 
    {
        cout << "The batsman is not consistent." << endl;
    }
    return 0;
}