// https://www.codingninjas.com/codestudio/problems/allocate-books_1090540
#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> arr, int n, int m,int mid)
{
    int student=1;
    int pagecount=0;
    for(int i=0;i<n;i++)
    {
        if(pagecount+arr[i]<=mid)
        {
            pagecount+=arr[i];
        }
        else 
        {
            student++;
            pagecount=arr[i];
            if(student>m || arr[i]>mid)
            {
                return false;
            }
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) 
{
    // Write your code here.
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int e=sum;
    int mid;
    int ans=-1;
    while(s<=e)
    {
        mid=s+(e-s)/2;
        if(isPossible(arr,n,m,mid)) 
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;            
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin>>n>>m;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<allocateBooks(arr,n,m)<<endl;
    }
    return 0;
}