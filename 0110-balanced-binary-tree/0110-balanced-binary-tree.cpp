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
    int minn = 0;
private:
    int rec(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int lft = 0;
        int ryt = 0;
        if(root->left) lft = rec(root->left);
        if(root->right) ryt = rec(root->right);
        minn = max(minn,abs(lft - ryt));
        return 1+max(lft,ryt);
    }
public:
    bool isBalanced(TreeNode* root) {
        rec(root);
        if(minn < 2) return true;
        return false;
    }
};