#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* kReverse(Node* head, int k) 
{
    if(head==NULL)return head;
    int cnt=0;
    Node*curr=head;
    Node*prev=NULL;
    Node*nex=NULL;

    while(cnt!=0 && head!=NULL)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
        cnt++;
    }
    kReverse(curr,k)->next=prev;

    return prev;
}