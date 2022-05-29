// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &stalls,int d,int k)
{
	int cow=1;
	int temp=0;
	for(int i=1;i<stalls.size();i++)
	{
		if(stalls[i]-stalls[temp]>=d)
		{
			cow++;
			temp=i;
		}
		if(cow==k)
			return true;
	}
	return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
	int n=stalls.size();
	int s=1;
	int e=stalls[n-1]-stalls[0];
	int mid;
	int ans;
	while(s<=e)
	{
		mid=(s+e)/2;
		if(isPossible(stalls,mid,k))
		{
			ans=mid;
			s=mid+1;
		}
		else
		{
			e=mid-1;
		}
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
        vector<int> stalls(n);
        for(int i=0;i<n;i++)
        {
            cin>>stalls[i];
        }
        cout<<aggressiveCows(stalls,k)<<endl;
    }
    return 0;
}