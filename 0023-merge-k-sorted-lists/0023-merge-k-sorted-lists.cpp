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
        vector<pair<int,ListNode*>> arr;
        for(int i=0;i<n;i++)
        {
            while(v[i])
            {
                arr.push_back({v[i]->val,v[i]});
                v[i]=v[i]->next;
            }
        }
        sort(arr.begin(),arr.end());
        for(auto e:arr)
        {
            ListNode* cur=new ListNode(e.first);
            prev->next=cur;
            prev=cur;
        }
        return h3->next;
    }
};