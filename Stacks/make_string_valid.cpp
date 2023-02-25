// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio

#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str) 
{
  if(str.size()&1)return -1;
  stack<char>s;
  for(int i=0;i<str.size();i++)
  {
    if(str[i]=='{')
    {
      s.push(str[i]);
    }
    else
    {
      if(!s.empty() && s.top()=='{')
      {
        s.pop();
      }
      else
      {
        s.push(str[i]);
      }
    }
  }

  int a=0;
  int b=0;

  while(!s.empty())
  {
    char temp=s.top();
    if(temp=='{')a++;
    else b++;
    s.pop();
  }
  if(a==0|| b==0 || a%2==0)
  {
    return (a+b)/2;
  }
  return ((a+b)/2)+1;
  
}