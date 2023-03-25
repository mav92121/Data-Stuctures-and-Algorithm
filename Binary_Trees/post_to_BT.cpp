// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
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

Node *solve(int in[], int post[], int &postOrderIndex, int inOrderStart, int inOrderEnd, int n)
{

    if (postOrderIndex <0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    
    int element = post[postOrderIndex--];
    
    Node *root = new Node(element);
    
    int position =findIndex(in,n,element);
    
    in[position]=-1;

    root->right = solve(in, post, postOrderIndex, position + 1, inOrderEnd, n);
    root->left =  solve(in, post, postOrderIndex, inOrderStart, position - 1, n);

    return root;

}
Node *buildTree(int in[], int post[], int n) 
{
    int index=n-1;
    return solve(in,post,index,0,n-1,n);
}


