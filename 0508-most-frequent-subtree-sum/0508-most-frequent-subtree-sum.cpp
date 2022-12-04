/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int fun(TreeNode* root,map<int,int>&mp)
    {
        if(root->left==NULL and root->right==NULL)
        {
            mp[root->val]++;
            return root->val;
        }
        int sum1=0,sum2=0,sum3=root->val;
        if(root->left!=NULL) sum1=fun(root->left,mp);
        if(root->right!=NULL) sum2=fun(root->right,mp);
        int tot=sum1+sum2+sum3;
        mp[tot]++;
        return tot;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> mp;
        fun(root,mp);
        vector<int> ans;
        int mx=-1;
        for(auto e:mp) mx=max(mx,e.second);
        for(auto e:mp)
        {
            if(e.second==mx) ans.push_back(e.first);
        }
        return ans;
    }
};