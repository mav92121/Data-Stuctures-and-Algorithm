// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
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

vector<int> verticalOrder(Node *root)
{
    vector<int>ans;
    if(root==NULL)return ans;
    map<int,map<int,vector<Node*>>>nodes;
    // hd,vd,node
    
    queue<pair< Node*,pair<int,int> >>q;
    // node,hd,vd
    q.push(make_pair(root,make_pair(0,0)));
    
    while(!q.empty())
    {
        pair< Node*,pair<int,int>>temp=q.front();
        Node*front=temp.first;
        int hd=temp.second.first;
        int vd=temp.second.second;
        nodes[hd][vd].push_back(front);
        q.pop();
        if(front->left)
        {
            q.push(make_pair(front->left,make_pair(hd-1,vd+1)));
        }
        if(front->right)
        {
            q.push(make_pair(front->right,make_pair(hd+1,vd+1)));
        }
        
    }

    for(auto i:nodes)
    {
        for(auto j:i.second)
        {
            for(auto k:j.second)
            {
                ans.push_back(k->data);
            }
        }
    }
    return ans;
    
    
}


