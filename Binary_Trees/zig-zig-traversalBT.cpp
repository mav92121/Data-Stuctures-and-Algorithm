// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

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

vector <int> zigZagTraversal(Node* root)
{
    vector<int>ans;
    if(root==NULL)
    {
        return ans;
    }
    bool Left_Right=true;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>temp(size);
        for(int i=0;i<size;i++)
        {
            Node*frontNode=q.front();
            q.pop();
            int index=i;
            if(!Left_Right)
            {
                index=size-i-1;
            }
            
            temp[index]=frontNode->data;
            if(frontNode->left)
            {
                q.push(frontNode->left);
            }
            if(frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        Left_Right=!Left_Right;
        for(auto it:temp)
        {
            ans.push_back(it);
        }
    }
    return ans;

}