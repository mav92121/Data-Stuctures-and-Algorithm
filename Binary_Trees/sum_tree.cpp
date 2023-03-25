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
pair<bool,int>Fast(Node*root)
{
    pair<bool,int>ans;
    if(root==NULL)
    {
        ans.first=true;
        ans.second=0;
        return ans;
    }
    if(root->left==NULL && root->right==NULL)
    {
        ans.first=true;
        ans.second=root->data;
        return ans;
    }
    
    pair<bool,int>left=Fast(root->left);
    pair<bool,int>right=Fast(root->right);
    
    bool cond=(left.second+right.second==root->data);
    
    if(cond && left.first && right.first)
    {
        ans.first=true;
        ans.second=left.second+right.second+root->data;
    }
    return ans;
    
}
bool isSumTree(Node* root)
{
        return Fast(root).first;
}