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
        ListNode *prev=NULL,*cur=NULL,*next=NULL;
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
    ListNode* removeNodes(ListNode* head) {
        head=fun(head);
        ListNode *prev,*cur,*next;
        prev=head;
        cur=head->next;
        while(cur!=NULL)
        {
            next=cur->next;
            if(cur->val>=prev->val)
            {
                cur->next=prev;
                prev=cur;
            }
            cur=next;
        }
        head->next=NULL;
        return prev;
    }
};