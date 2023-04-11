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
    int fun(TreeNode* root,int sum)
    {
        if(root==NULL) return sum;
        int cur=fun(root->right,sum);
        root->val+=cur;
        return fun(root->left,root->val);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        fun(root,sum);
        return root;
    }
};