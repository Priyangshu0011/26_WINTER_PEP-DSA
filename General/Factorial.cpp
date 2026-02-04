#include <iostream>
using namespace std;

int main() 
{
    int n;
    int f = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        f *= i;
    }
    cout << f;
}

