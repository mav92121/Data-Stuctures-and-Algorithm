#include <bits/stdc++.h>
using namespace std;
void rec(string s, vector<string>&ans,int index)
{
    if(index>=(s.length()))
    {
        ans.push_back(s);
        return;
    }
    for(int i=index;i<s.length();i++)
    {
        swap(s[i],s[index]);
        rec(s,ans,index+1);
        swap(s[i],s[index]);
    }
}
int main()
{
    string s;
    cin>>s;
    vector<string>ans;
    rec(s,ans,0);
    for(auto it:ans)
    {
       cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}