//   https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> &visited)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[y][x] == 0 && m[y][x] == 1)
        return true;
    return false;
}
void rec(vector<vector<int>> &m, int n, string &path, int x, int y, vector<string> &ans, vector<vector<int>> &visited)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[y][x] = 1;
    int nx, ny;
    // left
    nx = x - 1;
    ny = y;
    if (isPossible(m, n, nx, ny, visited))
    {
        path.push_back('L');
        rec(m, n, path, nx, ny, ans, visited);
        path.pop_back();
    }
    // right
    nx = x + 1;
    ny = y;
    if (isPossible(m, n, nx, ny, visited))
    {
        path.push_back('R');
        rec(m, n, path, nx, ny, ans, visited);
        path.pop_back();
    }
    // up
    nx = x;
    ny = y - 1;
    if (isPossible(m, n, (nx), ny, visited))
    {
        path.push_back('U');
        rec(m, n, path, nx, ny, ans, visited);
        path.pop_back();
    }
    // down
    nx = x;
    ny = y + 1;
    if (isPossible(m, n, (nx), ny, visited))
    {
        path.push_back('D');
        rec(m, n, path, nx, ny, ans, visited);
        path.pop_back();
    }
    visited[y][x] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    vector<string> ans;
    if (m[0][0] == 0)
        return ans;

    string path = "";
    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    rec(m, n, path, 0, 0, ans, visited);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    vector<string> ans=findPath(m,n);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}