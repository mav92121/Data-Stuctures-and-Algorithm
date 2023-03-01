// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
    unordered_map<char, int> m;
    queue<char> q;
    string ans = "";
    for (int i = 0; i < A.length(); i++)
    {
        m[A[i]]++;
        q.push(A[i]);
        while (!(q.empty()))
        {
            if (m[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}