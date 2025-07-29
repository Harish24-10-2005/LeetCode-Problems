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
    int maxLevelSum(TreeNode* root) {
        pair<int,int>ans;
        ans = {0,INT_MIN};
        if(!root) return 0;
        queue<TreeNode*>q;
        int level = 0;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            int summ = 0;
            for(int i=0;i<n;i++)
            {
                auto node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                summ+=node->val;
            }
            level++;
            if(ans.second<summ)
            {
                ans.first = level;
                ans.second = summ;
            }
        }
        return ans.first;
    }
};