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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL)
            {
                if(temp.size()) ans.push_back(temp);
                temp.clear();
                if(q.size()) q.push(NULL);
                continue;
            }
            temp.push_back(curr->val);
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL) 
            q.push(curr->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};