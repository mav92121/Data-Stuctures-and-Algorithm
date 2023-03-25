// https://practice.geeksforgeeks.org/problems/construct-tree-1/1

#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node* left;
  Node* right;
   Node(int data)
   {
    this->data=data;
   }
};

int findIndex(int in[],int n,int ele)
{
    for(int i=0;i<n;i++)
    {
        if(in[i]==ele)
        {
            return i;
        }
    }
    return -1;
}
Node *solve(int in[], int pre[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int n)
{

    if (preOrderIndex >= n || inOrderStart > inOrderEnd)

    {
        return NULL;
    }


    int element = pre[preOrderIndex++];

    Node *root = new Node(element);

    int position =findIndex(in,n,element);
    in[position]=-1;

    root->left = solve(in, pre, preOrderIndex, inOrderStart, position - 1, n);

    root->right = solve(in, pre, preOrderIndex, position + 1, inOrderEnd, n);
    return root;

}
Node* buildTree(int in[],int pre[], int n)
{
    int index=0;
    return solve(in,pre,index,0,n-1,n);
    
}
