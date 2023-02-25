// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
#include <bits/stdc++.h>
using namespace std;

bool knows(int a, int b, vector<vector<int>> &M, int n)
{
    if (M[a][b] == 1)
        return true;
    return false;
}
int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
        s.push(i);
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(a, b, M, n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    // check is top element is celebrity of not
    int row = 0;
    int col = 0;
    int ele = s.top();
    for (int i = 0; i < n; i++)
    {
        if (M[ele][i] == 0)
            row++;
        if (M[i][ele] == 1)
            col++;
    }
    if (row == n && col == n - 1)
        return ele;
    return -1;
}