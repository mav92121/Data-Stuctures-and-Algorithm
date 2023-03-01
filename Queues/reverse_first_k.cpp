// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) 
{
    // add code here.
    stack<int>s;
    int n=q.size();
    for(int i=0;i<k;i++)
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    int temp=n-k;
    while((temp)--)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}