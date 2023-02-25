//   https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio

#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>s;
    for(int i=0;i<expression.size();i++)
    {
        char ch=expression[i];
        if(ch=='{' || ch=='[' || ch=='(')
        {
            s.push(ch);
        } else {
          if (s.empty())
            return false;
          if ((ch == ')' && s.top() == '(') ||
              (ch == ']' && s.top() == '[') || (ch == '}' && s.top() == '{'))
              {
                  s.pop();
              }
              else
              {
                  return false;
              }
        }
    }
    if(s.empty())return true;
    return false;
}