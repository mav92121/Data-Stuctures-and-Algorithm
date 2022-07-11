#include <bits/stdc++.h>
using namespace std;
#define int long long int
void rec(int arr[],int n,int index,int sum,int &ans,int &curr)
{
    if(index>n)
    {
        return;
    }
    ans=min(ans,min(curr,(sum-curr)));
    rec(arr,n,index+1,sum,ans,curr);
    curr+=arr[index];
    rec(arr,n,index+1,sum,ans,curr);
    curr-=arr[index];
}
int32_t main()
{
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    // cout<<sum<<endl;
    int ans=INT_MAX;
    int curr=0;
    rec(arr,n,0,sum,ans,curr);
    cout<<ans<<endl;
}