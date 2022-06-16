#include <bits/stdc++.h>
using namespace std;
void recursion(vector<int> arr, vector<vector<int>> &ans, vector<int> temp, int index)
{
    if (index >= arr.size())
    {
        ans.push_back(temp);
        return;
    }
    // exclude
    recursion(arr, ans, temp, index + 1);
    // incude
    temp.push_back(arr[index]);
    recursion(arr, ans, temp, index + 1);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> ans;
    vector<int> temp;
    recursion(arr, ans, temp, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].size() == 0)
        {
            cout << "{} ";
        }
        else
            for (int j = 0; j < ans[i].size(); j++)
            {

                cout << ans[i][j] << " ";
            }
        cout << endl;
    }
    return 0;
}