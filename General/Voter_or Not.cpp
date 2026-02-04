#include <iostream>
using namespace std;
int main() 
{
    int age;
    cin >> age;
    if (age >= 18) 
    {
        cout << "Voter";
    } 
    else 
    {
        cout << "Not Voter";
    }
    return 0;
}