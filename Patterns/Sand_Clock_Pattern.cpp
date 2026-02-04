/*
Sand Clock Pattern:
    * * * * *
     * * * *
      * * *
       * *
        *
       * * 
      * * *
     * * * *
    * * * * *
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<< "Enter size: ";
    cin>>n; 
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
        {
            cout<<"* ";
        }
        cout<<endl;
        for(int k=i;k>=1;k--)
        {
            if(i==n)
                continue;
            cout<<" ";
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int k=n-1;k>=i;k--)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

// ***********
// ***** *****
// ****   ****
// ***     ***
// **       **
// *         *
// **       **
// ***     ***
// ****   ****
// ***** *****
// *********** 