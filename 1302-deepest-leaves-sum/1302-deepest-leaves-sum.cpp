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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty())
        {
            int sz=q.size();
            int temp=0;
            while(sz--)
            {
                TreeNode* rt=q.front();
                q.pop();
                temp+=rt->val;
                if(rt->left) q.push(rt->left);
                if(rt->right) q.push(rt->right);
            }
            sum=temp;
        }
        return sum;
    }
};