#include <iostream>
using namespace std;

int sumOfAP(int a, int d, int n) 
{
    return (n / 2) * (2 * a + (n - 1) * d);
}
int main() 
{
    int a, d, n;
    cin >> a >> d >> n;
    int sum = sumOfAP(a, d, n);
    cout << sum;
    return 0;
}