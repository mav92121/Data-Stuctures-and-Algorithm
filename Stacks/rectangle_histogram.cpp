// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

void nextSmaller(vector<int>&v,vector<int>&next)
{
    stack<int>s;
    s.push(-1);
    for(int i=v.size()-1;i>=0;i--)
    {
        while(s.top()!=-1 && v[s.top()]>=v[i])
        {
            s.pop();
        }
        next[i]=s.top();
        s.push(i);
    }
}
void prevSmaller(vector<int>&v,vector<int>&prev)
{
    stack<int>s;
    s.push(-1);
    for(int i=0;i<v.size();i++)
    {
        while(s.top()!=-1 && v[s.top()]>=v[i])
        {
            s.pop();
        }
        prev[i]=s.top();
        s.push(i);
    }
}

int largestRectangleArea(vector<int>& heights) 
{
    vector<int>next(heights.size(),0);
    vector<int>prev(heights.size(),0);
    prevSmaller(heights,prev);
    nextSmaller(heights,next);
    int ans=0;
    int l,b;
    for(int i=0;i<heights.size();i++)
    {
        l=heights[i];
        if(next[i]==-1)
        {
            next[i]=heights.size();
        } 
        
        b=next[i]-prev[i]-1;
        ans=max(ans,l*b);
    }
    return ans;

}