/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* fun(ListNode *head)
    {
        ListNode *cur=NULL,*prev=NULL,*next=NULL;
        cur=head;
        while(cur!=NULL)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *p1=NULL,*p2=NULL,*p3=NULL,*p4=NULL;
        int n=1;
        p2=head;
        while(n!=left)
        {
            n++;
            p1=p2;
            p2=p2->next;
        }
        p3=p2;
        while(n!=right)
        {
            n++;
            p3=p3->next;
        }
        p4=p3->next;
        p3->next=NULL;
        p2=fun(p2);
        p3=p2;
        if(p1!=NULL) p1->next=p2;
        while(p2->next!=NULL) p2=p2->next;
        p2->next=p4;
        if(left!=1)
        return head;
        else if(p1!=NULL) return p1;
        else return p3;
    }
};