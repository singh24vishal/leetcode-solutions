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
    TreeNode* fun(TreeNode* root1,TreeNode* root2)
    {
        if(!root1) return root2;
        else if(!root2) return root1;
        TreeNode* nt=new TreeNode(root1->val+root2->val);
        nt->left=fun(root1->left,root2->left);
        nt->right=fun(root1->right,root2->right);
        return nt;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return fun(root1,root2);
    }
};