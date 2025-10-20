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
    int s(TreeNode* root)
    {
        if(!root) return 0;
        int l = max(0,s(root->left));
        int r = max(0,s(root->right));

        maxx = max(maxx,l + r + root->val);

        return max(l,r) + root->val;
    }
    int maxx = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        s(root);
        return maxx;
    }
};