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
    int fun(TreeNode* root,map<TreeNode*,int> &mp)
    {
        if(mp.find(root)!=mp.end()) return mp[root];
        if(root==NULL) return 0;
        int x=fun(root->left,mp)+fun(root->right,mp);
        int y=root->val;
        if(root->left) y+=fun(root->left->left,mp)+fun(root->left->right,mp);
        if(root->right) y+=fun(root->right->left,mp)+fun(root->right->right,mp);
        return mp[root]=max(x,y);
    }
    int rob(TreeNode* root) {
        map<TreeNode*,int> mp;
        return fun(root,mp);
    }
};