#include <bits/stdc++.h>
using namespace std;
bool Binary_Search(int arr[],int s,int e,int k)
{
    if(s>e) return false;
    int mid=s+(e-s)/2;
    if(arr[mid]==k) return true;
    else if(arr[mid]>k) return Binary_Search(arr,s,mid-1,k);
    else return Binary_Search(arr, mid+1,e,k);
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    bool ans=Binary_Search(arr,0,n,k);
    if(ans) cout<<k<<" is present in array"<<endl;
    else cout<<k<<" is not present in array"<<endl;
    return 0;
}