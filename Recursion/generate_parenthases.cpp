// https://leetcode.com/problems/generate-parentheses/
#include <bits/stdc++.h>
using namespace std;
void rec(vector<string>&ans,string temp,int l,int r,int n)
{
    if(l==r && l==n)
    {
        ans.push_back(temp);
        return;
    }
    if(l<n) // condition for adding opening parenthases
    {
        temp.push_back('(');
        l++;
        rec(ans,temp,l,r,n);
        temp.pop_back();
        l--;
    }
    if(r<l) // condition for adding closing parenthases
    {
        temp.push_back(')');
        r++;
        rec(ans,temp,l,r,n);
        temp.pop_back();
        r--;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<string>ans;
    string temp="";
    rec(ans,temp,0,0,n);
    for(auto it:ans)
    {
        cout<<it<<endl;
    }
    return 0;
}