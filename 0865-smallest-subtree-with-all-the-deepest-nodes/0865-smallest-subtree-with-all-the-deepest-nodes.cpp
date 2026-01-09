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
    TreeNode* LCA(TreeNode* root,TreeNode* a, TreeNode* b){
        if(!root || root == a || root == b) return root;
        TreeNode* lft = LCA(root->left,a,b);
        TreeNode* ryt = LCA(root->right,a,b);

        if(!ryt) return lft;
        if(!lft) return ryt;

        return root;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return root;
        vector<TreeNode*>deep;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*>temp;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(i == 0 || i == n-1){
                    temp.push_back(node);
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            deep = temp;
        }
        if(deep.size() == 1) return deep[0];
        return LCA(root,deep[0],deep[1]);
    }
};