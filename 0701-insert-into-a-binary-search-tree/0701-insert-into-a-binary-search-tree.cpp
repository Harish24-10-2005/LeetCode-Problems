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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* t = root ;
        TreeNode* n = new TreeNode(val);
        if(!root) return n;
        while(true)
        {
            if(t->val > val)
            {
                if(t->left == nullptr)
                {
                    t->left = n;
                    break;
                }
                else t = t->left;
            }
            else
            {
                if(t->right == nullptr)
                {
                    t->right = n;
                    break;
                }
                else t = t->right;
            }
        }
        return root;
    }
};