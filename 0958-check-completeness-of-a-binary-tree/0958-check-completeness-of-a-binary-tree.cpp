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
    int maxidx = 0;
    int n;
    bool dfs(int idx,TreeNode* root){
        if(!root) return true;
        if(idx >= n) return false;
        return dfs(2*idx + 1,root->left) && dfs(2*idx + 2,root->right);
    }
    int count(TreeNode* root){
        if(!root) return 0;
        int lft = count(root->left);
        int ryt = count(root->right);
        return lft + ryt + 1;
    }
public:
    bool isCompleteTree(TreeNode* root) {
        n = count(root);
        return dfs(0,root);
    }
};