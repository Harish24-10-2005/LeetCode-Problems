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
    bool dfs(TreeNode* root,long long maxx,long long minn)
    {
        if(!root) return true;
        if(root->val <= minn || root->val >= maxx) return false;

        return dfs(root->left,root->val,minn) && dfs(root->right,maxx,root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root,LLONG_MAX,LLONG_MIN);
    }
};