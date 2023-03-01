// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) 
{
    queue<long long>q;

    vector<long long>ans;                                        
    for(int j=0;j<K;j++)
    {
        if(A[j]<0)
        {
            q.push(j);
        }
    }
    if(q.empty())
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(A[q.front()]);
    }
    
    for(int i=K;i<N;i++)
    {
        if((!q.empty()) && (i-q.front()>=K))
        {
            q.pop();
        }
        if(A[i]<0)
        {
            q.push(i);
        }
        if(q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(A[q.front()]);
        }
        
    }
    return ans;
}