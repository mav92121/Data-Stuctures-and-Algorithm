// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
vector<int> topView(Node *root)
{
    // for every horizontal value hd there would be only one node in top view
    vector<int>ans;
    if(root==NULL)return ans;
    map<int,int>topNode;
    //  hd,node->data
    queue<pair<Node*,int>>q;
    // node,hd;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<Node*,int>p=q.front();
        Node*front=p.first;
        int hd=p.second;
        q.pop();
        if(topNode[hd]==0) // if(topNode.find(hd)==topNode.end())
        {
            topNode[hd]=front->data;
        }
        if(front->left)
        {
            q.push(make_pair(front->left,hd-1));
        }
        if(front->right)
        {
            q.push(make_pair(front->right,hd+1));
        }
    }
    for(auto it:topNode)
    {
        ans.push_back(it.second);
    }
    return ans;
}