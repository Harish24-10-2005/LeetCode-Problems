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
 #define LL long long
class Solution {
private:
    bool check(TreeNode* root, LL minn,LL maxx)
    {
        if(!root) return true;
        LL val = root->val;
        if(!(val > minn && val < maxx))  return false;
        return check(root->left,minn,val) &&
               check(root->right,val,maxx);
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};

