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
    unordered_map<TreeNode*,TreeNode*>par;
    unordered_set<TreeNode*>vis;
private:
    void findPar(TreeNode* root,TreeNode*& st,int start)
    {
        if(root->val == start) st = root;
        if(root->left)
        {
            par[root->left] = root;
            findPar(root->left,st,start);
        }
        if(root->right)
        {
            par[root->right] = root;
            findPar(root->right,st,start);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;
        if(!root) return ans;
        TreeNode* st;
        findPar(root,st,start);
        queue<TreeNode*>q;
        q.push(st);
        vis.insert(st);
        while(!q.empty())
        {
            int si = q.size();
            for(int i=0;i<si;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && vis.find(node->left) == vis.end())
                {
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right && vis.find(node->right) == vis.end())
                {
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if(par.count(node) && vis.find(par[node]) == vis.end())
                {
                    q.push(par[node]);
                    vis.insert(par[node]);
                }
            }
            ans++;
        }
        return ans-1;
    }
};