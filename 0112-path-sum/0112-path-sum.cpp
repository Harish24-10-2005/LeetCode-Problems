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
        if(root->right || root->left) return false;
        return true;
    } 
    bool dfs(TreeNode* root,int targetSum)
    {
        if(!root) return false;
        if(isleaf(root))
        {
            return targetSum - root->val == 0;
        }
        bool left = false;
        bool ryt = false;
        cout<<targetSum<<" "<<root->val<<endl;
        left = dfs(root->left,targetSum-root->val);
        ryt = dfs(root->right,targetSum-root->val);
        return left || ryt;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return dfs(root,targetSum);
    }
};