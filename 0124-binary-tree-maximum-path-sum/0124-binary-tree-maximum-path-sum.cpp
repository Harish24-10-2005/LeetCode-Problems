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
    int maxx = INT_MIN;
private:
    int s(TreeNode* root)
    {
        if(!root) return 0;
        int l = 0;
        int r = 0;
        if(root->left)
        {
            l = max(0,s(root->left));
        }
        if(root->right)
        {
            r = max(0,s(root->right));
        }
        maxx = max(maxx,root->val + l + r);
        return root->val + max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        s(root);
        return maxx;
    }
};