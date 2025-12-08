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
    int maxx = INT_MIN;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int lft = 0;
        int ryt = 0;
        if(root->left) lft = max(0,dfs(root->left));
        if(root->right) ryt = max(0,dfs(root->right));
        maxx = max(maxx,lft + ryt + root->val);
        return max(lft, ryt) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxx;
    }
};