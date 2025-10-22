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
    vector<vector<int>>res;
    vector<int>temp;
private:
    bool isleaf(TreeNode* root)
    {
        if(root->right || root->left) return false;
        return true;
    }
    void dfs(TreeNode* root,int t)
    {
        if(!root) return;
        if(isleaf(root))
        {
            if(t - root->val == 0)
            {
                temp.push_back(root->val);
                res.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        temp.push_back(root->val);
        dfs(root->left,t-root->val);
        dfs(root->right,t-root->val);
        cout<<temp.back()<<endl;
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return res;
        dfs(root,targetSum);
        return res;
    }
};