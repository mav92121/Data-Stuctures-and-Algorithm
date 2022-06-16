//    https://leetcode.com/problems/letter-combinations-of-a-phone-number/


#include <bits/stdc++.h>
using namespace std;
void rec(string digits, string path, vector<string> &ans, string guide[], int index)
{
    if (index >= digits.length())
    {
        ans.push_back(path);
        return;
    }
    int number = digits[index] - '0';
    string value = guide[number];
    for (int i = 0; i < value.length(); i++)
    {
        path.push_back(value[i]);
        rec(digits, path, ans, guide, index + 1);
        path.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    string guide[10] = {"0", "0", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    if (digits.length() == 0)
        return ans;
    string path = "";
    rec(digits, path, ans, guide, 0);
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string digits;
        cin >> digits;
        vector<string> ans=letterCombinations(digits);
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}