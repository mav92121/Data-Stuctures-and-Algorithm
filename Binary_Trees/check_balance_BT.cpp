// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

pair<bool,int>Fast(Node*root) // we are returning two values (bool and height) at the same time
{
    pair<bool,int>ans;
    if(root==NULL)
    {
        ans.first=true;
        ans.second=0;
        return ans;
    }
    pair<bool,int>left;
    pair<bool,int>right;
    left=Fast(root->left);
    right=Fast(root->right);
    
    int diff=abs((left.second-right.second));
    
    ans.first=(left.first&&right.first&&(diff<=1));
    ans.second=max(left.second,right.second)+1;
    return ans;
}
bool isBalanced(Node *root)
{
    if(root==NULL)return true;
    
    return Fast(root).first;
}