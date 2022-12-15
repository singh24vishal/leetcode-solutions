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
    int fun(TreeNode*root, int &c)
    {
        if(root==NULL) return 0;
        int a=fun(root->left,c);
        int b=fun(root->right,c);
        c=max(c,a+b);
        return 1+max(a,b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int c=0;
        fun(root,c);
        return c;
    }
};