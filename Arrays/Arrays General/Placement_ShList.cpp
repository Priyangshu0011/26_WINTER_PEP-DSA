// Placement short-listing: a company will take interview of those students whose marks are >= 70 and array size is 50 (students number)
// 1. print shortlisted(sl) candidates
// 2. total sl count (no of passed students)
// 3. failed students array merge to the last of the passed students

#include <iostream>
using namespace std;    

int main() 
{
    int size = 0;
    cout << "Enter number of students (max 50): ";
    cin >> size;
    int marks[size];
    cout << "Enter marks of " << size << " students: " << endl;
    for (int i = 0; i < size; i++) 
    {
        cin >> marks[i];
    }
    int passed[size], failed[size];
    int passCount = 0, failCount = 0;
    for (int i = 0; i < size; i++) 
    {
        if (marks[i] >= 70) 
        {
            passed[passCount++] = marks[i];
        } 
        else 
        {
            failed[failCount++] = marks[i];
        }
    }
    cout << "Shortlisted candidates (marks >= 70): ";
    if(passCount == 0) 
    {
        cout << "None";
    }
    else
    {
        for (int i = 0; i < passCount; i++) 
        {
            cout << passed[i] << " ";
        }
    }
    cout << endl;
    cout << "Total shortlisted candidates: " << passCount << endl;
    for (int i = 0; i < failCount; i++) 
    {
        passed[passCount + i] = failed[i];
    }
    cout << "Merged array (passed followed by failed): ";
    for (int i = 0; i < passCount + failCount; i++) 
    {
        cout << passed[i] << " ";
    }
    cout << endl;

    return 0;
}