#include <bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 ListNode* middleNode(ListNode* head)
{
    if(head==NULL || head->next==NULL)return head;
    ListNode*fast=head->next;
    ListNode*slow=head;
    while(fast)
    {
        fast=fast->next;
        slow=slow->next;
        if(fast)
        {
            fast=fast->next;
        }
    }
    return slow;
}

  