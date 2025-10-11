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
    int rec(TreeNode*root,int maxx)
    {
        if(!root) return 0;
        maxx = max(maxx,root->val);
        int ans = 0;
        if(root->val >= maxx)
        {
            ans++;
        }
        if(root->left)
        {
            ans += rec(root->left,maxx);
        }
        if(root->right)
        {
            ans += rec(root->right,maxx);
        }
        return ans;
    }    
public:
    int goodNodes(TreeNode* root) {
        return 1 + rec(root->left,root->val) + rec(root->right,root->val);
    }
};