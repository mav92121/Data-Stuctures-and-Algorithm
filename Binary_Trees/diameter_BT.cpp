// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
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

pair<int,int>diamaterFast(Node*root)
{
    pair<int,int>ans;
    if(root==NULL)
    {
        ans.first=0;
        ans.second=0;
        return ans;
    }
    
    pair<int,int>left=diamaterFast(root->left);
    pair<int,int>right=diamaterFast(root->right);
    
    int opt1=left.first;
    int opt2=right.first;
    int opt3= (1+left.second+right.second);
    
    ans.first=max(opt1,max(opt2,opt3));
    ans.second=1+ max(left.second,right.second);
    return ans;
}
int diameter(Node* root) 
{
    // Your code here
    
    return diamaterFast(root).first;
}