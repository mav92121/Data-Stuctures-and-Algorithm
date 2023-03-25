// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};

pair<int,int> rec(Node*root)
    {
        pair<int,int>ans;
        //   include,exclude

        if(root==NULL)
        {
           ans=make_pair(0,0);
           return ans;
        }
        pair<int,int>left=rec(root->left);
        pair<int,int>right=rec(root->right);
        
        ans.first=root->data+right.second+left.second; // include
        ans.second=max(left.first,left.second)+max(right.first,right.second); //exclude
        return ans;
    }
    int getMaxSum(Node *root) 
    {
        return max(rec(root).first,rec(root).second);
    }