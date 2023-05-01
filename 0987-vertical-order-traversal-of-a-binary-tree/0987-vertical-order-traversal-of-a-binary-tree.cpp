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
    void fun(TreeNode* root,int c,map<int,vector<pair<int,int>>>&mp,int l)
    {
        if(root==NULL) return;
        mp[c].push_back({l,root->val});
        fun(root->left,c-1,mp,l+1);
        fun(root->right,c+1,mp,l+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;
        int c=0,l=0;
        fun(root,c,mp,l);
        vector<vector<int>> ans;
        for(auto e:mp)
        {
            vector<pair<int,int>> temp=e.second;
            sort(temp.begin(),temp.end());
            vector<int> temp2;
            for(auto i:temp) temp2.push_back(i.second);
            ans.push_back(temp2);
        }
        return ans;
    }
};