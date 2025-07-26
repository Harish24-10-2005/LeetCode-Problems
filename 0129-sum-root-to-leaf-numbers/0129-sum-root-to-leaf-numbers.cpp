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
    bool isleaf(TreeNode* root)
    {
        if(root->right == nullptr && root->left == nullptr)
        {
            return true;
        }
        return false;
    }
    int dfs(int digit , TreeNode* root)
    {
        if(!root) return 0;
        digit*=10;
        digit+=root->val;
        cout<<digit<<endl;
        if(isleaf(root))
        {
            return digit;
        }
        int l = 0;
        int r = 0;
        if(root->left)
        {
            l = dfs(digit,root->left);
        }
        if(root->right)
        {
            r = dfs(digit,root->right);
        }
        return l+r;
    }
public:
    int sumNumbers(TreeNode* root) {
        return dfs(0,root);
    }
};