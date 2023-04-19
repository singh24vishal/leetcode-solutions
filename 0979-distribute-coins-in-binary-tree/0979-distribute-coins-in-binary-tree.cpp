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
    int fun(TreeNode* root,int &ans)
    {
        if(root==NULL) return 0;
        int x=fun(root->left,ans);
        int y=fun(root->right,ans);
        ans+=abs(x)+abs(y);
        return (x+y+root->val-1);
    }
    int distributeCoins(TreeNode* root) {
        int ans=0;
        fun(root,ans);
        return ans;
    }
};