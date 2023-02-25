// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio

#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int>&stack,int temp)
{
	if(stack.empty())
	{
		stack.push(temp);
		return;
	}
	if(stack.top()<temp)
	{
		stack.push(temp);
		return;
	}


	int n=stack.top();
	stack.pop();
	sortedInsert(stack,temp);
	stack.push(n);

}
void sortStack(stack<int> &stack)
{
	if(stack.empty())return;
	int temp=stack.top();
	stack.pop();
	sortStack(stack);
	sortedInsert(stack,temp);	
	
}