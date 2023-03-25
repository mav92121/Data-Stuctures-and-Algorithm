#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*next;
    int data;
};
class ListNode{
    public:
    ListNode*next;
    int val;
    ListNode(int data)
    {
        this->val=data;
    }
};

Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node*start1=head1;
    Node*start2=head2;
    if(head1->data>head2->data)
    {
        start1=head2;
        start2=head1;
    }
    // start1 is the pointer to small valued node 
    Node*curr1=start1;
    Node*curr2=start2;
    Node*next1;
    Node*next2;

    if(curr1->next==NULL)
    {
        curr1->next=curr2;
        return start1;
    }

    while(curr1->next && curr2)
    {
        next1=curr1->next;
        next2=curr2->next;
        if(curr2->data>=curr1->data && curr2->data<=next1->data)
        {
            curr1->next=curr2;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }
        else
        {
            curr1=next1;
        }
    }
    if(curr2!=NULL)
        curr1->next=curr2;
    
    return start1;
    
}  

// approach 2

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    ListNode*temp=new ListNode(-1);
    ListNode*ans=temp;
    while(list1 && list2)
    {
        if(list1->val<list2->val)
        {
            temp->next=list1;
            temp=list1;
            list1=list1->next;
        }
        else
        {
            temp->next=list2;
            temp=list2;  
            list2=list2->next;
        }
    }
    if(list1)
    {
        temp->next=list1;
        temp=list1;
        list1=list1->next;
    }
    if(list2)
    {
        temp->next=list2;
        temp=list2;
        list2=list2->next;
    }
    return ans->next;
}