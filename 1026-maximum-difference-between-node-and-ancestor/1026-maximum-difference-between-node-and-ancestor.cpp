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
    int rec(TreeNode* root,int minn,int maxx){
        if(!root) return abs(maxx - minn);
        int lft = rec(root->left,min(minn,root->val),max(maxx,root->val));
        int ryt = rec(root->right,min(minn,root->val),max(maxx,root->val));
        return max(lft,ryt);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return rec(root,root->val,root->val);
    }
};