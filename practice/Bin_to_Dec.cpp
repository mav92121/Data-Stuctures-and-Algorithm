#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long ans=0;
    long long temp;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            temp=pow(2,n-i-1);
            ans+=temp;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}