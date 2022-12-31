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
    ListNode* mergeKLists(vector<ListNode*>& v) {
        int n=v.size();
        ListNode *h3,*prev;
        h3=new ListNode();
        prev=h3;
        while(1)
        {
            int mn=INT_MAX,in=-1;
            for(int i=0;i<n;i++)
            {
                if(v[i]!=NULL and v[i]->val<mn)
                {
                    mn=v[i]->val;
                    in=i;
                }
            }
            if(in==-1) break;
            ListNode* cur=new ListNode();
            cur->val=mn;
            prev->next=cur;
            prev=cur;
            v[in]=v[in]->next;
        }
        return h3->next;
    }
};