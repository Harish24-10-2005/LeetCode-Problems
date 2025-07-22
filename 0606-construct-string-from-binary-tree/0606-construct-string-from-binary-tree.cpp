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
string s = "";
void bs(TreeNode* root)
{
    if(root == nullptr) 
    {
        // if(s[s.size()-1] == '(')s.pop_back();
        // s+="()";
        return ;
    }
    s+=to_string(root->val);
    if(root->left || root->right)
    {
        s+="(";
        bs(root->left);
        s+=")";
    }
    if(root->right)
    {
        s+="(";
        bs(root->right);
        s+=")";
    }
}
public:
    string tree2str(TreeNode* root) {
        bs(root);
        return s;
    }
};