// https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>&stack,int temp)
{
    if(stack.empty())
    {
        stack.push(temp);
        return;
    }
    int element=stack.top();
    stack.pop();
    insertAtBottom(stack,temp);
    stack.push(element);

}
void reverseStack(stack<int> &stack) 
{
    
    if(stack.empty())return;
    int temp=stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack,temp);

}