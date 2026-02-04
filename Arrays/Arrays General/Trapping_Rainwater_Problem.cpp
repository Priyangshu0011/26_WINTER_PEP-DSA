#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int h[n];
    for(int i=0;i<n;i++) cin >> h[i];

    int l=0,r=n-1,left=0,right=0,water=0;
    while(l<r)
    {
        if(h[l]<h[r])
        {
            if(h[l]>=left) left=h[l];
            else water+=left-h[l];
            l++;
        }
        else
        {
            if(h[r]>=right) right=h[r];
            else water+=right-h[r];
            r--;
        }
    }
    cout << water;
    return 0;
}
//This code solves the Trapping Rainwater Problem, which calculates the total amount of rainwater that can be trapped between bars of different heights represented by an array. It uses a two-pointer approach, initializing pointers at both ends of the array and maintaining the maximum heights seen so far from both sides (left and right). By comparing the heights at the two pointers, it determines which side to process, updating the water trapped based on the difference between the current height and the maximum height seen so far. This method ensures that each element is processed only once, resulting in an efficient O(n) time complexity and O(1) space complexity.