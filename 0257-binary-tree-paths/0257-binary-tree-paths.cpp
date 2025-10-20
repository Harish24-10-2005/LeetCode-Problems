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
    vector<string>res;
private:
    void rec(TreeNode* root,string& temp)
    {
        if(!root->right && !root->left)
        {
            res.push_back(temp);
            return;
        } 
        if(root->left)
        {
            string l = temp + "->" + to_string(root->left->val);
            rec(root->left,l);
        }
        if(root->right)
        {
            string r = temp + "->" + to_string(root->right->val);
            rec(root->right,r);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return res;
        string temp = to_string(root->val);
        rec(root,temp);
        return res;
    }
};