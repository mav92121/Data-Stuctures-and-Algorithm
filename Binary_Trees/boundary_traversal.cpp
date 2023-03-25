#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
void rightTraversal(Node*root,vector<int>&ans)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))return;
    if(root->right)
    rightTraversal(root->right,ans);
    else
    rightTraversal(root->left,ans);
    
    ans.push_back(root->data);  
}
void leafTraversal(Node*root,vector<int>&ans)
{
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
    leafTraversal(root->left,ans);
    leafTraversal(root->right,ans);
}
void leftTraversal(Node*root,vector<int>&ans)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))return;
    ans.push_back(root->data);
    if(root->left)
    leftTraversal(root->left,ans);
    else
    leftTraversal(root->right,ans);
}


vector <int> boundary(Node *root)
{
    vector<int>ans;
    ans.push_back(root->data);

    leftTraversal(root->left,ans);

    leafTraversal(root->left,ans);
    leafTraversal(root->right,ans);
    
    rightTraversal(root->right,ans);

    return ans;
}