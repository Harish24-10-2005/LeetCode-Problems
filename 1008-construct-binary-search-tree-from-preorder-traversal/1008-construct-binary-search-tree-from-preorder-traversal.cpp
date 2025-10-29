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
    TreeNode* b(vector<int>&nums,int& i,int maxx)
    {
        if(i == nums.size() || nums[i] > maxx) return NULL;
        TreeNode* root = new TreeNode(nums[i++]);
        root->left = b(nums,i,root->val);
        root->right = b(nums,i,maxx);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i =0;
        return b(preorder,i,INT_MAX);
    }
};