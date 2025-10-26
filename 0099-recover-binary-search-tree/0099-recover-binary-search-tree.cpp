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
    TreeNode* f =nullptr;
    TreeNode* s =nullptr;
    TreeNode* p = nullptr;
    void swp(TreeNode*root)
    {
        if(!root) return;
        swp(root->left);
        if(p && p->val>root->val)
        {
            if(!f) f = p;
            s = root;
        }
        p = root;
        swp(root->right);
    }
    void recoverTree(TreeNode* root) {
        swp(root);
        if(f && s) swap(f->val,s->val);
    }
};