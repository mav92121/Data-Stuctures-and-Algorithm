#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* reverse(Node*head)
{
    Node*curr=head;
    Node*next=NULL;
    Node*prev=NULL;
    if(head==NULL || head->next==NULL)return head;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void addNode(Node*&head,Node*&tail,Node*temp)
{
    if(head==NULL)
    {
        head=temp;
        tail=head;
        return;
    }
    tail->next=temp;
    tail=temp;
}
struct Node* addTwoLists(struct Node* l1, struct Node* l2)
{
    Node*ans=NULL;
    Node*tail=NULL;
    int carry=0;
    l1=reverse(l1);
    l2=reverse(l2);
    while(l1 && l2)
    {
        int temp=l1->data + l2->data+ carry;
        int temp1=temp%10;
        carry=temp/10;
        Node*ar=new Node(temp1);
        addNode(ans,tail,ar);
        l1=l1->next;
        l2=l2->next;
    }
    while(l1)
    {
        int temp=l1->data+ carry;
        int temp1=temp%10;
        carry=temp/10;
        Node*ar=new Node(temp1);
        addNode(ans,tail,ar);
        l1=l1->next;
    }
    while(l2)
    {
        int temp=l2->data+ carry;
        int temp1=temp%10;
        carry=temp/10;
        Node*ar=new Node(temp1);
        addNode(ans,tail,ar);
        l2=l2->next;
    }
    while(carry)
    {
        int temp=carry;
        int temp1=temp%10;
        carry=temp/10;
        Node*ar=new Node(temp1);
        addNode(ans,tail,ar);
    }
    ans=reverse(ans);
    return ans;
}