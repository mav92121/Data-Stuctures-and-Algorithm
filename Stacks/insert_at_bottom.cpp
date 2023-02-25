// https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio

#include <bits/stdc++.h>
using namespace std;

void rec(stack<int>& myStack, int x)
{
    if(myStack.empty())
    {
        myStack.push(x);
        return;
    }
    int temp=myStack.top();
    myStack.pop();
    rec(myStack,x);
    myStack.push(temp);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    rec(myStack,x);
    return myStack;
}
