// https://www.codingninjas.com/codestudio/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &boards, int k,int mid)
{
    int painters=1;
    int area=0;
    for(int i=0;i<boards.size();i++)
    {
        if(area+boards[i]<=mid)
        {
            area+=boards[i];
        }
        else
        {
            painters++;
            area=boards[i];
            if(painters>k || boards[i] > mid) return false;
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int s=0;
    int sum=0;
    for(int i=0;i<boards.size();i++)
    {
        sum+=boards[i];
    }
    int e=sum;
    int ans=-1;
    int mid;
    while(s<=e)
    {
        mid=s+(e-s)/2;
        if(isPossible(boards,k,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>boards(n);
        for(int i=0;i<n;i++) cin>>boards[i];
        cout<<findLargestMinDistance(boards,k)<<endl;
    }
    return 0;
}