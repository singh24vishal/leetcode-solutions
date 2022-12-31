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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        ListNode *h3,*prev;
        h3=new ListNode();
        prev=h3;
        while(h1 and h2)
        {
            if(h1->val<=h2->val)
            {
                ListNode* cur=new ListNode();
                cur->val=h1->val;
                prev->next=cur;
                prev=cur;
                h1=h1->next;
            }
            else
            {
                ListNode* cur=new ListNode();
                cur->val=h2->val;
                prev->next=cur;
                prev=cur;
                h2=h2->next;
            }
        }
        while(h1)
        {
            ListNode* cur=new ListNode();
            cur->val=h1->val;
            prev->next=cur;
            prev=cur;
            h1=h1->next;
        }
        while(h2)
        {
            ListNode* cur=new ListNode();
            cur->val=h2->val;
            prev->next=cur;
            prev=cur;
            h2=h2->next;
        } 
        return h3->next;
    }
};