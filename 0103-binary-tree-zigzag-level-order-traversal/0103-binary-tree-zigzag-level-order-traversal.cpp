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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == nullptr) return res;
        queue<TreeNode*>q;
        q.push(root);
        bool f = false;
        while(!q.empty())
        {
            int si = q.size();
            vector<int>t;
            for(int i=0;i<si;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                t.push_back(node->val);
            }
            if(f)
            {
                reverse(t.begin(),t.end());
            }
            f = !f;
            res.push_back(t);
        }
        return res;
    }
};