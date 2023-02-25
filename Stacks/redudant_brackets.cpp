// https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio

#include <bits/stdc++.h>
using namespace std;
bool findRedundantBrackets(string &s)
{
    stack<char>st;
    for(auto it:s)
    {
        if(it=='(' || it=='+' || it=='-' || it=='*' || it=='/')
        {
            st.push(it);
        }
        else 
        {
            if(it==')')
            {
                bool isRedundant=true;
                while(st.top()!='(')
                {
                    char curr=st.top();
                    if(curr=='+' || curr=='-' || curr=='*' || curr=='/')
                    {
                        isRedundant=false;
                    }
                    st.pop();
                }
                if(isRedundant==true)return true;
                st.pop();
            }
        }
    }
    return false;
}
