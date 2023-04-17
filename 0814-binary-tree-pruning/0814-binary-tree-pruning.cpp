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
    TreeNode* fun(TreeNode* root)
    {
        if(!root) return root;
        root->left=fun(root->left);
        root->right=fun(root->right);
        if(root->val==0 and !root->left and !root->right) return NULL;
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return fun(root);
    }
};