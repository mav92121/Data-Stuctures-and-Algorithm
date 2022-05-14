#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2*n;j++)
        {
            if(i>=2 && j>=n+2-i && j<=n+i-1) cout<<"*" ; 
            else 
            {
                if(j<=n) cout<<j;
                else cout<<2*n+1-j;
            }
        }
        cout<<endl;
    }
   return 0;
}