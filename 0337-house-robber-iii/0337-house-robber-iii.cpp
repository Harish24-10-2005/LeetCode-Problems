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
private:
    int dfs(TreeNode* root,unordered_map<TreeNode*,int>&dp)
    {
        if(!root) return 0;
        if(dp.count(root) != 0) return dp[root];
        int cur = root->val;
        if(root->left)
        {
            cur += dfs(root->left->left,dp)+ dfs(root->left->right,dp);
        }
        if(root->right)
        {
            cur += dfs(root->right->left,dp)+ dfs(root->right->right,dp);
        }
        int below =  dfs(root->left,dp) + dfs(root->right,dp);

        return dp[root] = max(cur,below);
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>dp;
        return dfs(root,dp);
    }
};